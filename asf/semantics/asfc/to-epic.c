#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <sys/times.h>
#include <limits.h>
#include "to-epic.tif.c"

extern aterm *pattern_asfix_id;
void init_asfix_patterns();
aterm *rnx2asfix(arena *ar, aterm *rnx);
int print_term_source(FILE *f, aterm *term);

FATAL_ERROR

void rec_terminate(int cid, aterm *t)
{
  exit(0);
}

aterm *rnx_to_epic(int cid, aterm *name, aterm *mod)
{
  aterm *asfix, *result;
  arena local;
  int len;
  FILE *output;
  char *text,*fname;
  char *path = "/home/markvdb/NEW-META/new-meta/pico/";
  /*char *path = "/home/markvdb/AsFix2EP/muASF2/asfixfiles/reshuffle/";*/

  TinitArena(t_world(mod), &local);

  assertp(TmatchTerm(name,pattern_asfix_id,&text));
  len = strlen(path) + strlen(text) + strlen(".ep");
  fname = malloc(len + 1);
  if(!fname) {
    fprintf(stderr,"Not enough memory\n");
    exit(1);
  }
  fname = strcpy(fname,path);
  fname = strcat(fname,text);
  fname = strcat(fname,".ep");
  asfix = rnx2asfix(&local,mod);
  Tprintf(stderr,"Writing: %s.ep\n", text);
  output = fopen(fname,"w");
  free(fname);
  if(!output)
    Tprintf(stderr,"Cannot open file\n");
  else {
    print_term_source(output,asfix);
    Tprintf(output, "\n");
    fclose(output);
  }
  result = Tmake(TBgetArena(cid), "snd-value(done)");
  TdestroyArena(&local);
  return result;
}

int main(int argc, char **argv)
{
  int cid;

  TBinit(argc, argv);
  AFinit(NULL);
  cid = TBnewConnection(NULL, NULL, NULL, -1,
                         to_epic_handler, to_epic_check_in_sign);
  TBconnect(cid);
  init_asfix_patterns();
  TBeventloop();

  return 0;
}
