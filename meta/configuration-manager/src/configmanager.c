/*
  $Id$
 */   

#include "configmanager.h"

static char myversion[] = "1.0";     

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}
   
ATerm process_config_file(int cid, char *filename, char *contents)
{
  int i,
      j = 0,
      line_number = 0,
      len = strlen(contents);
  char pathline[len];
  ATermList paths = ATempty;

  for (i = 0; i < len; i++) {
    if (contents[i] == '\n') {
      if (j != 0 && pathline[0] != '#') {
        pathline[j] = '\0';
        while (j > 0 && isspace((int)pathline[j-1])) {
          pathline[--j] = '\0';
        }
        line_number++;
        j = 0;
        paths = ATinsert(paths, ATmake("<str>", pathline));
      }
      else {
        j = 0;
      }
    }
    else {
      pathline[j++] =  contents[i];
    }
  }
  if (j != 0 && pathline[0] != '#') {
    pathline[j] = '\0';
    while (j > 0 && isspace((int)pathline[j-1])) {
      pathline[--j] = '\0';
    }
    line_number++;
    j = 0;
    paths = ATinsert(paths, ATmake("<str>", pathline));
  }

  return ATmake("snd-value(search-paths(<term>))", ATreverse(paths));
}

void usage(char *prg, ATbool is_err)
{
    ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
    ATwarning("use '%s -at-help' to get more options.\n", prg);
    ATwarning("This program can only be used as a ToolBus tool!\n");
    exit(is_err ? 1 : 0);
}

void version(const char *msg)
{
    ATwarning("%s v%s\n", msg, myversion);
    exit(1);
}    

/* Main program */
int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i=1; i<argc; i++) {
      if (strcmp(argv[i], "-h") == 0) {
          usage(argv[0], ATfalse);
      } else if (strcmp(argv[i], "-V") == 0) {
          version(argv[0]);
      }
  }

  ATBinit(argc, argv,&bottomOfStack);

  cid = ATBconnect(NULL, NULL, -1, configmanager_handler);

  ATBeventloop();

  return 0;
}         
