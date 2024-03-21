#include<stdio.h>
#include<stdlib.h>
#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
int gettoken(char *);

int getop();
void push(double);
double pop(void);
float fval;


// polish calculator
main()
{
    int type;
    double op2;

    while((type = getop()) != EOF){
        switch(type){
            case NUMBER:
                push(fval);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: division by zero");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %c\n", type);
                break;
        }
    }
    return 0;
}

// getop: get next operator or numeric operand
#include<ctype.h>
int getop()
{
    char token[100];
    if(gettoken(token) == '\n')
        return '\n';

    char ch;
    extern float fval;

    if (sscanf(token, "%f", &fval) == 1)                // for number
        return NUMBER;
    else if (sscanf(token, "%c", &ch))                  // for character
        return ch;

}

int gettoken(char *p){
    int c;
    while ((c = getchar()) != ' ' && c!= '\n')          // skip white spaces
        *p++ = c;
    *p ='\0';
    if (c == '\n')                                      // return newline
        return c;
    return 0;
}

// stack
#define MAXVAL 100      // maximum depth of val stack

int sp = 0;      /* next free stack position */
double val[MAXVAL];     // val stack

// push: push f onto value stack
void push(double f)
{
    if (sp<MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cant push %g \n", f);

}
// pop: pop and return top value from stack
double pop(void)
{
    if (sp>0)
        return val[--sp];
    else{
        printf("error: stack empty \n");
        return 0.0;
    }

}