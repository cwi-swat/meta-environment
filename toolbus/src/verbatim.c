
/* Synopsis: verbatim file

   Print on standard output:
    - \begin{verbatim}
    - the contents of `file' with tabs replaced by spaces. 
    - \end{verbatim}

   Note: this program is equivalent to the /bin/sh script:
      echo '\\begin{verbatim}'
      sed -e "s/	/        /" <$@
      echo '\\end{verbatim}'
   However, the interpretation of \\ is different on various
   systems (i.e., IRIX vs Solaris) therfore we code it in C.

*/

#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, c;

  for(i=1; i<argc; i++) {
    if(strcmp(argv[i], "-h") == 0) {
      fprintf(stderr, "usage: %s < input > output\n", argv[0]);
      exit(0);
    }
  }

  fprintf(stdout, "\\begin{verbatim}\n");
  while((c = fgetc(stdin)) != EOF){
    if(c == '\t')
      fprintf(stdout, "        ");
    else
      fprintf(stdout, "%c", c);
  }
  fprintf(stdout, "\\end{verbatim}\n");
  return 0;
}

