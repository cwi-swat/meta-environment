#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <ctype.h>

FATAL_ERROR

int print_term_source(FILE *f, aterm *term);

int main(int argc, char *argv[])
{
  aterm *asfix;
  arena local;

  Tinit(argc,argv);
  AFinit(the_world);

  TinitArena(NULL, &local);

  TreadTermFile(stdin,&local,&asfix);
  print_term_source(stdout,asfix);
  return 0;
}

