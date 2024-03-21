#include<stdio.h>
#include<stdarg.h>

union all_type{
    int ival;
    double dval;
    char *sval;
};

// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...)
{
    va_list ap;     // points to each unnamed arg in turn
    char *p;
    union all_type v;

    va_start(ap, fmt);      // make ap point to 1st unnamed arg
    for(p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            //continue;       
        }
        else{
            switch(*++p){
                case 'd':
                    v.ival = va_arg(ap, int);
                    printf("%d", v.ival);
                    break;
                case 'f':
                    v.dval = va_arg(ap, double);
                    printf("%f", v.dval);
                    break;
                case 's':
                    for (v.sval = va_arg(ap, char *); *v.sval; v.sval++)
                        putchar(*v.sval);
                    break;
                default:
                    putchar(*p);
                    break;
        }
        }   
    }
    va_end(ap);     // clean up when done
}

main()
{
        int k = printf("hello");
        minprintf("%s %d\n", " isit", k);
}

