#define NAMEMAX 256         // longest filename component
                            // system dependent

typedef struct {            // portable directory entry
    long ino;               // inode number
    char name[NAMEMAX];    // name + '\0' terminator
} Dirent;

// typedef struct {            // miinimal DIR: no buffering, etc
//     int fd;                 // file descriptor for directory
//     Dirent d;               // the directory entry
// } DIR_;

// DIR_ *opendir_(char *);
Dirent *readdir_(DIR *dfd);
// void closedir_(DIR_ *dfd);
