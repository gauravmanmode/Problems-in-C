#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;


char *alloc(int n) // return pointer to n characters
{
    if (allocbuf+ALLOCSIZE-allocp >= n) {
        allocp += n;
        return allocp - n;          //old p
    } else                          // not enough room
        return 0;
}

void afree(char *p)
{
    if (p>=allocbuf && p < allocbuf+ALLOCSIZE)
        allocp=p;
}
