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
static char *expandPath(const char *relative_path);

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

/*{{{  static char *ATgetString(ATerm t) */

static char *ATgetString(ATerm t)
{
  assert(t != NULL && ATgetType(t) == AT_APPL);

  return ATgetName(ATgetAFun((ATermAppl) t));
}

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
/*{{{  static ATerm createFileNotFoundMessage() */

static ATerm createFileNotFoundMessage()
{
  return ATmake("snd-value(file-not-found)");
}

/*}}}  */
/*{{{  static ATerm createFileFoundMessage(ATermList directories) */

static ATerm createFileFoundMessage(ATermList directories)
{
  return ATmake("snd-value(file-found(<term>))", directories);
}

/*}}}  */

/*{{{  static ATbool fileExists(const char *fname) */

static ATbool fileExists(const char *fname)
{
  struct stat st;
  return stat(fname, &st) != EOF ? ATtrue : ATfalse;
}

/*}}}  */
/*{{{  static size_t getFileSize(const char *s) */

static size_t getFileSize(const char *s)
{
  struct stat st;
  return (stat((char *)s, &st)!=EOF) ? st.st_size : -1L;
}

/*}}}  */

/*{{{  static char *readFileContents(char *fnam, size_t *size) */

static char *readFileContents(char *fnam, size_t *size)
{
  char *buf;
  FILE *fd;

  *size = getFileSize(fnam);
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
    t = ATmake("snd-value(file-contents(<str>))", buf);
    free(buf);
  }
  return t;
}

/*}}}  */
 /*{{{  static char *expandPath(const char *relative_path) */

/* Expand a relative path to its absolute equivalent
 *
 * - ATerror upon serious failure (no current directory, no memory)
 * - returns NULL when relative_path could not be expanded
 * - returns calloc(3)-ed pointer containing absolute path otherwise.
 */
static char *expandPath(const char *relative_path)
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
    ATerror("expandPath: out of memory.\n");
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

/*{{{  static char *makeFileName(char *path, char *extension) */

static char *makeFileName(char *path, char *extension)
{
  char *fileName = NULL;

  assert(strlen(path) != 0 && "path is empty");

  fileName = calloc(sizeof(char), strlen(path) + strlen(extension) + 1);

  if (fileName != NULL) {
    sprintf(fileName,"%s%s", path, extension);
  }
  else {
    return NULL;
  }

  return fileName;
}

/*}}}  */

/*{{{  ATerm relative_to_absolute(int cid, ATerm paths) */

ATerm relative_to_absolute(int cid, ATerm paths)
{
  ATermList relativePaths = (ATermList) paths;
  ATermList result = ATempty;
  char *relativePath = NULL;
  char *absolutePath = NULL;

  for (; !ATisEmpty(relativePaths); relativePaths = ATgetNext(relativePaths)) {
    relativePath = ATgetString(ATgetFirst(relativePaths));
    absolutePath = expandPath(relativePath);

    if (absolutePath != NULL) {
      result = ATinsert(result, ATmake("<str>", absolutePath));
    }
    else {
      ATwarning("Unable to expand %s, skipping...\n", relativePath);
    }
  }

  return ATmake("snd-value(absolute-directories(<term>))", ATreverse(result));
}

/*}}}  */

/*{{{  ATerm read_named_text_file(int cid, char *fileName) */

ATerm read_named_text_file(int cid, char *fileName)
{
  return read_raw_from_named_file(fileName);
}

/*}}}  */

/*{{{  ATerm read_text_file(int cid, char *path, char *extension) */

ATerm read_text_file(int cid, char *path, char *extension)
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

  if (fileExists(fileName)) {
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

  if (fileExists(fileName)) {
    result = createSuccessMessage();
  }
  else {
    result = createErrorMessage("file does not exist");
  }
  free(fileName);
  return result;
}

/*}}}  */

/*{{{  ATerm find_file(int cid, ATerm paths, char *name, char *extension) */

ATerm find_file(int cid, ATerm paths, char *name, char *extension)
{
  char filename[PATH_LEN];
  ATermList searchPaths = (ATermList) paths;
  ATermList directories = ATempty;
 
  for (; !ATisEmpty(searchPaths); searchPaths = ATgetNext(searchPaths)) {
    ATerm path = ATgetFirst(searchPaths);
    char *pathString = ATgetString(path);
    sprintf(filename, "%s%s%s%s", pathString, SEP, name, extension);

    if (fileExists(filename)) {
      directories = ATinsert(directories, path);
    }
  }

  if (ATisEmpty(directories)) {
    return createFileNotFoundMessage();
  }
  else {
    return createFileFoundMessage(directories);
  }
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
      absolute_path = expandPath(contents);
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

/*{{{  static ATerm createCompareMessage(ATbool result) */

static ATerm createCompareMessage(ATbool filesEqual)
{
  if (filesEqual) {
    return ATmake("snd-value(equal)");
  }
  else {
    return ATmake("snd-value(different)");
  }
}

/*}}}  */
/*{{{  static ATbool filesEqual(const char *f1, const char *f2) */

static ATbool filesEqual(const char *f1, const char *f2)
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
/*{{{  ATerm compare_files(int cid, char *f1, char *f2) */

ATerm compare_files(int cid, char *f1, char *f2)
{
  return createCompareMessage(filesEqual(f1, f2));
}

/*}}}  */

/*{{{  ATerm get_filename(int cid, char *directory, char *name, char *extension) */

ATerm get_filename(int cid, char *directory, char *name, char *extension)
{
  char fileName[PATH_LEN];

  sprintf(fileName, "%s%s%s%s", directory, SEP, name, extension);

  return ATmake("snd-value(filename(<str>))", fileName);
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
