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

int fileexists(const char *fname)
{
  struct stat st;
  return stat(fname,&st)!=EOF;
}

time_t filetime(const char *fname)
{
  struct stat st;
  return stat(fname,&st)!=EOF ? st.st_mtime : -1L;
}

size_t filesize(const char *s)
{
  struct stat st;
  return (stat((char*)s,&st)!=EOF) ? st.st_size : -1L;
}

int fileisregular(const char *s)
{
  struct stat st;
  return (stat((char*)s,&st)!=EOF) ? S_ISREG(st.st_mode) : 0;
}

int fileisreadable(const char *s)
{
  FILE *fd;
  return fileisregular(s) && (fd = fopen(s, "r")) && fclose(fd);
}

int newerfile(const char *s1, const char *s2)
{
  return filetime(s1) > filetime(s2);
}

/*
 * JS: Initially, this was designed to read arbitraty buffers.
 * So it returned an allocated, filled buffer as well as a size_t
 * indication of its length.
 * The fragment below assumes is modified to read an arbitraty
 * file with no NULL characters in it into a buffer, which is then
 * NULL-terminated.
 * The resulting output is a properly terminated C string.
 */

char *slurpfile(char *fnam, size_t *size)
{
        char *buf;
        FILE *fd;

        *size = filesize(fnam);
        if((fd = fopen(fnam, "r")) == NULL) {
                fprintf(stderr, "could not open %s\n", fnam);
                *size = 0;
                return NULL;
        }
        if((buf = (char *)malloc(*size + 1)) == NULL ) {
                fprintf(stderr, "could not allocate %i bytes for %s\n", *size + 1, fnam);
                fclose(fd);
                *size = 0;
                return NULL;
        }
        if(fread(buf, 1, *size, fd) != *size) {
                fprintf(stderr, "could not fread() %i bytes %s\n", *size, fnam);
                free(buf);
                *size = 0;
                buf = NULL;
        }
        fclose(fd);
	buf[*size] = '\0';	/* Terminate the string :-( */
        return buf ;
}

ATbool path_length_exceeded(int l, char *p, char *f)
{
  if(l <= PATH_LEN)
    return ATfalse;

  ATfprintf(stderr, "warning: path too long, ignored: %s/%s\n", p, f);
  return ATtrue;
}

int  nr_paths = 0;
char paths[MAX_PATHS][PATH_LEN];
int  asfix_status = 0;

char *find_newest_in_path(char *name)
{
  int    i;
  char   thisname[PATH_LEN], *newestname = NULL;
  time_t newesttime = 0L, thistime;

  for(i=0; i<nr_paths; i++) {
    if(path_length_exceeded(strlen(paths[i])+strlen(name)+1, paths[i], name))
      continue;
    sprintf(thisname, "%s/%s", paths[i], name);
    if((thistime = filetime(thisname)) > newesttime) {
      newesttime = thistime;
      newestname = thisname;
    }
  }
  return newestname;
}

ATerm open_error(char *n)
{
  return ATmake("snd-value(error-opening(<str>))", n);
}

ATerm read_term_from_named_file(char *fn, char *n)
{
  ATerm t;

  if(!(t = ATreadFromNamedFile(fn))) {
    ATfprintf(stderr, "error reading from %s\n", fn);
    return open_error(n);
  }
  ATfprintf(stderr, "read term from %s\n", fn);
  return ATmake("snd-value(opened-file(<str>,<term>,<str>))", n, t, fn);
}

ATerm write_term_to_named_file(ATerm t, char *fn, char *n)
{
  FILE   *fd;

  if(!(fd = fopen(fn, "w"))) {
    ATfprintf(stderr,"cannot write to %s\n",fn);
   } else {
    ATfprintf(stderr, "writing file %s\n", fn);
    ATwriteToBinaryFile(t,fd);
    fclose(fd);
  }
  return ATmake("snd-value(save-done(<str>))", n);
}

ATerm read_raw_from_named_file(char *fn, char *n)
{
  ATerm t;
  char   *buf;
  size_t size;

  if (!(buf = slurpfile(fn, &size))) {
    ATfprintf(stderr, "error reading %s\n", fn);
    t = open_error(n);
  } else {
    ATfprintf(stderr, "raw read from %s\n", fn);
    t = ATmake("snd-value(opened-file(<str>,<str>,<str>))",
               n, buf, fn);
    free(buf);
  }
  return t;
}

ATerm open_old_asfix_file(int cid, char *name)
{
  ATerm t;
  char  *fullname,namext[PATH_LEN];

  if (asfix_status == 2) {
    ATfprintf(stderr,"cannot mix asfix modes\n");
    return open_error(name);
  }

  sprintf(namext, "%s%s", name, ".asfix");
  ATfprintf(stderr, "pre-parsed file %s\n", namext);
  if(!(fullname = find_newest_in_path(namext))) {
    t = open_error(name);
  } else {
    t = read_term_from_named_file(fullname, name);
    if(ATmatch(t, "snd-value(opened-file(<list>))", NULL))
      asfix_status = 1;
  }
  return t;
}

ATerm open_sdf2_file(int cid, char *name)
{
  char   *full;
  char   newestbaf[PATH_LEN] = {'\0'};
  char   newestraw[PATH_LEN] = {'\0'};
  ATbool newest_is_binary = ATfalse;
  ATerm  t;

  if(asfix_status == 1) {
    ATfprintf(stderr,"cannot mix asfix modes\n");
    return open_error(name);
  }

  sprintf(newestraw, "%s%s", name, ".sdf2");
  sprintf(newestbaf, "%s%s", name, ".sdf2.baf");
  ATfprintf(stderr, "looking for {%s,%s}\n", newestraw, newestbaf);

  if((full = find_newest_in_path(newestraw)))
    strcpy(newestraw, full);
  if((full = find_newest_in_path(newestbaf)))
    strcpy(newestbaf, full);
  newest_is_binary = newerfile(newestbaf, newestraw);

  if(!newestraw[0] && !newestbaf[0]) {
    ATfprintf(stderr,"requested file not found in path\n");
    return open_error(name);
  }
  if(newest_is_binary) {
    t = read_term_from_named_file(newestbaf, name);
  } else {
    t = read_raw_from_named_file(newestraw, name);
  }
  if(ATmatch(t, "snd-value(opened-file(<list>))", NULL))
    asfix_status = 2;

  return t;
}

ATerm open_eqs2_asfix_file(int cid, char *name)
{
  char *full, fullname[PATH_LEN];
  ATerm t;

  sprintf(fullname, "%s%s", name, ".eqs2.baf");
  ATfprintf(stderr, "pre-parsed file %s\n", fullname);

  if((full = find_newest_in_path(name))) {
    t = read_term_from_named_file(full, name);
  } else {
    t = open_error(name);
  }
  return t;
}

ATerm open_eqs2_text_file(int cid, char *name)
{
  char  *full;
  ATerm t;

  if((full = find_newest_in_path(name))) {
    t = read_raw_from_named_file(full, name);
  } else {
    ATfprintf(stderr,"file %s could not be found\n", name);
    t = open_error(name);
  }
  return t;
}

ATerm read_parse_table(int cid, char *name)
{
  char *full, fullname[PATH_LEN];

  sprintf(fullname, "%s%s", name, ".tbl");

  if((full = find_newest_in_path(fullname)) && fileisreadable(full))
     return ATmake("snd-value(table-on-disk(<str>))", full);

  return open_error(name);
}

ATerm open_trm_file(int cid, char *name)
{
  char *full;
  ATerm t;

  if((full = find_newest_in_path(name))) {
    t = read_raw_from_named_file(full, name);
  } else {
    ATfprintf(stderr,"file %s could not be found\n", name);
    t = open_error(name);
  }
  return t;
}

ATerm save_sdf2_asfix(int cid, char *name, char *fn, ATerm syntax)
{
  char full[PATH_LEN];

  sprintf(full, "%s%s", fn, ".baf");
  return write_term_to_named_file(syntax, full, name);
}

ATerm save_eqs2_asfix(int cid, char *name, char *fn, ATerm eqs)
{
  char full[PATH_LEN];

  sprintf(full, "%s%s", fn, ".baf");
  return write_term_to_named_file(eqs, full, name);
}

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

void read_conf(char *cfg)
{
  FILE *fd;

  if(!(fd = fopen(cfg, "r"))) {
    ATfprintf(stderr, "warning: cannot open config %s\n", cfg);
    paths[nr_paths][0]   = '.';
    paths[nr_paths++][1] = '\0';
    return;
  }
  while(fgets(paths[nr_paths], PATH_LEN, fd)) {
    if(*paths[nr_paths]) {
      if(*paths[nr_paths] != '#'){
        paths[nr_paths][strlen(paths[nr_paths])-1] = '\0';
        nr_paths++;
      } else
        *paths[nr_paths] = '\0';
    }
  }
  fclose(fd);
}

int main(int argc, char **argv)
{
  int   cid, i=0;
  ATerm bottomOfStack;

  read_conf("meta.conf");
  for(i=0; i<nr_paths; i++)
    ATfprintf(stderr, "path[%d] = %s\n", i, paths[i]);

  ATBinit(argc, argv, &bottomOfStack);
  cid = ATBconnect(NULL, NULL, -1, in_output_handler);
  ATBeventloop();

  return 0;
}
