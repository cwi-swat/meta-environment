
#include <stdio.h>
#include <limits.h>
#include <tool.h>
#include "in-output.tif.c"

#define PATH_LEN _POSIX_PATH_MAX
#define MAX_PATHS 256

arena *ar;

int nr_paths = 0;
char paths[MAX_PATHS][PATH_LEN];

FATAL_ERROR

aterm *open_file(int cid, char *type, char *name)
{
  int i;
  char full[PATH_LEN];
  FILE *f;
  aterm *t;

  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 8 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".asfix");
    fprintf(stderr, "trying file %s\n", full);
    f = fopen(full, "r");
    if(f) {
      if(TreadTermFile(f, ar, &t) < 0)
        fprintf(stderr, "error reading file %s\n", full);
      else {
        fprintf(stderr, "ok!\n");
        return Tmake(ar, "snd-value(opened-file(<str>,<term>))", name, t);
      }
    }
  }
  return Tmake(ar, "snd-value(error-opening(<str>))", name);
}

void rec_terminate(int cid, aterm *arg)
{
  exit(1);
}

int main(int argc, char **argv)
{
  int cid, i=0;

  FILE *f = fopen(".msm-paths", "r");
  if(f) {
    while(fgets(paths[nr_paths], PATH_LEN, f))
      if(strlen(paths[nr_paths]) > 0 && paths[nr_paths][0] != '#') {
        /* Remove trailing cr */
        paths[nr_paths][strlen(paths[nr_paths])-1] = '\0';
        nr_paths++;
      }
  } else {
    fprintf(stderr, "warning: cannot open .msm-paths file");
  }
  for(i=0; i<nr_paths; i++)
    fprintf(stderr, "path %d = %s\n", i, paths[i]);

  TBinit(argc, argv);
  cid = TBnewConnection(NULL, NULL, NULL, -1, 
			 in_output_handler, in_output_check_in_sign);
  ar = TBgetArena(cid);
  TBconnect(cid);
  TBeventloop();

  return 0;
}
