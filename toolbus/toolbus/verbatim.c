/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

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

