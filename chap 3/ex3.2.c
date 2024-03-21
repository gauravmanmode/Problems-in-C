#include<stdio.h>
void escape(char s[], char t[]);
void escape2(char s[], char t[]);
void getlines(char s[]);
main()
{
    char from[19];
    char to[19];
    getlines(from);
    escape2(to, from);
    printf("%s", to);

}
void escape2(char to[], char from[])
{
    int j = 0;
    for (int i = 0; from[i] != '\0'; ++i){
        switch(from[i]){
            case '\\':
                ++i;
                to[j++] = '\\';
            case 't':
                to[j - 1] = '\t';
                break;
            case 'n':
                to[j - 1] = '3';
                break;
            default:
                to[j++] = from[i];
                break;
        }
        to[j] = '\0';

    }

}



void escape(char to[], char from[])
{
    int j = 0;
    for (int i = 0; from[i] != '\0'; ++i){
        switch(from[i]){
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            default:
                to[j++] = from[i];
                break;
        }
        to[j] = '\0';

    }

}







void getlines(char s[])
{
    int i = 0;
    while( (s[i] =  getchar()) != EOF)
        i++;
    s[i] = '\0';
    putchar('\n');
}