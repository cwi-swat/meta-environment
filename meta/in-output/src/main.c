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
#include <Error.h>

#include "in-output.tif.h"

/*}}}  */
/*{{{  defines */

#define EOS '\0'
#define PATH_LEN (_POSIX_PATH_MAX)
#define PATH_SEPARATOR '/'
#define EXTENSION_SEPARATOR '.'
#define TOOL_NAME "in-output"

/*}}}  */
/*{{{  typedefs */

typedef ATbool (*Writer)(ATerm, FILE *);

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

/*{{{  static ATerm makeResultMessage(ERR_Summary summary) */

static ATerm makeResultMessage(ERR_Summary summary)
{
  ATerm result;

  if (summary == NULL) {
    result = ATmake("snd-value(success)");
  }
  else {
    result = ATmake("snd-value(failure(<term>))", ERR_SummaryToTerm(summary));
  }

  return result;
}

/*}}}  */
/*{{{  static ERR_Summary createSummary(const char *msg, const char *path) */

static ERR_Summary createSummary(const char *msg, const char *path)
{
  ERR_Location location = ERR_makeLocationFile(path);
  ERR_Subject subject = ERR_makeSubjectLocalized(strerror(errno), location);
  ERR_SubjectList subjects = ERR_makeSubjectListSingle(subject);
  ERR_Error error = ERR_makeErrorError(msg, subjects);
  ERR_ErrorList errors = ERR_makeErrorListSingle(error);

  return ERR_makeSummarySummary(TOOL_NAME, path, errors);
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
  ERR_Summary summary = NULL;

  while (!ATisEmpty(relativePaths)) {
    const char *relativePath = ATgetString(ATgetFirst(relativePaths));
    char *absolutePath = expandPath(relativePath);

    if (absolutePath != NULL) {
      result = ATinsert(result, ATmake("<str>", absolutePath));
    }
    else {
      summary = createSummary("Unable to expand", relativePath);
      break;
    }

    free(absolutePath);
    absolutePath = NULL;

    relativePaths = ATgetNext(relativePaths);
  }

  if (summary == NULL) {
    /* Found files should be reported in order of the searchPaths */
    return ATmake("snd-value(absolute-directories(<term>))", ATreverse(result));
  }
  else {
    return makeResultMessage(summary);
  }
}

/*}}}  */
/*{{{  ATerm remove_file(int cid, const char *path) */

ATerm remove_file(int cid, const char *path)
{
  ERR_Summary summary = NULL;

  if (unlink(path) != 0) {
    summary = createSummary("Failed to remove file", path);
  }

  return makeResultMessage(summary);
}

/*}}}  */
/*{{{  ATerm copy_file(int cid, const char *srcPath, const char *destPath) */

ATerm copy_file(int cid, const char *srcPath, const char *destPath)
{
  size_t size;
  char *contents;
  ERR_Summary summary = NULL;

  contents = readFileContents(srcPath, &size);
  if (contents == NULL) {
    summary = createSummary("Failed to read during copy", srcPath);
  }
  else {
    FILE *f = fopen(destPath, "w");
    if (f == NULL) {
      summary = createSummary("Failed to open destination file during copy",
			      destPath);
    }
    else {
      if (fputs(contents, f) == EOF) {
	summary = createSummary("Failed to write during copy", destPath);
      }
      fclose(f);
    }
    free(contents);
  }

  return makeResultMessage(summary);
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

/*{{{  ATerm read_text_file(int cid, const char *path) */

ATerm read_text_file(int cid, const char *path)
{
  char *contents = NULL;
  size_t size;

  contents = readFileContents(path, &size);

  if (contents == NULL) {
    return makeResultMessage(createSummary("Failed to read text file", path));
  } else {
    ATerm result = ATmake("snd-value(file-contents(<str>))", contents);
    free(contents);
    return result;
  }
}

/*}}}  */
/*{{{  ATerm read_and_pack_term(int cid, const char *path) */

ATerm read_and_pack_term(int cid, const char *path)
{
  ATerm contents = ATreadFromNamedFile(path);

  if (contents == NULL) {
    return makeResultMessage(createSummary("Failed to read term file", path));
  } else {
    return ATmake("snd-value(packed-term(<term>))", ATBpack(contents));
  }
}

/*}}}  */
/*{{{  ATerm read_term_file(int cid, const char *path) */

ATerm read_term_file(int cid, const char *path)
{
  ATerm contents = ATreadFromNamedFile(path);
 
  if (contents == NULL) {
    return makeResultMessage(createSummary("Failed to read packed term file",
					    path));
  } else {
    return ATmake("snd-value(term(<term>))", contents);
  }
}

/*}}}  */

/*{{{  static ERR_Summary write_file(const char *path, ATerm content, Writer writer) */

static ATerm write_file(const char *path, ATerm content, Writer writer)
{
  FILE *file;
  ERR_Summary summary = NULL;

  file = fopen(path, "w");
  if (file == NULL) {
    summary = createSummary("Failed to open file for writing", path);
  }
  else {
    if (!writer(content, file)) {
      summary = createSummary("Failed to write", path);
    }

    if (fclose(file) != 0) {
      if (summary == NULL) {
	summary = createSummary("Failed to close text file", path);
      }
    }
  }

  return makeResultMessage(summary);
}

/*}}}  */
/*{{{  static ATbool text_list_writer(ATerm content, FILE *f) */

static ATbool text_list_writer(ATerm content, FILE *f)
{
  ATermList list = (ATermList) content;
  while (!ATisEmpty(list)) {
    const char *str = ATgetString(ATgetFirst(list));
    if (fputs(str, f) == EOF) {
      return ATfalse;
    }
    list = ATgetNext(list);
  }
  return ATtrue;
}

/*}}}  */

/*{{{  ATerm write_text_list(int cid, const char *path, ATerm content) */

ATerm write_text_list(int cid, const char *path, ATerm content)
{
  return write_file(path, ATBunpack(content), text_list_writer);
}

/*}}}  */
/*{{{  ATerm write_term_as_text(int cid, const char *path, ATerm content) */

ATerm write_term_as_text(int cid, const char *path, ATerm content)
{
  return write_file(path, ATBunpack(content), ATwriteToTextFile);
}

/*}}}  */
/*{{{  ATerm write_in_baf(int cid, const char *path, ATerm content) */

ATerm write_in_baf(int cid, const char *path, ATerm content)
{
  return write_file(path, content, ATwriteToBinaryFile);
}

/*}}}  */
/*{{{  ATerm unpack_and_write_in_baf(int cid, const char *path, ATerm content) */

ATerm unpack_and_write_in_baf(int cid, const char *path, ATerm content)
{
  return write_file(path, ATBunpack(content), ATwriteToBinaryFile);
}

/*}}}  */

/*{{{  ATerm exists_file(int cid, const char *path) */

ATerm exists_file(int cid, const char *path)
{
  ERR_Summary summary = NULL;

  if (!fileExists(path)) {
    summary = createSummary("No such file", path);
  }
  
  return makeResultMessage(summary);
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

/*{{{  ATerm get_relative_filename(int cid, ATerm paths, const char *path, const char *extension) */

ATerm get_relative_filename(int cid, ATerm paths, const char *path, const char *extension)
{
  ATerm result = NULL;
  ATermList searchPaths = (ATermList) paths;

  assert(path != NULL);

  while (!ATisEmpty(searchPaths) && !result) {
    ATerm searchPath = ATgetFirst(searchPaths);
    const char *pathString = ATgetString(searchPath);
    if (strncmp(pathString, path, strlen(pathString)) == 0) {
      char *copy;
      char *extension;

      copy = strdup(path + strlen(pathString) + 1);
      assert(copy != NULL);

      extension = strrchr(copy, EXTENSION_SEPARATOR);
      if (extension != NULL) {
        *extension = EOS;
      }
      result = ATmake("filename(<str>)", copy);
      free(copy);
    }
    searchPaths = ATgetNext(searchPaths);
  }

  if (!result) {
    result = ATmake("filename(<str>)", "");
  }

  return ATmake("snd-value(<term>)", result);
}

/*}}}  */

/*{{{  ATerm compare_files(int cid, const char *f1, const char *f2) */

ATerm compare_files(int cid, const char *f1, const char *f2)
{
  struct stat st1;
  struct stat st2;

  if (stat(f1, &st1) != 0) {
    return makeResultMessage(createSummary("Cannot stat", f1));
  }

  if (stat(f2, &st2) != 0) {
    return makeResultMessage(createSummary("Cannot stat", f2));
  }

  if (st1.st_ino == st2.st_ino) {
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
  char path[PATH_LEN];
  int directoryLen;

  buf = strdup(directory);
  assert(buf != NULL);

  directoryLen = strlen(buf);

  if (directoryLen > 0 && buf[directoryLen-1] == PATH_SEPARATOR) {
    buf[directoryLen-1] = '\0';
  }

  sprintf(path, "%s%c%s%s", buf, PATH_SEPARATOR, name, extension);

  result = ATmake("snd-value(filename(<str>))", path);

  free(buf);

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
  char *copy;
  char *extension;
  char *filename;
  ATerm result = NULL;

  assert(path != NULL);

  copy = strdup(path);
  assert(copy != NULL);

  extension = strrchr(copy, EXTENSION_SEPARATOR);
  if (extension != NULL) {
    *extension = EOS;
  }

  filename = strrchr(copy, PATH_SEPARATOR);
  result = ATmake("filename(<str>)", ++filename);

  free(copy);
  
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
    ERR_initErrorApi();
    cid = ATBconnect(NULL, NULL, -1, in_output_handler);
    ATBeventloop();
  }

  return 0;
}

/*}}}  */
