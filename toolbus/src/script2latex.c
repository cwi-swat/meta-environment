/*
 * script2tex -- convert ToolBus scripts to LaTex code
 */

#include <stdio.h>
#include "TB.h"

void usage(void)
{
  fprintf(stderr, "Usage: script2latex [-strip]\n");
  exit(1);
}

char *text_size = "\\normalsize\n";
char *script_size = "\\small\n";

int is_comment(char *line)
{
  return (strlen(line) >= 2) && (line[0] == '%') && (line[1] == '%');
}

void main(int argc, char *argv[])
{
  char line[256];
  int strip = 0;
  int first = 1;

  argv++;     /* skip argv[0] */
  while(*argv){
    if(strcmp(*argv, "-strip") == 0){
      argv++;
      strip = 1;
    } else
      usage();
  }

  while(gets(line)){
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
     
      while(gets(line)){
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
  exit(0);  
}
