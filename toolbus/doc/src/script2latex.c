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
/*
 * script2tex -- convert ToolBus scripts to LaTex code
 */

#include <stdio.h>
#include <limits.h>

void usage(void)
{
  fprintf(stderr, "Usage: script2latex [-strip]\n");
  exit(0);
}

char *text_size = "\\normalsize\n";
char *script_size = "\\small\n";

int is_comment(char *line)
{
  return (strlen(line) >= 2) && (line[0] == '%') && (line[1] == '%');
}

char *safer_gets(char *s, int l)
{
  s = fgets(s, l, stdin);
  if(s) {
    int lastpos = strlen(s)-1;

    if(s[lastpos] == '\n')
      s[lastpos] = '\0';
  }
  return s;
}

int main(int argc, char *argv[])
{
  char line[PATH_MAX];
  int strip = 0;
  int first = 1;

  argv++;     /* skip argv[0] */
  while(*argv){
    if(strcmp(*argv, "-strip") == 0){
      argv++;
      strip = 1;
    } else if(strcmp(*argv, "-h") == 0) {
      usage();
    } else
      usage();
  }

  while(safer_gets(line, PATH_MAX)){
    if(is_comment(line)){
      if(!strip){
	if(!first){
	  printf("\\end{verbatim}\n");
	}
	first = 0;
	
	printf("\\noindent\n");
	printf(text_size);
	printf("%s\n", &line[2]);
      }
     
      while(safer_gets(line, PATH_MAX)){
	if(line[0] == '\0')
	  printf("\n");
	else if(is_comment(line)){
	  if(!strip)
	    printf("%s\n", &line[2]);
	} else {
	  if(!strip){
	    printf(script_size);
	    printf("\\begin{verbatim}\n");
	  }
	  goto print_script_line;
	}
      }
      exit(0);
    } else {
    print_script_line:
      if(!strip){
	if(first){
	  printf(script_size);
	  printf("\\begin{verbatim}\n");
	  first = 0;
	}
      }

      printf("%s\n", line);
    }
  }
  if(!strip){
    printf("\\end{verbatim}\n");
    printf(text_size);
  }
  return 0;  
}
