// this code is for old UNIX systems, i have modified it to work on this system

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>           // flags for read and write
#include<sys/types.h>       // typedefs
#include<sys/stat.h>        // structure returned by stat & flags
#include "/home/gaurav/untitled/chap 8/dirent.h"

void fsize(char *);

// print file sizes
main(int argc, char **argv)
{
    if (argc==1)            // default current directory
        fsize(".");
    else
        while(--argc > 0)
            fsize(*++argv);
    return 0;
}

//int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));

// fsize: print size of file name
void fsize(char *name)
{
    struct stat stbuf;

    if ((stat(name, &stbuf)) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if((stbuf.st_mode & S_IFMT) == S_IFDIR)             // if file type is directory
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024 

//dirwalk: apply fcn to all files in dir
void dirwalk(char *dir, void (*fcn)(char *))
{
    char name[MAX_PATH];
    Dirent *dp;
    DIR_ *dfd;

    if((dfd = opendir_(dir)) == NULL) {
         fprintf(stderr, "dirwalk: can't open %s\n", dir);
         return;
    }
    while ((dp = readdir_(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0
         || strcmp(dp->name, "..") == 0)
            continue;       // skip self and parent
        if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        else {
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn) (name);
        }
    }
    closedir_(dfd);
}

int fstat(int fd, struct stat *);

// opendir_: operna directory for readdir_ calls
DIR_ *opendir_(char *dirname)
{
    int fd;
    struct stat stbuf;
    DIR_ *dp;

    if ((fd = open(dirname, O_RDONLY, 0)) == -1 
     || fstat(fd, &stbuf) == -1 
     || (stbuf.st_mode & S_IFMT) != S_IFDIR
     || (dp = (DIR_ *) malloc(sizeof(DIR_))) == NULL){
        //debug
        printf("%u %d %d %d", fd, fstat(fd, &stbuf), (stbuf.st_mode & S_IFMT) != S_IFDIR, dp == NULL);
        return NULL;}
    
    dp->fd = fd;
    return dp;
}

// closedir_: close directory opened by opendir_
void closedir_(DIR_ *dp)
{
    if(dp) {
        close(dp->fd);
        free(dp);
    }
}

#include <sys/dir.h>    // local directory structure
#define DIRSIZE 256

// readir: read directory entries in sequence
Dirent *readdir_(DIR_ *dp)
{
    struct direct dirbuf;     // local directory entry structure
    static Dirent d;         // portable directory entry structure
    
    int k = read(dp->fd, (char *) &dirbuf, 1) ;                         // on new system, read fails to read directory, hence use readdir()
        printf("%d", k);
    // while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
    //     printf("%d %s",dirbuf.d_ino, dirbuf.d_name );
    //     if (dirbuf.d_ino == 0)      // slot not is use
    //         continue;
    //     d.ino = dirbuf.d_ino;
    //     strncpy(d.name, dirbuf.d_name, DIRSIZE);
    //     d.name[DIRSIZE] = '\0';          // null character at ending
    //     return &d;
    // }
    return NULL;
} 

