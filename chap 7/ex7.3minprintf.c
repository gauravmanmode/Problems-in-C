#include<stdio.h>
#include<stdarg.h>


// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...)
{
    va_list ap;     // points to each unnamed arg in turn
    char *p, *sval;
    unsigned uval;
    int ival, c;
    int prec = 0;
    double dval;

    va_start(ap, fmt);      // make ap point to 1st unnamed arg
    for(p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;    
        }
        if(*++p == '.'){
            for(++p; isdigit(*p); p++)
                prec = 10* prec + *p -'0';
        } --p;

        switch(*++p){
            case 'd': case 'i':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'x': case 'X':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break;
            case 'c':
                c = va_arg(ap, int);
                printf("%c", c);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%.*f", dval, prec);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval && prec--; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }   
    }
    va_end(ap);     // clean up when done
}

main()
{

        minprintf("%.3f", 554.2334);
        char *s = "%*s";
        printf(s, 10, " isit");
        //minprintf("%f %f %c\n", 32.34, 34, 'k');
}

