/*{{{  includes */

#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <assert.h>
#include <sys/stat.h>

#include "in-output.tif.h"

/*}}}  */
/*{{{  defines */


#define PATH_LEN (_POSIX_PATH_MAX)
#define MAX_PATHS 256

/* Macro's for file extensions */
#define BAF_EXT	".baf"
#define TBL_EXT ".tbl"
#define TXT_EXT ".txt"

/* Macro for extension of dump of all equations for a module */
#define EQSDUMP_BAF_EXT ".eqs"

/*}}}  */
/*{{{  variables */

ATbool run_verbose = ATfalse;

static char myversion[] = "1.5";

/*
   The argument vector: list of option letters, colons denote option
   arguments.  See usage function, immediately below, for option
   explanation.
 */

static char myarguments[] = "hvV";

static int  nr_paths = 0;
static char *paths[MAX_PATHS];
static char *syntax_ext;
static char *rules_ext;
static char *term_ext;

/*}}}  */

/*{{{  void usage(char *prg, ATbool is_err) */

void usage(char *prg, ATbool is_err)
{
  ATwarning(
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-h              display help information (usage)\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    prg, myversion);
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  int fileexists(const char *fname) */

int fileexists(const char *fname)
{
  struct stat st;
  return stat(fname,&st) != EOF;
}

/*}}}  */
/*{{{  time_t filetime(const char *fname) */

time_t filetime(const char *fname)
{
  struct stat st;
  return stat(fname,&st)!=EOF ? st.st_mtime : -1L;
}

/*}}}  */
/*{{{  size_t filesize(const char *s) */

size_t filesize(const char *s)
{
  struct stat st;
  return (stat((char*)s,&st)!=EOF) ? st.st_size : -1L;
}

/*}}}  */
/*{{{  ATbool fileequal(const char *f1, const char *f2) */

ATbool fileequal(const char *f1, const char *f2)
{
  struct stat st1;
  struct stat st2;

  if (stat(f1, &st1) == 0 && stat(f2, &st2) == 0) {
    return st1.st_ino == st2.st_ino;
  }
  else {
    perror("stat");
    return ATfalse;
  }
}

/*}}}  */
/*{{{  int fileisregular(const char *s) */

int fileisregular(const char *s)
{
  struct stat st;
  return (stat((char*)s,&st)!=EOF) ? S_ISREG(st.st_mode) : 0;
}

/*}}}  */
/*{{{  int fileisreadable(const char *s) */

int fileisreadable(const char *s)
{
  FILE *fd;
  return fileisregular(s) && (fd = fopen(s, "rb")) && fclose(fd);
}

/*}}}  */
/*{{{  int newerfile(const char *s1, const char *s2) */

int newerfile(const char *s1, const char *s2)
{
  return filetime(s1) > filetime(s2);
}

/*}}}  */
/*{{{  char *readFileContents(char *fnam, size_t *size) */

/*
 * JS: Initially, this was designed to read arbitrary buffers.
 * So it returned an allocated, filled buffer as well as a size_t
 * indication of its length.
 * The fragment below assumes is modified to read an arbitrary
 * file with no NULL characters in it into a buffer, which is then
 * NULL-terminated.
 * The resulting output is a properly terminated C string.
 */

char *readFileContents(char *fnam, size_t *size)
{
  char *buf;
  FILE *fd;

  *size = filesize(fnam);
  if((fd = fopen(fnam, "rb")) == NULL) {
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

/*}}}  */
/*{{{  ATbool path_length_exceeded(int length) */

ATbool path_length_exceeded(int length)
{
  return (length > PATH_LEN);
}

/*}}}  */
/*{{{  char *find_in_path(char *target) */

char *find_in_path(char *target)
{
  static char filename[PATH_LEN + 1]; /* max. pathlength + '\0' */
  char thisname[PATH_LEN + 1];
  int i, name_length;
  ATbool found = ATfalse;

  assert(target != NULL);

  strcpy(filename, "");
  name_length = 1 + strlen(target); /* '/' + filename */

  for (i=0; i<nr_paths; i++) {
    /* Make sure pathlength doesn't exceed sane length. */
    if (path_length_exceeded(strlen(paths[i]) + name_length)) {
      ATwarning("warning: path too long: %s/%s\n", paths[i], target);
      continue;
    }

    /* Construct filename, now that we know it will fit */
    sprintf(thisname, "%s/%s", paths[i], target);

    /* Check if this file exists */
    if (fileexists(thisname)) {
      if (found && !fileequal(thisname, filename)) {
	ATwarning(" warning: found multiple matches for %s\n", target);
	ATwarning("   using: %s\n", filename);
	ATwarning("    peer: %s\n", thisname);
      }
      else {
	found = ATtrue;
	strcpy(filename, thisname);
      }
    }
  }

  if (run_verbose) {
    if (found) {
      ATwarning("Found: %s\n", filename);
    }
    else {
      ATwarning("No entry in searchpath for %s\n", target);
    }
  }

  return found ? filename : NULL;
}

/*}}}  */
/*{{{  ATerm open_error(char *error_message) */

ATerm open_error(char *error_message)
{
  return ATmake("snd-value(error-opening(<str>))", error_message);
}

/*}}}  */
/*{{{  ATerm read_term_from_named_file(char *fn, char *n) */

ATerm read_term_from_named_file(char *fn, char *n)
{
  ATerm t;
  static char pn[PATH_LEN];

  if(!(t = ATreadFromNamedFile(fn))) {
    if (run_verbose) {
      ATwarning("error reading %s\n", fn);
    }
    return open_error(n);
  }

  /* Remove BAF_EXT from filename */
  strncpy(pn,fn,strlen(fn)-strlen(BAF_EXT));
  pn[strlen(fn)-strlen(BAF_EXT)] = '\0';

  return ATmake("snd-value(opened-file(<str>,tree(<term>),<str>,"
		"timestamp(<int>)))",
		n, t, pn, filetime(fn));
}

/*}}}  */
/*{{{  ATerm write_term_to_named_file(ATerm t, char *fn, char *n) */

ATerm write_term_to_named_file(ATerm t, char *fn, char *n)
{
  static char pn[PATH_LEN];
  FILE   *fd;

  sprintf(pn, "%s%s",fn, BAF_EXT);
  if(!(fd = fopen(pn, "w"))) {
    ATwarning("%s: cannot create\n", pn);
  }
  else {
    ATwriteToBinaryFile(t,fd);
    fclose(fd);
  }
  return ATmake("snd-value(save-done(<str>))", n);
}

/*}}}  */
/*{{{  ATerm create_equations_dump_file(int cid, char *module, ATerm equations) */

ATerm create_equations_dump_file(int cid, char *module, char *path,
                                 ATerm equations)
{
  FILE *f = NULL;
  char filename[PATH_LEN] = {'\0'};

  if (strlen(path) > 0) {
    sprintf(filename,"%s", path);
  }
  else {
    sprintf(filename,"%s%s", module, EQSDUMP_BAF_EXT);
  }

  if(!(f = fopen(filename, "w"))) {
    char *errmsg = strerror(errno);
    if (run_verbose) {
      ATwarning("create_equations_dump_file: %s\n", errmsg);
    }
    return ATmake("snd-value(create-equations-dump-file-failed(<str>, <str>))", 
		  module, errmsg);
  }

  ATwriteToBinaryFile(equations, f);

  fclose(f);

  return ATmake("snd-value(create-equations-dump-file-done(<str>))", module);
}

/*}}}  */
/*{{{  ATerm read_raw_from_named_file(char *fn, char *n) */

ATerm read_raw_from_named_file(char *fn, char *n)
{
  ATerm t;
  char   *buf;
  size_t size;

  if (!(buf = readFileContents(fn, &size))) {
    if (run_verbose) {
      ATwarning("error reading %s\n", fn);
    }
    t = open_error(n);
  } else {
    if(run_verbose) {
      ATwarning("reading %s (ascii)\n", fn);
    }
    t = ATmake("snd-value(opened-file(<str>,text(<str>),<str>,"
	       "timestamp(<int>)))",
	       n, buf, fn, filetime(fn));
    free(buf);
  }
  return t;
}

/*}}}  */
/*{{{  ATerm read_file(int cid, char *name)  */

ATerm read_file(int cid, char *name) 
{
  ATerm t;
  char   *buf;
  size_t size;

  if (!(buf = readFileContents(name, &size))) {
    if (run_verbose) {
      ATwarning("error reading %s\n", name);
    }
    t = open_error(name);
  }
  else {
    if (run_verbose) {
      ATwarning("reading %s (ascii)\n", name);
    }
    t = ATmake("snd-value(file-contents(<str>,<str>))", name, buf);
    free(buf);
  }
  return t; 
}

/*}}}  */
/*{{{  ATerm read_aterm_file(int cid, char *name)  */

ATerm read_aterm_file(int cid, char *name) 
{
  ATerm ft, t;

  if(!(t = ATreadFromNamedFile(name))) {
    if (run_verbose) {
      ATwarning("error reading %s\n", name);
    }
    return open_error(name);
  }
  else {
    if (run_verbose) {
      ATwarning("reading %s (ascii)\n", name);
    }
    ft = ATmake("snd-value(file-contents(<str>,<term>))", name, t);
  }
  return ft; 
}

/*}}}  */
/*{{{  ATerm exists_syntax_module(int cid, char *moduleName) */

ATerm exists_syntax_module(int cid, char *moduleName)
{
  char   txtFileName[PATH_LEN] = {'\0'};

  sprintf(txtFileName, "%s%s", moduleName, syntax_ext);

  if (fileexists(txtFileName)) {
    return ATmake("snd-value(exists)");
  }
  else {
    return ATmake("snd-value(not-exists)");
  }
}

/*}}}  */
/*{{{  ATerm create_empty_syntax_module(int cid, char *moduleName) */

ATerm create_empty_syntax_module(int cid, char *path, char *moduleName)
{
  FILE *f;
  char txtFileName[PATH_LEN] = {'\0'};

  /* Build syntax-text-filename from moduleName */
  sprintf(txtFileName, "%s%s", path, syntax_ext);

  if (!(f = fopen(txtFileName, "w"))) {
    char *errmsg = strerror(errno);
    if (run_verbose) {
      ATwarning("create_empty_syntax_module: %s\n", errmsg);
    }
    return ATmake("snd-value(creation-failed(<str>))", errmsg);
  }

  /* Insert proper syntax syntax. */
  fprintf(f, "module %s\n", moduleName);

  fclose(f);

  return ATmake("snd-value(creation-succeeded)");
}

/*}}}  */
/*{{{  ATerm exists_rules_section(int cid, char *moduleName) */

ATerm exists_rules_section(int cid, char *name, char *syntaxPath)
{
  char filename[PATH_LEN] = {'\0'};
  char  *p;

  strcpy(filename, syntaxPath);
  p = strrchr(filename, '.');
  if (p != NULL) {
    strcpy(p, rules_ext);
  }

  if (fileexists(filename)) {
    return ATmake("snd-value(exists)");
  } else {
    return ATmake("snd-value(not-exists)");
  }
}

/*}}}  */
/*{{{  ATerm create_empty_rules_section(int cid, char *name, char *syntaxPath) */

ATerm create_empty_rules_section(int cid, char *name, char *syntaxPath)
{
  FILE *file;
  char filename[PATH_LEN] = {'\0'};
  char *p;

  strcpy(filename, syntaxPath);
  p = strrchr(filename, '.');
  if (p != NULL) {
    strcpy(p, rules_ext);
  }

  file = fopen(filename, "w");
  if (file == NULL) {
    char *errmsg = strerror(errno);
    if (run_verbose) {
      ATwarning("create_empty_eqs_section: %s\n", errmsg);
    }
    return ATmake("snd-value(creation-failed(<str>))", errmsg);
  }

  fclose(file);

  return ATmake("snd-value(creation-succeeded(<str>))", filename);
}

/*}}}  */

/*{{{  ATerm open_file(int cid, char *path) */

ATerm open_file(int cid, char *path)
{
  char   newestbaf[PATH_LEN] = {'\0'};
  char   newestraw[PATH_LEN] = {'\0'};
  ATbool newest_is_binary = ATfalse;
  ATerm  t;

  strcpy(newestraw, path);
  sprintf(newestbaf, "%s%s", newestraw, BAF_EXT);
  
  if (fileexists(newestbaf)) {
    newest_is_binary = newerfile(newestbaf, newestraw);
  }

  if (newest_is_binary) {
    t = read_term_from_named_file(newestbaf, path);
  } else {
    t = read_raw_from_named_file(newestraw, path);
  }

  return t;
}

/*}}}  */
/*{{{  ATerm remove_module(int cid, char *name) */

ATerm remove_module(int cid, char *name)
{
  char   *full;
  char   bafsyntaxfile[PATH_LEN] = {'\0'};
  char   textsyntaxfile[PATH_LEN] = {'\0'};
  char   bafrulesfile[PATH_LEN] = {'\0'};
  char   textrulesfile[PATH_LEN] = {'\0'};
  char   *p;

  sprintf(textsyntaxfile, "%s%s", name, syntax_ext);
  full = find_in_path(textsyntaxfile);
  if (full != NULL) {
    remove(full);

    strcpy(textsyntaxfile, full);
    sprintf(bafsyntaxfile, "%s%s", textsyntaxfile, BAF_EXT);
  
    if (fileexists(bafsyntaxfile)) {
      remove(bafsyntaxfile);
    }

    strcpy(textrulesfile, textsyntaxfile);
    p = strrchr(textrulesfile, '.');
    if (p != NULL) {
      strcpy(p, rules_ext);
    }

    if (fileexists(textrulesfile)) {
      remove(textrulesfile);

      sprintf(bafrulesfile, "%s%s", textrulesfile, BAF_EXT);

      if (fileexists(bafrulesfile)) {
        remove(bafrulesfile);
      }
    }
  }
  return ATmake("snd-value(removed-module)");
}

/*}}}  */
/*{{{  ATerm open_syntax_file(int cid, char *name) */

ATerm open_syntax_file(int cid, char *name)
{
  char   *full;
  char   newestbaf[PATH_LEN] = {'\0'};
  char   newestraw[PATH_LEN] = {'\0'};
  ATbool newest_is_binary = ATfalse;
  ATerm  t;

  sprintf(newestraw, "%s%s", name, syntax_ext);
  full = find_in_path(newestraw);
  if (full == NULL) {
    ATwarning("open_syntax_file: %s not found in path.\n", newestraw);
    return open_error(name);
  }

  strcpy(newestraw, full);
  sprintf(newestbaf, "%s%s", newestraw, BAF_EXT);
  
  if (fileexists(newestbaf)) {
    newest_is_binary = newerfile(newestbaf, newestraw);
  }

  if (newest_is_binary) {
    t = read_term_from_named_file(newestbaf, name);
  } else {
    t = read_raw_from_named_file(newestraw, name);
  }

  return t;
}

/*}}}  */
/*{{{  ATerm open_rules_file(int cid, char *name, char *syntaxPath) */

ATerm open_rules_file(int cid, char *name, char *syntaxPath)
{
  char   newestbaf[PATH_LEN] = {'\0'};
  char   newestraw[PATH_LEN] = {'\0'};
  ATbool newest_is_binary = ATfalse;
  ATerm  t;
  char  *p;

  strcpy(newestraw, syntaxPath);
  p = strrchr(newestraw, '.');
  if (p != NULL) {
    strcpy(p, rules_ext);
  }

  if (!fileexists(newestraw)) {
    return open_error(name);
  }

  sprintf(newestbaf, "%s%s", newestraw, BAF_EXT);
  if (fileexists(newestraw)) {
    newest_is_binary = newerfile(newestbaf, newestraw);
  }

  if (newest_is_binary) {
    t = read_term_from_named_file(newestbaf, name);
  } else {
    t = read_raw_from_named_file(newestraw, name);
  }

  return t;
}

/*}}}  */
/*{{{  ATerm open_trm_file(int cid, char *name) */

ATerm open_trm_file(int cid, char *name)
{
  return read_raw_from_named_file(name, name);
}

/*}}}  */

/*{{{  ATerm open_parse_table(int cid, char *name, ATerm tableType) */

ATerm open_parse_table(int cid, char *name, char *syntaxPath, ATerm tableType)
{
  ATerm t, packed;
  char filename[PATH_LEN];
  char *p;

  strcpy(filename, syntaxPath);
  p = strrchr(filename, '.');
  assert (p != NULL);

  if (ATisEqual(tableType, ATmake("asf"))) {
    strcpy(p, rules_ext);
  } else {
    strcpy(p, term_ext);
  }

  strcat(filename, TBL_EXT);

  if (fileexists(filename)) {
    t = ATreadFromNamedFile(filename);
    if (t == NULL) {
      if (run_verbose) {
	ATwarning("error reading %s\n", filename);
      }
      return open_error(name);
    }

    packed = ATBpack(t);
    packed = ATmake("lazy-unpack(<term>)", ATgetArgument((ATermAppl)packed, 0));

    return ATmake("snd-value(table-on-disk(<term>,timestamp(<int>)))",
		  packed, filetime(filename));
  }

  return open_error(name);
}

/*}}}  */
/*{{{  ATerm save_parsetable(int cid, char *name, char *fn, ATerm table) */

ATerm save_parsetable(int cid, char *name, char *fn, ATerm table)
{
  FILE *fd = NULL;

  if (!(fd = fopen(fn, "w"))) {
    ATwarning("%s: cannot create\n", fn);
  }
  else {
    ATwriteToBinaryFile(table,fd);
    fclose(fd);
  }

  return ATmake("snd-value(save-done(<str>))", name);
}

/*}}}  */

/*{{{  ATerm save_tree(int cid, char *name, char *fn, ATerm tree) */

ATerm save_tree(int cid, char *name, char *fn, ATerm tree)
{ 
  return write_term_to_named_file(tree, fn, name);
}

/*}}}  */
/*{{{  ATerm save_text_file(int cid, char *filename, char *text) */

ATerm save_text_file(int cid, char *filename, char *text)
{
  FILE *file;

  if (!(file = fopen(filename, "w"))) {
    ATwarning("%s: cannot create\n", filename);
  } 
  else {
    fputs(text, file);
    fclose(file);
  }
  return ATmake("snd-value(save-done(<str>))", filename);
}

/*}}}  */
/*{{{  ATerm print_module_text(int cid, char *modname, char *filename, char *syntaxtext, char *rulestext) */

ATerm print_module_text(int cid, char *modname, char *syntaxPath, 
                        char *syntaxtext, char *rulestext)
{
  FILE *file;

  char filename[PATH_LEN] = {'\0'};
  char  *p;

  strcpy(filename, syntaxPath);
  p = strrchr(filename, '.');
  if (p != NULL) {
    strcpy(p, TXT_EXT);
  }

  if (!(file = fopen(filename, "w"))) {
    ATwarning("%s: cannot create\n", filename);
  } 
  else {
    fputs(syntaxtext, file);
    if (strlen(rulestext) > 0) {
      fputc('\n', file);
      fputs(rulestext, file);
    }
    fclose(file);
  }

  return ATmake("snd-value(module-text-printed(<str>))", modname);
}

/*}}}  */


/*{{{  void rec_terminate(int cid, ATerm arg) */

void rec_terminate(int cid, ATerm arg)
{
  /* FIXME: free <nr_paths> entries in <paths> */
  exit(0);
}

/*}}}  */
/*{{{  void add_path(char *pathname) */

void add_path(char *pathname)
{
  int i;

  /* Ward off illegal entries */
  assert(pathname != NULL);

  if (nr_paths >= MAX_PATHS) {
    if (run_verbose) {
      ATwarning("add_path(%s) failed, nr_paths exceeded (max = %d)\n",
		pathname, MAX_PATHS);
    }
    return;
  }

  /* ignore duplicate entries */
  for (i=0; i<nr_paths; i++) {
    if (strcmp(paths[i], pathname) == 0) {
      if (run_verbose) {
	ATwarning("ignoring duplicate entry in searchpath: %s\n", pathname);
      }
      return;
    }
  }

  if (run_verbose) {
    ATwarning("path[%d] = %s\n", nr_paths, pathname);
  }

  paths[nr_paths++] = pathname;
}

/*}}}  */
/*{{{  char *expand_path(const char *relative_path) */
/* Expand a relative path to its absolute equivalent
 *
 * - aborts upon serious failure (no current directory, no memory)
 * - returns NULL when relative_path could not be expanded
 * - returns calloc(3)-ed pointer containing absolute path otherwise.
 */

char *expand_path(const char *relative_path)
{
  char *absolute_path = NULL;
  char *trial_path = NULL;
  char current_dir[PATH_LEN + 1];

  /* Save current dir */
  if (getcwd(current_dir, PATH_LEN) == NULL) {
    ATerror("no current directory: %s\n", strerror(errno));
  }

  /* Go to relative dir */
  if (chdir(relative_path) == -1) {
    return NULL;
  }

  /* Allocate sufficient memory for worstcase expansion */
  trial_path = (char *) calloc(PATH_LEN + 1, sizeof(char));
  if (trial_path == NULL) {
    ATerror("expand_path: out of memory.\n");
    return NULL;
  }

  /* Try to get absolute pathname */
  absolute_path = getcwd(trial_path, PATH_LEN);

  /* Restore current dir */
  if (chdir(current_dir) == -1) {
    ATerror("could not chdir(%s): %s\n", current_dir, strerror(errno));
  }

  /* May have to cleanup allocated memory upon failure */
  if (absolute_path == NULL) {
    free(trial_path);
  }

  return absolute_path;
}

/*}}}  */
/*{{{  ATerm process_search_paths(int cid, char *config_filename, ATerm paths) */

ATerm process_search_paths(int cid, char *config_filename, ATerm paths)
{
  ATerm path = NULL;
  char *contents;
  char *absolute_path;

  while (!ATisEmpty((ATermList) paths)) {
    path = ATgetFirst((ATermList) paths);
    paths = (ATerm) ATgetNext((ATermList) paths);

    if (ATmatch(path, "<str>", &contents)) {
      absolute_path = expand_path(contents);
      if (absolute_path != NULL) {
	add_path(absolute_path);
      }
    }
  }

  return ATmake("snd-value(search-paths-processed(<str>))", config_filename);
}

/*}}}  */
/*{{{  void set_file_extensions(int cid, char *syntaxExt, char *ruleExt, char *termExt) */

void set_file_extensions(int cid, char *syntaxExt, char *rulesExt, char *termExt)
{
  syntax_ext = (char *) malloc(strlen(syntaxExt) + 1);
  if (syntax_ext == NULL) {
    ATerror("set_file_extensions: out of memory.\n");
  }
  strcpy(syntax_ext, syntaxExt); 
  rules_ext = (char *) malloc(strlen(rulesExt) + 1);
  if (rules_ext == NULL) {
    ATerror("set_file_extensions: out of memory.\n");
  }
  strcpy(rules_ext, rulesExt); 
  term_ext = (char *) malloc(strlen(termExt) + 1);
  if (term_ext == NULL) {
    ATerror("set_file_extensions: out of memory.\n");
  }
  strcpy(term_ext, termExt); 
}

/*}}}  */
/*{{{  void version(char *prg) */

void version(char *prg)
{
  ATwarning("%s v%s\n", prg, myversion);
  exit(1);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int   c, cid, toolbus_mode = 0;
  ATerm bottomOfStack;

  /* Check whether we're a ToolBus process */
  for (c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  if (!toolbus_mode) {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'v':
	  run_verbose = ATtrue;
	  break;
	case 'V':
	  version(argv[0]);
	  break;
	case 'h':
	  usage(argv[0], ATfalse);
	  break;
	default:
	  usage(argv[0], ATtrue);
	  break;
      }
    }
  }

  if (toolbus_mode) {
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, in_output_handler);
    ATBeventloop();
  }

  return 0;
}

/*}}}  */
