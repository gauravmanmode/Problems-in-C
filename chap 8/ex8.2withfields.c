
#define NULL 0
#define EOF -1
#define BUFSIZ 1024
#define OPEN_MAX 20            // max files open at once


struct _flags{                        
    unsigned int READ : 1;
    unsigned int WRITE : 1;
    unsigned int UNBUF : 1;
    unsigned int _EOF : 1;
    unsigned int ERR : 1;
} flag;

typedef struct _iobuf     {
    int cnt;            // characters left
    char *ptr;          // next character position
    char *base;         // location of buffer
    struct _flags flag; // mode of file access
    int fd;             // file descriptor
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin       (&_iob[0])
#define stdout      (&_iob[1])
#define stderr      (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)         ((p)->flag._EOF == 1)
#define ferror(p)       ((p)->flag.ERR == 1)
#define fileno(p)       ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 \
                ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)  (--(p)->cnt >= 0 \
                ? *(p)->ptr = (x) : _flushbuf((x), p));

#define _getchar()       getc(stdin)
#define putchar(x)      putc(x, stdout)


#include<fcntl.h>
#include<unistd.h>
#define PERMS 0666              // (in octal) RW for owner, group and others

// fopen:   open file, return file ptr
FILE *fopen(char *name, char *mode)
{

    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++ )
        if (fp->flag.READ == 0 | fp->flag.WRITE == 0)
            break;                  // found free slot
    if (fp >= _iob + OPEN_MAX)              // no free slots
        return NULL;

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a'){
        if ((fd = open(name, O_WRONLY, 0) == -1))
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd == -1)                   // couldn't access name
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    if (*mode =='r')
        fp->flag.READ = 1;
    else
        fp->flag.WRITE = 1;
    return fp;
}

#include<unistd.h>

// fillbuf: allocate and fill input buffer
int _fillbuf(FILE *fp)
{
    int bufsize;

    if (fp->flag.READ == 1 && fp->flag._EOF == 1 && fp->flag.ERR == 1)
        return EOF;
    bufsize = (fp->flag.UNBUF == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL)           // no buffer yet
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;             // cant get buffer
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0){
        if (fp->cnt == -1)
            fp->flag._EOF = 1;
        else
            fp->flag.ERR = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

FILE _iob[OPEN_MAX] = {     // stdin, stdout, stderr
    {0, (char *) 0, (char *) 0, {1}, 0},
    {0, (char *) 0, (char *) 0, {0,1}, 1},
    {0, (char *) 0, (char *) 0, {0,1,1}, 2}
};

main()
{
    int x = _getchar();
    printf("%c", x);
}