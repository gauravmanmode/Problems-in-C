#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define dprint(c) printf("%c \n", c);

//expr: reverse polish calculator
main(int argc, char *argv[]) {
    char **opn = argv;
    float z;
    char op;
    while (atof((++*opn)))                    // skip digits until first operator
        ;               //   printf("%d", atoi(*argv);
    printf("%s", *opn);
    // float lastnum=atof(*(--argv));

/*
    op=*(argv[0]);
   // dprint(op)
  //  printf("%f", lastnum);
  while(opn!=NULL) {
      switch (*opn++) {                         // get next opn
          case '+':
              z = atof(*--argv) + atof(*--argv);
              break;
          case '*':
              z = z * atof(*--argv);
              break;
      }
      printf("\n %s\n", *opn);
  }


}*/
}