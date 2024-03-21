#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define VARNUM 26
#define VARIABLE '1'
int getop(char []);
void push(double);
double pop(void);
void clearsp(void);
char currvar;
// adding exercises 4.4,4.5,4.6

// polish calculator
main()
{
    int type;
    double op1, op2;
    double r;
    char s[MAXOP];
    double var[VARNUM];


    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case VARIABLE:
                if (currvar=='r')
                    push(r);
                else
                    push(var[currvar-'A']);
                break;
            case '=':
                var[currvar-'A']=pop();
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
            case '%':
                op2 = pop();                                              // add modulus operator
                push((int)pop() % (int)op2);/**/
                break;
            case 't':                                       // print top element
                op2 = pop();
                printf("\t%.8g\n", op2 );
                push(op2);
                break;
            case 'd':                                      // duplicate elements
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 'x':                                      // swap two elements
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
                break;
            case 'c':                                     // clear stack
                clearsp();
                break;
            case 's':                                     // sine
                push(sin(pop()));
                break;
            case 'e':                                    // exp
                push(exp(pop()));
                break;
            case 'p':                                    // pow (a, b)
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                r=pop();
                printf("\t%.8g\n", r);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// getop: get next operator or numeric operand
#include<ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;
    static unsigned char unget = 0;
    printf("%c" ,c = unget ? unget : getch());
    while((s[0] = c = unget ? unget : getch()) == ' ' || c == '\t')
        ;

s[1] = '\0';
    if (isupper(c) || c=='r') {
        currvar = c;
        return VARIABLE;
    }
    if (!isdigit(c) && c!= ' ' && c!= '-')
        return c;
    else if (c=='-' && isdigit(c = unget ? unget : getch()))
        unget=c;
    else if (!isdigit(c)) {
        unget=c;
        return '-';
    }

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = unget ? unget : getch()));   // collect integer part
    if (c == '.')
        while (isdigit(s[++i] = c  = unget ? unget : getch()));  // collect fraction part
    s[i] = '\0';
    if (c!= EOF)
        unget=c;
    return NUMBER;
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


// getch-ungetch
#define BUFSIZE 100

int buf[BUFSIZE];      // buffer for getch
int bufp = 0;           // next free position in buf

int getch(void)         // get a possibly(pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)     // push character back on input
{
    if(bufp>=BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}


// clearsp: sets sp value to zero .
void clearsp(void)
{
    sp = 0;
}
