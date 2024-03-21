#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "calc.h"
#define MAXOP 100       // max size of operand or operator
#define VARNUM 26
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

