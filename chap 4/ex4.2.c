
#include<stdio.h>
#include<ctype.h>
#define MAXLINE 1000
main()
{
    double sum, atof(char s[]);


    printf("%f\n",atof("123.45e6"));

}

double atof(char s[])
{
    double val, power, factor;
    int i, sign, exp;

    for(i=0; s[i] == ' '; i++)   // skip whitespace
        ;
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for(val=0.0; isdigit(s[i]); i++)
        val = 10*val + (s[i]-'0');
    if (s[i]=='.')
        i++;
    for(power=1.0; isdigit(s[i]); i++) {
        val = 10 * val + (s[i] - '0');
        power /=10;
    }
    if(s[i]=='e' || s[i]=='E')
        i++;
    factor = (s[i] == '-') ? 0.1 : 10;
    if (s[i] == '-')
        i++;
    for(exp=0; isdigit(s[i]); i++)
        exp = exp*10 + (s[i]-'0');
    while(exp)
        power*= factor, exp--;
    return sign * (val * power);


}
