
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

int main(void)
{
  int c;

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

