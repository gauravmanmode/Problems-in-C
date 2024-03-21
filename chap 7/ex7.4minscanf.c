#include<stdio.h>
#include<ctype.h>
#include<stdarg.h>

// minscanf: minimal scanf with vraiable argument list
void minscanf(char *fmt, ...)
{
    va_list ap;     // points to each unnamed arg in turn
    char *p, *sval;
    int *ival;
    float *fval;
    unsigned *uval;

    va_start(ap, fmt);      // make ap point to 1st unnamed arg
    for(p = fmt; *p; p++){
        if (isspace(*p)){    // skip white spaces
            p++;
            continue;
        }
        if(*p != '%' && *p == getchar()){                  
            continue;            
        }
        switch(*++p){
            case 'd': case 'i':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'e': case 'f': case 'g':
                fval = va_arg(ap, float *);
                scanf("%e", fval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            case 'o':
                ival = va_arg(ap, int *);
                scanf("%o", ival);
                break;
            case 'u':
                uval = va_arg(ap, unsigned *);
                scanf("%u", uval);
                break;
            case 'x':
                ival = va_arg(ap, int *);
                scanf("%x", ival);
                break;
            case 'c':
                sval = va_arg(ap, char *);
                scanf("%c", sval);
                break;
            case '%':
                break;
            default :
                return ;                                // stop
        } 
    }

    va_end(ap);         // clean up after done

}

main()
{
    int n;
    char s[10];
    minscanf("hello %s", s);
    //scanf("hello%d", &n);
    printf("%s", s);

    // char s[2], t;
    // scanf("h%2sx%c", s, &t);
    // //scanf("hello%d", &n);
    // printf("%s%c", s, t);
}