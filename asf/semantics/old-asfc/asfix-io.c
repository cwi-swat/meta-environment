/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

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
  $Id$
 */

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <aterm2.h>
#include <atb-tool.h>

#define PATH_LEN _POSIX_PATH_MAX
#define MAX_PATHS 256

/* This is a hack, due to JS */
#include <sys/stat.h>

ATbool run_verbose = ATfalse;

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See usage function, immediately below, for option
    explanation.
 */

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
 * JS: Initially, this was designed to read arbitrary buffers.
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
                /* fprintf(stderr, "could not open %s\n", fnam); */
                *size = 0;
                return NULL;
        }
        if((buf = (char *)malloc(*size + 1)) == NULL ) {
                /*
                fprintf(stderr, "could not allocate %i bytes for %s\n",
                        (int) *size+1, fnam);
                */
                fclose(fd);
                *size = 0;
                return NULL;
        }
        if(fread(buf, 1, *size, fd) != *size) {
                /*
                fprintf(stderr, "could not fread() %i bytes %s\n",
                        (int) *size, fnam);
                */
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

  ATwarning("warning: path too long, ignored: %s/%s\n", p, f);
  return ATtrue;
}

int  nr_paths = 0;
char paths[MAX_PATHS][PATH_LEN];

char *find_newest_in_path(char *name)
{
  int    i;
  char   thisname[PATH_LEN];
  static char   newestnamebuf[PATH_LEN];
  char*  newestname = NULL;
  time_t  newesttime = -1L, thistime;

  for(i=0; i<nr_paths; i++) {
    if(path_length_exceeded(strlen(paths[i])+strlen(name)+1, paths[i], name))
      continue;
    sprintf(thisname, "%s/%s", paths[i], name);
    if((thistime = filetime(thisname)) > newesttime) {
      newesttime = thistime;
      strcpy( newestnamebuf, thisname );
      newestname = newestnamebuf;
    }
  }

  if(newestname && run_verbose) {
    ATwarning("Found %s\n", newestname);
  }

  return newestname;
}

ATerm open_error(char *n)
{
  return ATmake("snd-value(error-opening(<str>))", n);
}

ATerm read_term_from_named_file(char *fn, char *n)
{
  ATerm       t;

  if(!(t = ATreadFromNamedFile(fn))) {
    if (run_verbose) {
      ATwarning("error reading %s\n", fn);
    }
    return open_error(n);
  }
  return t; 
}

ATerm open_asfix_file(char *name)
{
  ATerm  t;
  char  *fullname, namext[PATH_LEN];

  sprintf(namext, "%s%s", name, ".asfix");
  if(!(fullname = find_newest_in_path(namext))) {
    t = open_error(name);
  } else {
    t = read_term_from_named_file(fullname, name);
  }
  return t;
}

void read_conf(char *cfg)
{
  FILE *fd;

  if(!(fd = fopen(cfg, "r"))) {
    if(run_verbose) ATwarning("warning: no %s, using default config\n", cfg);
    paths[nr_paths][0]   = '.';
    paths[nr_paths++][1] = '\0';
    return;
  }
  while(fgets(paths[nr_paths], PATH_LEN, fd)) {
    if(*paths[nr_paths]) {
      if(*paths[nr_paths] != '#'){
        int len = strlen(paths[nr_paths])-1;

        while(isspace((int) paths[nr_paths][len]))
          paths[nr_paths][len--] = '\0';
        nr_paths++;
      } else
        *paths[nr_paths] = '\0';
    }
  }
  fclose(fd);
}


