#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <aterm2.h>
#include <atb-tool.h>

#include "in-output.tif.h"

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

int nr_paths = 0;
char paths[MAX_PATHS][PATH_LEN];

ATerm open_old_asfix_file(int cid, char *name)
{
  int i;
  char full[PATH_LEN];
  FILE *f;
  ATerm t;

  ATfprintf(stderr, "pre-parsed file %s.asfix\n", name);
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 8 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".asfix");
    f = fopen(full, "r");
    if(f) {
      t = ATreadFromTextFile(f);
      if(!t) {
        ATfprintf(stderr, "could not be read\n");
        fclose(f);
      }else {
        ATfprintf(stderr, "was found in: %s\n",paths[i]);
        fclose(f);
        return ATmake("snd-value(opened-file(<str>,<term>,<str>))",
                      name,t,paths[i]);
      }
    } 
  }
  ATfprintf(stderr,"could not be found\n");
  return ATmake("snd-value(error-opening(<str>))", name);
}

ATerm open_sdf2_file(int cid, char *name)
{
  int i;
  char full[PATH_LEN];
  ATerm t;
  char *buf;
  size_t size;
  FILE *f;

    ATfprintf(stderr, "pre-parsed file %s.sdf2.baf\n", name);
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 12 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".sdf2.baf");
    f = fopen(full, "r");
    if(f) {
      t = ATreadFromBinaryFile(f);
      if(!t) {
        ATfprintf(stderr, "could not be read\n");
        fclose(f);
      }else {
        ATfprintf(stderr, "was found in: %s\n",paths[i]);
        fclose(f);
        return ATmake("snd-value(opened-asfix-file(<str>,<term>,<str>))",
                      name,t,paths[i]);
      }
    } 
  }

  /* JS  Try raw format if no pre-parsed version was found */
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 8 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".sdf2");
    fprintf(stderr, "trying file %s\n", full);
    buf = SlurpFile(full, &size);
    if (buf != NULL) {
	t = ATmake("<str>", buf);
 	free(buf);
        ATfprintf(stderr, "was found in: %s\n",paths[i]);
	return ATmake("snd-value(opened-file(<str>,<term>,<str>))",
                      name, t, paths[i]);
    }
  }
  ATfprintf(stderr,"File could not be found\n");
  return ATmake("snd-value(error-opening(<str>))", name);
}

ATerm open_eqs2_file(int cid, char *name)
{
  int i;
  char full[PATH_LEN];
  ATerm t;
  char *buf;
  size_t size;

  
  /* JS  Try raw format if no pre-parsed version was found */
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 8 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".eqs2");
    fprintf(stderr, "trying file %s\n", full);
    buf = SlurpFile(full, &size);
    if (buf != NULL) {
	t = ATmake("<str>", buf);
 	free(buf);
        ATfprintf(stderr, "was found in: %s\n",paths[i]);
	return ATmake("snd-value(opened-file(<str>,<term>,<str>))",
                      name, t, paths[i]);
    }
  }
  ATfprintf(stderr,"File could not be found\n");
  return ATmake("snd-value(error-opening(<str>))", name);
}

ATerm open_trm_file(int cid, char *name)
{
  int i;
  char full[PATH_LEN];
  ATerm t;
  char *buf;
  size_t size;

  
  /* JS  Try raw format if no pre-parsed version was found */
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 8 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    fprintf(stderr, "trying file %s\n", full);
    buf = SlurpFile(full, &size);
    if (buf != NULL) {
	t = ATmake("<str>", buf);
 	free(buf);
        ATfprintf(stderr, "was found in: %s\n",paths[i]);
	return ATmake("snd-value(opened-file(<str>,<term>,<str>))",
                      name, t, paths[i]);
    }
  }
  ATfprintf(stderr,"File could not be found\n");
  return ATmake("snd-value(error-opening(<str>))", name);
}

ATerm open_file(int cid, char *name)
{
  int i;
  char full[PATH_LEN];
  FILE *f;
  ATerm t;
  char *buf;
  size_t size;

  ATfprintf(stderr, "pre-parsed file %s.sdf2.asfix\n", name);
  for(i=0; i<nr_paths; i++) {
    strcpy(full, paths[i]);
    if(strlen(full) + strlen(name) + 12 > PATH_LEN) {
      fprintf(stderr, "warning: path to long, ignored: %s+%s\n", full, name);
      continue;
    }
    strcat(full, "/");
    strcat(full, name);
    strcat(full, ".sdf2.asfix");
    f = fopen(full, "r");
    if(f) {
      t = ATreadFromTextFile(f);
      if(!t) {
        ATfprintf(stderr, "could not be read\n");
        fclose(f);
      }else {
        ATfprintf(stderr, "was found in: %s\n",paths[i]);
        fclose(f);
        return ATmake("snd-value(opened-file(<str>,<str>,<term>,<str>))",
                      "asfix",name,t,full);
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
    strcat(full, ".sdf2");
    fprintf(stderr, "trying file %s\n", full);
    buf = SlurpFile(full, &size);
    if (buf != NULL) {
	t = ATmake("<str>", buf);
 	free(buf);
	fprintf(stderr, "ok!\n");
	return ATmake("snd-value(opened-file(<str>,<str>,<term>,<str>))",
                      "raw",name, t,full);
    }
  }
  ATfprintf(stderr,"File could not be found\n");
  return ATmake("snd-value(error-opening(<str>))", name);
}

ATerm save_sdf2_asfix(int cid, char *name, char *path, ATerm syntax)
{
  char full[PATH_LEN];
  FILE *output;

  strcpy(full, path);
  strcat(full, "/");
  strcat(full, name);
  strcat(full, ".sdf2.baf");
  ATfprintf(stderr, "writing file %s\n", full);
  output = fopen(full,"w");
  if(!output)
    ATfprintf(stderr,"Cannot open file %s\n",full);
  else {
    ATwriteToBinaryFile(syntax,output);
    fclose(output);
  }
  return ATmake("snd-value(save-done(<str>))", name);
}

ATerm save_eqs_asfix(int cid, char *name, char *path, ATerm eqs)
{
  char full[PATH_LEN];
  FILE *output;

  strcpy(full, path);
  strcat(full, "/");
  strcat(full, name);
  strcat(full, ".eqs.baf");
  ATfprintf(stderr, "writing file %s\n", full);
  output = fopen(full,"w");
  if(!output)
    ATfprintf(stderr,"Cannot open file %s\n",full);
  else {
    ATwriteToBinaryFile(eqs,output);
    fclose(output);
  }
  return ATmake("snd-value(save-done(<str>))", name);
}

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

int main(int argc, char **argv)
{
  int cid, i=0;
  ATerm bottomOfStack;

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
    ATfprintf(stderr, "path %d = %s\n", i, paths[i]);

  ATBinit(argc, argv, &bottomOfStack);
  cid = ATBconnect(NULL, NULL, -1, in_output_handler); 
  ATBeventloop();

  return 0;
}
