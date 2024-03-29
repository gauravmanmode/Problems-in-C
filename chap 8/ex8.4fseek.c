
#define NULL 0
#define EOF -1
#define BUFSIZ 17
#define OPEN_MAX 1024            // max files open at once

typedef struct _iobuf     {
    int cnt;            // characters left
    char *ptr;          // next character position
    char *base;         // location of buffer
    int flag;           // mode of file access
    int fd;             // file descriptor
} FILE;
extern FILE _iob[OPEN_MAX];

#define stdin       (&_iob[0])
#define stdout      (&_iob[1])
#define stderr      (&_iob[2])

enum _flags {
    _READ   = 01,       // file open for reading
    _WRITE  = 02,       // file open for writing
    _UNBUF  = 04,       // file is unbuffered
    _EOF    = 010,      // EOF has occured on this file
    _ERR    = 020,      // error has occured on this file
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)         (((p)->flag & _EOF) != 0)
#define ferror(p)       (((p)->flag & _ERR) != 0)
#define fileno(p)       ((p)->fd)

#define getc(p)     (--(p)->cnt >= 0 \
                ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)  (--(p)->cnt >= 0 \
                ? *(p)->ptr++ = (x) : _flushbuf((x), p));

#define _getchar()       getc(stdin)
#define _putchar(x)      putc(x, stdout)


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
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
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
    fp->flag = (*mode =='r') ? _READ : _WRITE;
    return fp;
}

#include<unistd.h>

// fillbuf: allocate and fill input buffer
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)           // no buffer yet
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;             // cant get buffer
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0){
        if (fp->cnt == -1)
            fp->flag = _EOF;
        else
            fp->flag = _ERR;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int bufsize;

int _flushbuf(int x, FILE *fp)                
{
    extern int bufsize;

    if ((fp->flag&(_WRITE|_EOF|_ERR)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if(fp->base != NULL)
        write(fp->fd, fp->base, bufsize);

    if (fp->base == NULL)           // no buffer yet
        if ((fp->base = (char *) malloc(BUFSIZ)) == NULL)
            return EOF;             // cant get buffer
    
  
    fp->ptr = fp->base;
    fp->cnt = bufsize;

    *fp->ptr++ = x;
    fp->cnt--;
    return x;


}

int fflush(FILE *fp)            // fflush, fclose return 0 on success and EOF on error
{
    int n = bufsize - fp->cnt;          // number of characters to write
    if (n !=  write(fp->fd, fp->base, n))
        return EOF;
    fp->cnt = bufsize;              
    return 0;
}


int fclose(FILE *fp)            // close returns 0 on success and -1 on error
{
    fflush(fp);
    if (close(fp->fd) == -1)        
        return EOF;
    free(fp->base);
    return 0;
}

FILE _iob[OPEN_MAX] = {     // stdin, stdout, stderr
    {0, (char *) 0, (char *) 0, _READ, 0},
    {0, (char *) 0, (char *) 0, _WRITE, 1},
    {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

int fseek(FILE *fp, long offset, int origin)
{
    if (lseek(fp->fd, offset, origin) == -1)
        return -1;
    //_fillbuf(fp);    
}

main()
{
    FILE *fp1 = fopen("a", "r");
    fseek(fp1, 6, 0);

    int x = getc(fp1);
    _putchar(x);
    fclose(stdout);
    
}
