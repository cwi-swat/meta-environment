#include <stdio.h>
#include <limits.h>
#include <tb-tool.h>
#include "in-output.tif.c"

#define PATH_LEN _POSIX_PATH_MAX
#define MAX_PATHS 256

/* This is a hack, due to JS */
#include <sys/stat.h>
size_t  FileSize(char *fnam)
{
        struct stat     statbuf;

        if(stat(fnam, &statbuf) < 0) {
                fprintf(stderr, "could not stat() %s\n", fnam);
                return(-1);
        }
        return(statbuf.st_size);
}
/* This too :-) */
/*
 * JS
 * Initially, this was designed to read arbitraty buffers
 * So it returned an allocated, filled buffer as well
 * as a size_t indication of its length
 * The fragment below assumes is modified to read an
 * arbitraty file with no NULL characters in it into
 * a buffer, which is then NULL-terminated
 * The resulting output is a properly terminated C string
 */

char *SlurpFile(char *fnam, size_t *size)
{
        char *buf;
        FILE *fd;

        *size = FileSize(fnam);
        if((fd = fopen(fnam, "r")) == NULL) {
                fprintf(stderr, "could not fopen() %s\n", fnam);
                *size = 0;
                return(NULL);
        }
        if((buf = (char *)malloc(*size + 1)) == NULL ) {
                fprintf(stderr, "could not allocate %i bytes for %s\n", *size + 1, fnam);
                fclose(fd);
                *size = 0;
                return(buf);
        }
        if(fread(buf, 1, *size, fd) != *size) {
                fprintf(stderr, "could not fread() %i bytes %s\n", *size, fnam);
                free(buf);
                *size = 0;
                buf = NULL;
        }
        fclose(fd);
	buf[*size] = '\0';	/* Terminate the string :-( */
/*	fprintf(stderr, "file: %s, Size: %i\n", fnam, *size);	*/
        return(buf);
}

arena *ar;

int nr_paths = 0;
char paths[MAX_PATHS][PATH_LEN];

FATAL_ERROR

aterm *open_file(int cid, char *name)
{
  int i;
  char full[PATH_LEN];
  FILE *f;
  aterm *t;
  char *buf;
  size_t size;

  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 8 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".asfix");
    fprintf(stderr, "trying pre-parsed file %s\n", full);
    f = fopen(full, "r");
    if(f) {
      if(TreadTermFile(f, ar, &t) < 0) {
        fprintf(stderr, "error reading pre-parsed file %s\n", full);
        fclose(f);
      }else {
        fprintf(stderr, "ok!\n");
        fclose(f);
        return Tmake(ar, "snd-value(opened-file(<str>,<str>,<term>,<str>))", "asfix",name, t,full);
      }
    }
  }
  /* JS  Try raw format if no pre-parsed version was found */
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    fprintf(stderr, "trying file %s\n", full);
    buf = SlurpFile(full, &size);
    if (buf != NULL) {
	t = Tmake(ar,"<str>", buf);
 	free(buf);
	fprintf(stderr, "ok!\n");
	return Tmake(ar, "snd-value(opened-file(<str>,<str>,<term>,<str>))", "raw",name, t,full);
    }
  }
  fprintf(stderr,"We kunnen de file helaas niet vinden\n");
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
