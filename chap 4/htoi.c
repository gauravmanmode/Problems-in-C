#include <stdio.h>
int  htoi(char s[]);
int main() {

    char s[7] = "0x123f";
    printf("two numb %d %d",htoi(s), 0x123f);
    return 0;
}
int htoi(char s[])
{
    int i, n = 0;
    if (s[0] == 0 && (s[1] == 'x' || s[1] == 'X'))
        i+=2;
    while (s[i] != '\0'){
        if (s[i] >= '0' && s[i] <= '9')
            n = 16*n + (s[i] - '0');
        if (s[i] >= 'a' && s[i] <= 'f')
            n = 16*n + (s[i] - 'a' + 10 );
        if (s[i] >= 'A' && s[i] <= 'F')
            n = 16*n + (s[i] - 'A' + 10 );
        ++i;
    }
    return n;
}
