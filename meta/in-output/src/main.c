/*{{{  includes */

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <aterm2.h>
#include <atb-tool.h>

#include "in-output.tif.h"

/*}}}  */
/*{{{  defines */

#define PATH_LEN (_POSIX_PATH_MAX)
#define SEP "/"

/*}}}  */
/*{{{  variables */

ATbool run_verbose = ATfalse;

static char myversion[] = "1.5";
static char myarguments[] = "hmvV";

/*}}}  */

/*{{{  static char *ATgetString(ATerm t) */

static char *ATgetString(ATerm t)
{
  assert(t != NULL && ATgetType(t) == AT_APPL);

  return ATgetName(ATgetAFun((ATermAppl) t));
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
  char *buf = NULL;
  FILE *fd;

  *size = getFileSize(fnam);

  if((fd = fopen(fnam, "rb")) == NULL) {
    *size = 0;
    return NULL;
  }

  if((buf = (char *)malloc(*size + 1)) == NULL ) {
    fclose(fd);
    *size = 0;
    return NULL;
  }

  if(fread(buf, 1, *size, fd) != *size) {
    free(buf);
    fclose(fd);
    *size = 0;
    return NULL;
  }

  fclose(fd);
  buf[*size] = '\0';
  return buf ;
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
/*{{{  static ATerm createFilesEqualMessage() */

static ATerm createFilesEqualMessage()
{
  return ATmake("snd-value(equal)");
}

/*}}}  */
/*{{{  static ATerm createFilesDifferentMessage() */

static ATerm createFilesDifferentMessage()
{
  return ATmake("snd-value(different)");
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

    free(absolutePath);
    absolutePath = NULL;
  }

  return ATmake("snd-value(absolute-directories(<term>))", ATreverse(result));
}

/*}}}  */
/*{{{  ATerm remove_file(int cid, char *fileName) */

void remove_file(int cid, char *directory, char *name, char *extension)
{
  char fileName[PATH_LEN];

  sprintf(fileName, "%s%s%s%s", directory, SEP, name, extension);

  remove(fileName);
}

/*}}}  */
/*{{{  ATerm read_text_file(int cid, char *fileName) */

ATerm read_text_file(int cid, char *fileName)
{
  ATerm t;
  char *buf = NULL;
  size_t size;

  buf = readFileContents(fileName, &size);

  if (buf == NULL) {
    t = createErrorMessage(strerror(errno));
  } else {
    t = ATmake("snd-value(file-contents(<str>))", buf);
    free(buf);
  }

  return t;
}

/*}}}  */
/*{{{  ATerm read_term_file(int cid, char *fileName) */

ATerm read_term_file(int cid, char *fileName)
{
  ATerm result, contents;

  contents = ATreadFromNamedFile(fileName);

  if (contents == NULL) {
    result = createErrorMessage(strerror(errno));
  } else {
    result = ATmake("snd-value(file-contents(<term>))", ATBpack(contents));
  }

  return result;
}

/*}}}  */

ATerm pack_term(int cid, ATerm term)
{
  return ATmake("snd-value(term(<term>))", ATBpack(term));
}

ATerm unpack_term(int cid, ATerm term)
{
  return ATmake("snd-value(term(<term>))", ATBunpack(term));
}


/*{{{  ATerm read_packed_term_file(int cid, char *fileName) */
 
ATerm read_packed_term_file(int cid, char *fileName)
{
  ATerm result, contents;
 
  contents = ATreadFromNamedFile(fileName);
 
  if (contents == NULL) {
    result = createErrorMessage(strerror(errno));
  } else {
    result = ATmake("snd-value(file-contents(<term>))", contents);
  }
 
  return result;
}
 
/*}}}  */
/*{{{  ATerm write_text_file(int cid, char *fileName, ATerm content) */

ATerm write_text_file(int cid, char *fileName, ATerm content)
{
  ATermList list = (ATermList) content;
  FILE *file = NULL;
  ATerm message;

  if (!(file = fopen(fileName, "w"))) {
    message = createErrorMessage(strerror(errno));
  }
  else {
    for (; !ATisEmpty(list); list = ATgetNext(list)) {
      ATerm atString = ATgetFirst(list);
      char *string = ATgetName(ATgetAFun((ATermAppl) atString));
      fputs(string, file);
    }

    if (!ferror(file)) {
      message = createSuccessMessage();
    }
    else {
      message = createErrorMessage(strerror(errno));
    }

    fclose(file);
  }

  return message;
}

/*}}}  */
/*{{{  ATerm write_term_file(int cid,  char *fileName, ATerm packedContent) */

ATerm write_term_file(int cid,  char *fileName, ATerm packedContent)
{
  ATerm message;

  ATerm content = ATBunpack(packedContent);

  if (fileName != NULL) {
    FILE *file = NULL;

    if (!(file = fopen(fileName, "w"))) {
      message = createErrorMessage(strerror(errno));
    }
    else {
      if (ATwriteToBinaryFile(content, file)) {
        message = createSuccessMessage();
      }
      else {
	if (ferror(file)) {
	  message = createErrorMessage(strerror(errno));
	}
	else {
	  message = createErrorMessage("Could not write ATerm to file");
	}
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
/*{{{  ATerm write_packed_term_file(int cid,  char *fileName, ATerm packedContent) */

ATerm write_packed_term_file(int cid,  char *fileName, ATerm content)
{
  ATerm message;

  if (fileName != NULL) {
    FILE *file = NULL;

    if (!(file = fopen(fileName, "w"))) {
      message = createErrorMessage(strerror(errno));
    }
    else {
      if (ATwriteToTextFile(content, file)) {
        message = createSuccessMessage();
      }
      else {
	if (ferror(file)) {
	  message = createErrorMessage(strerror(errno));
	}
	else {
	  message = createErrorMessage("Could not write ATerm to file");
	}
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
/*{{{  ATerm exists_file(int cid, char *path, char *name, char *extension) */

ATerm exists_file(int cid, char *fileName)
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
/*{{{  ATerm compare_files(int cid, char *f1, char *f2) */

ATerm compare_files(int cid, char *f1, char *f2)
{
  if (filesEqual(f1, f2)) {
    return createFilesEqualMessage();
  }
  else {
    return createFilesDifferentMessage();
  }
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
/*{{{  void rec_terminate(int cid, ATerm arg) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
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

static void memprof()
{
  read_term_file(0, "/ufs/markvdb/Research/asf/library/sandbox/toolbus/analysis/Meta.snapshot");
}

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
        case 'm':
          ATBinit(argc, argv, &bottomOfStack);
	  memprof();
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
