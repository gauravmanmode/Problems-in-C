#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);



main(int argc, char *argv[]){


   int n, nlines;

   n=10;
   if(argc==2 && *argv[1]=='-' ){
      if((n=atoi(argv[1]+1)))
         ;
      else
      printf("Usage: tail \n");
   }

   if((nlines=readlines(lineptr, MAXLINES)) >= 0){
      if(n>nlines){
         while(nlines-->0){
         int i=
         printf("%s \n", lineptr[i]);
         i++;
         }
      }
      else{
         while(n-->0)
         printf("%s \n", lineptr[nlines-1-n]);
      }
   
   }


}


int getline1(char *, int);
char *alloc(int);




int readlines(char *lineptr[], int maxlines)
{
   int len, nlines;
   char *p, line[MAXLEN];

   nlines=0;
   while((len=getline1(line, MAXLEN)) > 0){
      
      if(nlines>=maxlines || (p=alloc(len)) == NULL)
         return -1;
      else{
         line[len-1] = '\0';        // delete newline
         strcpy(p, line);
         lineptr[nlines++]=p;
      }
   }
      return nlines;
}

int getline1(char *s, int lim)
{
   int c;
   char *t = s;
   while(--lim>0 && (c=getchar()) != EOF && c!= '\n')
      *s++=c;
   if(c=='\n')
      *s++='\n';
   *s='\0';
   return s - t;
}

#define ALLOCSIZE 10000          // size of available space

static char allocbuf[ALLOCSIZE];       // storage for alloc
static char *allocp = allocbuf;         // next free position

char *alloc(int n)         // return pointer to n charcters
{
   if(allocbuf+ALLOCSIZE-allocp >= n){  // it fits
      allocp += n;
      return allocp - n;
   }
   else     // not enough space
      return 0;

}






