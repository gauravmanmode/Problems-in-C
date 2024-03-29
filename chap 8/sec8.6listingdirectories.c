// this code is for old UNIX systems, i have modified it to work on this system

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>           // flags for read and write
#include<sys/types.h>       // typedefs
#include<sys/stat.h>        // structure returned by stat & flags
#include<sys/dir.h>
#include</home/gaurav/untitled/chap 8/dirent.h>

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
    DIR *dfd;

    if((dfd = opendir(dir)) == NULL) {
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
    closedir(dfd);
}

int fstat(int fd, struct stat *);

// readir_: read directory structure from readdir() and convert to portable
Dirent *readdir_(DIR *dp)
{
    struct direct *dirbuf;     // local directory entry structure
    static Dirent d;         // portable directory entry structure
    if ( (dirbuf = readdir(dp)) == NULL )
        return NULL;
    strncpy(d.name, dirbuf->d_name, 256);
    return &d;

} 
