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

#define EOS '\0'
#define PATH_LEN (_POSIX_PATH_MAX)
#define PATH_SEPARATOR '/'
#define EXTENSION_SEPARATOR '.'

/*}}}  */
/*{{{  variables */

ATbool run_verbose = ATfalse;

static char myversion[] = "1.5";
static char myarguments[] = "hvV";

/*}}}  */

/*{{{  static const char *ATgetString(ATerm t) */

static const char *ATgetString(ATerm t)
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
/*{{{  static char *readFileContents(const char *fnam, size_t *size) */

static char *readFileContents(const char *fnam, size_t *size)
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

  for (; !ATisEmpty(relativePaths); relativePaths = ATgetNext(relativePaths)) {
    const char *relativePath = ATgetString(ATgetFirst(relativePaths));
    char *absolutePath = expandPath(relativePath);

    if (absolutePath != NULL) {
      result = ATinsert(result, ATmake("<str>", absolutePath));
    }
    else {
      ATwarning("Unable to expand %s, skipping...\n", relativePath);
    }

    free(absolutePath);
    absolutePath = NULL;
  }

  // Found files should be reported in order of the searchPaths
  return ATmake("snd-value(absolute-directories(<term>))", ATreverse(result));
}

/*}}}  */
/*{{{  void remove_file(int cid, const char *directory, const char *name, const char *extension) */

void remove_file(int cid, const char *directory, const char *name, const char *extension)
{
  char fileName[PATH_LEN];

  sprintf(fileName, "%s%c%s%s", directory, PATH_SEPARATOR, name, extension);

  unlink(fileName);
}

/*}}}  */
/*{{{  ATerm read_text_file(int cid, const char *fileName) */

ATerm read_text_file(int cid, const char *fileName)
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
/*{{{  ATerm read_term_file(int cid, const char *fileName) */

ATerm read_term_file(int cid, const char *fileName)
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

/*{{{  ATerm pack_term(int cid, ATerm term) */

ATerm pack_term(int cid, ATerm term)
{
  return ATmake("snd-value(term(<term>))", ATBpack(term));
}

/*}}}  */
/*{{{  ATerm unpack_term(int cid, ATerm term) */

ATerm unpack_term(int cid, ATerm term)
{
  return ATmake("snd-value(term(<term>))", ATBunpack(term));
}

/*}}}  */

/*{{{  ATerm read_packed_term_file(int cid, const char *fileName) */

ATerm read_packed_term_file(int cid, const char *fileName)
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
/*{{{  ATerm write_text_file(int cid, const char *fileName, ATerm content) */

ATerm write_text_file(int cid, const char *fileName, ATerm content)
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
      const char *string = ATgetName(ATgetAFun((ATermAppl) atString));
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
/*{{{  ATerm write_term_file(int cid, const char *fileName, ATerm packedContent) */

ATerm write_term_file(int cid, const char *fileName, ATerm packedContent)
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
/*{{{  ATerm write_packed_term_file(int cid, const char *fileName, ATerm content) */

ATerm write_packed_term_file(int cid, const char *fileName, ATerm content)
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
/*{{{  ATerm exists_file(int cid, const char *fileName) */

ATerm exists_file(int cid, const char *fileName)
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
/*{{{  ATerm find_file(int cid, ATerm paths, const char *name, const char *extension) */

ATerm find_file(int cid, ATerm paths, const char *name, const char *extension)
{
  char filename[PATH_LEN];
  ATermList searchPaths = (ATermList) paths;
  ATermList directories = ATempty;
 
  for (; !ATisEmpty(searchPaths); searchPaths = ATgetNext(searchPaths)) {
    ATerm path = ATgetFirst(searchPaths);
    const char *pathString = ATgetString(path);
    sprintf(filename, "%s%c%s%s", pathString, PATH_SEPARATOR, name, extension);

    if (fileExists(filename)) {
      directories = ATinsert(directories, path);
    }
  }

  if (ATisEmpty(directories)) {
    return createFileNotFoundMessage();
  }
  else {
    return createFileFoundMessage(ATreverse(directories));
  }
}

/*}}}  */
/*{{{  ATerm compare_files(int cid, const char *f1, const char *f2) */

ATerm compare_files(int cid, const char *f1, const char *f2)
{
  if (filesEqual(f1, f2)) {
    return createFilesEqualMessage();
  }
  else {
    return createFilesDifferentMessage();
  }
}

/*}}}  */
/*{{{  ATerm get_filename(int cid, const char *directory, const char *name, const char *extension) */

ATerm get_filename(int cid, const char *directory, const char *name, const char *extension)
{
  ATerm result;
  char *buf;
  char fileName[PATH_LEN];
  int directoryLen;

  buf = strdup(directory);
  assert(buf != NULL);

  directoryLen = strlen(buf);

  if (directoryLen > 0 && buf[directoryLen-1] == PATH_SEPARATOR) {
    buf[directoryLen-1] = '\0';
  }

  sprintf(fileName, "%s%c%s%s", buf, PATH_SEPARATOR, name, extension);

  result = ATmake("snd-value(filename(<str>))", fileName);

  free(buf);

  return result;
}

/*}}}  */
/*{{{  ATerm decons_filename(int conn, const char *filename, const char *extension) */

ATerm decons_filename(int conn, const char *filename, const char *extension)
{
  int filenameLength = strlen(filename);
  int extensionLength = strlen(extension);
  ATerm result;
  char *buf;
  char *save;
  const char *path;
  char *p;

  buf = strdup(filename);
  assert(buf != NULL);
  save = buf;
  
  p = buf + filenameLength - extensionLength;
  if (strncmp(p, extension, extensionLength) == 0) {
    *p = '\0';
  }
  else {
    extension = "";
  }

  p = strrchr(buf, '/'); /* TODO: separator is hardcoded */
  if (p != NULL) {
    path = buf;
    *p++ = '\0';
    buf = p;
  }
  else {
    path = "";
  }

  result = ATmake("snd-value(file-name(<str>,<str>,<str>))",
		path, buf, extension);

  free(save);

  return result;
}

/*}}}  */

/*{{{  ATerm get_path_directory(int conn, const char *path) */

ATerm get_path_directory(int conn, const char *path)
{
  char *copy;
  char *directory;
  ATerm result;

  assert(path != NULL);

  copy = strdup(path);
  assert(copy != NULL);

  directory = strrchr(copy, PATH_SEPARATOR);
  if (directory != NULL) {
    directory++; /* include trailing '/' */
    *directory = EOS;
    result = ATmake("directory(<str>)", copy);
    free(copy);
  }
  else {
    result = ATmake("directory(<str>)", "");
  }

  return ATmake("snd-value(<term>)", result);
}

/*}}}  */
/*{{{  ATerm get_path_filename(int conn, const char *path) */

ATerm get_path_filename(int conn, const char *path)
{
  char *filename;
  ATerm result;

  assert(path != NULL);

  filename = strrchr(path, PATH_SEPARATOR);
  if (filename != NULL) {
    char *copy;
    char *extension;

    copy = strdup(filename + 1);
    assert(copy != NULL);

    extension = strrchr(copy, EXTENSION_SEPARATOR);
    if (extension != NULL) {
      *extension = EOS;
    }
    result = ATmake("filename(<str>)", copy);
    free(copy);
  }
  else {
    result = ATmake("filename(<str>)", "");
  }

  return ATmake("snd-value(<term>)", result);
}

/*}}}  */
/*{{{  ATerm get_path_extension(int conn, const char *path) */

ATerm get_path_extension(int conn, const char *path)
{
  const char *extension;

  assert(path != NULL);

  extension = strrchr(path, EXTENSION_SEPARATOR);

  if (extension == NULL) {
    return ATmake("snd-value(extension(\"\"))");
  }
  else {
    return ATmake("snd-value(extension(<str>))", extension);
  }
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm arg) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

/*}}}  */

/*{{{  static void usage(const char *prg, ATbool is_err) */

static void usage(const char *prg, ATbool is_err)
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
/*{{{  static void version(const char *prg) */

static void version(const char *prg)
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
