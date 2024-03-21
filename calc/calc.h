#define NUMBER '0'      // signal that a number was found
#define VARIABLE '1'
int getop(char []);
void push(double);
double pop(void);
void clearsp(void);
int getch(void);
void ungetch(int);