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
static char *expand_path(const char *relative_path);

/*}}}  */
/*{{{  defines */


#define PATH_LEN (_POSIX_PATH_MAX)
#define MAX_PATHS 256
#define SEP "/"

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

/*}}}  */

/*{{{  static ATerm createErrorMessage(char *message) */

static ATerm createErrorMessage(char *message)
{
  return ATmake("snd-value(failure(<str>))", message);
}

/*}}}  */
/*{{{  static ATerm createSuccessMessage() */

static ATerm createSuccessMessage()
{
  return ATmake("snd-value(success)");
}

/*}}}  */

/*{{{  static int fileexists(const char *fname) */

static int fileexists(const char *fname)
{
  struct stat st;
  return stat(fname,&st) != EOF;
}

/*}}}  */
/*{{{  static size_t filesize(const char *s) */

static size_t filesize(const char *s)
{
  struct stat st;
  return (stat((char*)s,&st)!=EOF) ? st.st_size : -1L;
}

/*}}}  */
/*{{{  static char *readFileContents(char *fnam, size_t *size) */

static char *readFileContents(char *fnam, size_t *size)
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
/*{{{  static ATerm read_raw_from_named_file(char *fn, char *n) */

static ATerm read_raw_from_named_file(char *fileName)
{
  ATerm t;
  char   *buf;
  size_t size;

  if (!(buf = readFileContents(fileName, &size))) {
    t = createErrorMessage("could not open file");
  } else {
    t = ATmake("snd-value(opened-file(text(<str>)))", buf);
    free(buf);
  }
  return t;
}

/*}}}  */
 /*{{{  static char *expand_path(const char *relative_path) */

static char *expand_path(const char *relative_path)
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
/*{{{  static void add_path(char *pathname) */

static void add_path(char *pathname)
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

/*{{{  static char *makeFileName(char *path, */

static char *makeFileName(char *path, char *extension)
{
  char *fileName = NULL;

  assert(strlen(path) != 0 && "path is empty");

  fileName = calloc(sizeof(char), strlen(path) + 
		    strlen(extension) + 1);

  if (fileName != NULL) {
    sprintf(fileName,"%s%s", path, extension);
  }
  else {
    return NULL;
  }

  return fileName;
}

/*}}}  */
/*{{{  static char *makePath(char *path, char *name) */

static char *makePath(char *path, char *name)
{
  char *newPath = NULL;

  assert(strlen(path) != 0 && "path is empty");
  assert(strlen(name) != 0 && "name is empty");

  newPath = calloc(sizeof(char), strlen(path) + strlen(SEP) +
                   strlen(name) + 1);

  if (newPath != NULL) {
    sprintf(newPath,"%s%s%s", path, SEP, name);
  }
  else {
    return NULL;
  }

  return newPath;
}

/*}}}  */

/*{{{  ATerm open_named_text_file(int cid, char *fileName) */

ATerm open_named_text_file(int cid, char *fileName)
{
  return read_raw_from_named_file(fileName);
}

/*}}}  */

/*{{{  ATerm open_text_file(int cid, char *path, char *name,  */

ATerm open_text_file(int cid, char *path, char *extension)
{
  char *fileName = makeFileName(path, extension);
  ATerm t = read_raw_from_named_file(fileName);

  free(fileName);
  return t;
}

/*}}}  */
/*{{{  ATerm write_text_file(int cid, char *fileName, char *path, char *extension, char *content) */

ATerm write_text_file(int cid, char *path,
		      char *extension, ATerm content)
{
  ATermList list = (ATermList) content;
  char *fileName = makeFileName(path, extension);
  FILE *file = NULL;
  ATerm message;

  if (fileName != NULL) {
    if (!(file = fopen(fileName, "w"))) {
      message = createErrorMessage("could not open file");
    }
    else {
      int error = 1;

      for (; !ATisEmpty(list); list = ATgetNext(list)) {
	ATerm atString = ATgetFirst(list);
	char *string = ATgetName(ATgetAFun((ATermAppl) atString));
	error = fputs(string, file);
      }

      if (error != EOF) {
	message = createSuccessMessage();
      }
      else {
	message = createErrorMessage("disk full");
      }

      fclose(file);
    }

    free(fileName);
  }
  else{
    message = createErrorMessage("out of memory");
  }

  return message;
}

/*}}}  */

/*{{{  ATerm write_term_file(int cid, char *path, char *extension, ATerm content) */

ATerm write_term_file(int cid, char *path, char *extension, 
		      ATerm packedContent)
{
  char *fileName = makeFileName(path, extension);
  ATerm message;

  ATerm content = ATBunpack(packedContent);

  if (fileName != NULL) {
    FILE *file = NULL;

    if (!(file = fopen(fileName, "w"))) {
      message = createErrorMessage("could not open file");
    }
    else {
      if (ATwriteToBinaryFile(content, file)) {
        message = createSuccessMessage();
      }
      else {
	message = createErrorMessage("disk full");
      }
      fclose(file);
    }
  }
  else{
    message = createErrorMessage("out of memory");
  }

  return message;
}

/*}}}  */

/*{{{  ATerm exists_named_file(int cid, char *fileName) */

ATerm exists_named_file(int cid, char *fileName)
{
  ATerm result;

  if (fileexists(fileName)) {
    result = createSuccessMessage();
  }
  else {
    result = createErrorMessage("file does not exist");
  }
  return result;
}

/*}}}  */
/*{{{  ATerm exists_file(int cid, char *path, char *name, char *extension) */

ATerm exists_file(int cid, char *path, char *extension)
{
  char *fileName = makeFileName(path, extension);
  ATerm result;

  if (fileexists(fileName)) {
    result = createSuccessMessage();
  }
  else {
    result = createErrorMessage("file does not exist");
  }
  free(fileName);
  return result;
}

/*}}}  */

/*{{{  ATerm find_file(int cid, char *path, char *name, char *extension) */

ATerm find_file(int cid, char *path, char *name, char *extension)
{
  char *newPath = makePath(path, name);
  char *fileName = makeFileName(newPath, extension);
  ATerm result;

  if (fileexists(fileName)) { 
    result = ATmake("snd-value(file-found(<str>))", newPath);
  }   
  else {
    result = createErrorMessage("file does not exist");
  }
  free(newPath);
  free(fileName);
  return result;
}

/*}}}  */
/*{{{  ATerm process_search_paths(int cid, ATerm paths) */

ATerm process_search_paths(int cid, ATerm paths)
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

  return ATmake("snd-value(search-paths-processed)");
}

/*}}}  */
/*{{{  ATerm retrieve_search_paths(int cid) */

ATerm retrieve_search_paths(int cid)
{
  int i;
  ATermList atPaths = ATempty;

  for (i=0; i<nr_paths; i++) {
    atPaths = ATinsert(atPaths, ATmake("<str>", paths[i]));
  }
  return ATmake("snd-value(search-paths([<list>]))", atPaths);
}

/*}}}  */

/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
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
/*{{{  static void version(char *prg) */

static void version(char *prg)
{
  ATwarning("%s v%s\n", prg, myversion);
  exit(1);
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm arg) */

void rec_terminate(int cid, ATerm arg)
{
  /* FIXME: free <nr_paths> entries in <paths> */
  exit(0);
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
