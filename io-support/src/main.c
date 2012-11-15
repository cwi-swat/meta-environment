#include <assert.h>
#include <ctype.h>
#include <dirent.h>
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
#include <Config.h>
#include <IO.h>

#include "in-output.h"

#define EOS '\0'
#define PATH_SEPARATOR '/'
#define EXTENSION_SEPARATOR '.'
#define TOOL_NAME "in-output"

typedef ATbool (*Writer)(ATerm, FILE *);

ATbool run_verbose = ATfalse;

static char myversion[] = "1.5";
static char myarguments[] = "hvV";

static const char *ATgetString(ATerm t) {
  assert(t != NULL && ATgetType(t) == AT_APPL);

  return ATgetName(ATgetAFun((ATermAppl) t));
}

static ATbool fileExists(const char *fname) {
  struct stat st;
  return stat(fname, &st) != EOF ? ATtrue : ATfalse;
}

static size_t getFileSize(const char *s) {
  struct stat st;
  return (stat((char *)s, &st)!=EOF) ? st.st_size : -1L;
}

static char* tmpFile = NULL;
static int tmpFileLen = 0;
static char* tempFile(const char* path, const char* name, const char* ext) 
{
  int needed = strlen(path) + strlen(name) + strlen(ext) + 1 + 1;

  if (tmpFileLen < needed) {
    tmpFileLen = needed * 2;
    char *tmp = (char*) realloc(tmpFile, tmpFileLen * sizeof(char));
    if (tmp == NULL) {
      ATerror("in-output: out of memory");
      return NULL;
    }
    else {
      tmpFile = tmp;
    }
  }

  snprintf(tmpFile, needed, "%s%c%s%s", path, PATH_SEPARATOR, name, ext);

  return tmpFile;
}

static char *readFileContents(const char *fnam, size_t *size) {
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
  buf[*size] = EOS;
  return buf ;
}

static char* getCwd() {
  int size = _POSIX_PATH_MAX + 1;
  char *tmp = (char*) calloc(size, sizeof(char));

  if (tmp != NULL) {
    while (getcwd(tmp, size) == NULL && errno == ERANGE) {
      size *= 2;
      tmp = (char*) realloc(tmp, size * sizeof(char));

      if (tmp == NULL) {
	ATerror("in-output: out of memory");
	return NULL;
      }
    }
    return tmp;
  }
  else {
    ATerror("in-output: out of memory");
    return NULL;
  }
}

/* Expand a relative path to its absolute equivalent
 *
 * - ATerror upon serious failure (no current directory, no memory)
 * - returns NULL when relative_path could not be expanded
 * - returns calloc(3)-ed pointer containing absolute path otherwise.
 */
static char *expandPath(const char *relative_path) {
  char *absolute_dir = NULL;
  char *current_dir = NULL;

  current_dir = getCwd();

  if (chdir(relative_path) == -1) {
    return NULL;
  }

  absolute_dir = getCwd();

  if (chdir(current_dir) == -1) {
    ATerror("could not chdir(%s): %s\n", current_dir, strerror(errno));
  }

  free(current_dir);

  return absolute_dir;
}

static char *normalizePath(const char *path) {
  char *normalized = (char*) calloc(strlen(path) + 1, sizeof(char)); 
  const char *p;
  char *q; 

  if (normalized == NULL) {
    ATerror("in-output: out of memory");
    return NULL;
  }

  for(p = path, q = normalized; *p != '\0'; p++) {
    if (*p != PATH_SEPARATOR || *(p+1) != PATH_SEPARATOR) {
      *q++ = *p;
    }
  }
  *q = '\0';

  return normalized;
}

static ATerm makeResultMessage(ERR_Summary summary) {
  ATerm result;

  if (summary == NULL) {
    result = ATmake("snd-value(success)");
  }
  else {
    result = ATmake("snd-value(failure(<term>))", ERR_SummaryToTerm(summary));
  }

  return result;
}

static ERR_Summary createSummary(const char *msg, const char *path) {
  ERR_Location location = ERR_makeLocationFile(path);
  ERR_Subject subject = ERR_makeSubjectLocalized(strerror(errno), location);
  ERR_SubjectList subjects = ERR_makeSubjectListSingle(subject);
  ERR_Error error = ERR_makeErrorError(msg, subjects);
  ERR_ErrorList errors = ERR_makeErrorListSingle(error);

  return ERR_makeSummarySummary(TOOL_NAME, path, errors);
}

static ATerm createFileNotFoundMessage() {
  return ATmake("snd-value(file-not-found)");
}

static ATerm createFileFoundMessage(ATermList directories) {
  return ATmake("snd-value(file-found(<term>))", directories);
}

static ATerm createFilesEqualMessage() {
  return ATmake("snd-value(equal)");
}

static ATerm createFilesDifferentMessage() {
  return ATmake("snd-value(different)");
}

ATerm relative_to_absolute(int cid, ATerm paths) {
  CFG_PropertyList relativePaths = CFG_PropertyListFromTerm(paths);
  CFG_PropertyList result = CFG_makePropertyListEmpty();
  ERR_Summary summary = NULL;

  while (!CFG_isPropertyListEmpty(relativePaths)) {
    CFG_Property prop = CFG_getPropertyListHead(relativePaths);
    const char *relativePath = CFG_getPropertyPath(prop);
    char *absolutePath = expandPath(relativePath);

    if (absolutePath != NULL) {
      prop = CFG_setPropertyPath(prop, absolutePath);
      result = CFG_makePropertyListMany(prop, result);
    }
    else {
      summary = createSummary("Unable to expand", relativePath);
      break;
    }

    free(absolutePath);
    absolutePath = NULL;

    relativePaths = CFG_getPropertyListTail(relativePaths);
  }

  if (summary == NULL) {
    /* Found files should be reported in order of the searchPaths */
    return ATmake("snd-value(absolute-directories(<term>))", 
		  CFG_reversePropertyList(result));
  }
  else {
    return makeResultMessage(summary);
  }
}

ATerm remove_file(int cid, const char *path) {
  ERR_Summary summary = NULL;

  if (unlink(path) != 0) {
    summary = createSummary("Failed to remove file", path);
  }

  return makeResultMessage(summary);
}

ATerm copy_file(int cid, const char *srcPath, const char *destPath) {
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

ATerm pack_term(int cid, ATerm term) {
  return ATmake("snd-value(term(<term>))", ATBpack(term));
}

ATerm unpack_term(int cid, ATerm term) {
  return ATmake("snd-value(term(<term>))", ATBunpack(term));
}

ATerm read_text_file(int cid, const char *path) {
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

ATerm read_and_pack_term(int cid, const char *path) {
  ATerm contents = ATreadFromNamedFile(path);

  if (contents == NULL) {
    return makeResultMessage(createSummary("Failed to read term file", path));
  } else {
    return ATmake("snd-value(packed-term(<term>))", ATBpack(contents));
  }
}

ATerm read_term_file(int cid, const char *path) {
  ATerm contents = ATreadFromNamedFile(path);
 
  if (contents == NULL) {
    return makeResultMessage(createSummary("Failed to read packed term file",
					    path));
  } else {
    return ATmake("snd-value(term(<term>))", contents);
  }
}

static ATerm write_file(const char *path, ATerm content, Writer writer) {
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

static ATbool text_list_writer(ATerm content, FILE *f) {
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

ATerm write_text_list(int cid, const char *path, ATerm content) {
  return write_file(path, ATBunpack(content), text_list_writer);
}

ATerm write_term_as_text(int cid, const char *path, ATerm content) {
  return write_file(path, ATBunpack(content), ATwriteToTextFile);
}

ATerm write_in_baf(int cid, const char *path, ATerm content) {
  return write_file(path, content, ATwriteToBinaryFile);
}

ATerm unpack_and_write_in_baf(int cid, const char *path, ATerm content) {
  return write_file(path, ATBunpack(content), ATwriteToBinaryFile);
}

ATerm exists_file(int cid, const char *path) {
  ERR_Summary summary = NULL;

  if (!fileExists(path)) {
    summary = createSummary("No such file", path);
  }
  
  return makeResultMessage(summary);
}

ATerm list_files(int cid, const char *path, const char *extension) {
  char *filename;
  DIR* dir;
  struct dirent* entry;
  ATermList files = ATempty;

  dir = opendir(path);
  if (dir != NULL) {
    while ((entry = readdir(dir))) {
      int length = strlen(entry->d_name) - strlen(extension);
      if (entry->d_name && strcmp(&(entry->d_name)[length], extension) == 0) {
	filename = tempFile(path, entry->d_name, "");
	files = ATinsert(files, 
			 (ATerm) 
			 ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)));
      }
    }  
  }

  return ATmake("snd-value(file-list(<term>))", files);
}

ATerm find_file(int cid, ATerm paths, const char *name, const char *extension) {
  CFG_PropertyList searchPaths = CFG_PropertyListFromTerm(paths);
  ATermList directories = ATempty;
 
  for ( ; !CFG_isPropertyListEmpty(searchPaths); 
       searchPaths = CFG_getPropertyListTail(searchPaths)) {
    CFG_Property path = CFG_getPropertyListHead(searchPaths);
    const char *pathString = CFG_getPropertyPath(path);
    char *filename = tempFile(pathString, name, extension);
      
    if (fileExists(filename)) {
      directories = ATinsert(directories, 
			     (ATerm)
			     ATmakeAppl(ATmakeAFun(pathString, 0, ATtrue)));
    }
  }

  if (ATisEmpty(directories)) {
    return createFileNotFoundMessage();
  }
  else {
    return createFileFoundMessage(ATreverse(directories));
  }
}

ATerm get_relative_filename(int cid, ATerm paths, const char *path, const char *extension) {
  ATerm result = NULL;
  CFG_PropertyList searchPaths = CFG_PropertyListFromTerm(paths);

  assert(path != NULL);

  while (!CFG_isPropertyListEmpty(searchPaths) && !result) {
    CFG_Property searchPath = CFG_getPropertyListHead(searchPaths);
    const char *pathString = CFG_getPropertyPath(searchPath);
    char *normalizedSearchPath = normalizePath(pathString);
    char *normalizedPath = normalizePath(path);

    if (strncmp(normalizedSearchPath, normalizedPath, strlen(normalizedSearchPath)) == 0) {
      char *copy;
      char *extension;

      copy = strdup(normalizedPath + strlen(normalizedSearchPath) + 1);
      assert(copy != NULL);

      extension = strrchr(copy, EXTENSION_SEPARATOR);
      if (extension != NULL) {
        *extension = EOS;
      }
      result = ATmake("filename(<str>,<str>)", normalizedSearchPath, copy);
      free(copy);
    }

    free(normalizedSearchPath);
    free(normalizedPath);
    searchPaths = CFG_getPropertyListTail(searchPaths);
  }

  if (!result) {
    result = ATmake("filename(<str>,<str>)", "", "");
  }

  return ATmake("snd-value(<term>)", result);
}

ATerm compare_files(int cid, const char *f1, const char *f2) {
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

ATerm get_filename(int cid, const char *directory, const char *name, const char *extension) {
  ATerm result;
  char *buf;
  int directoryLen;

  buf = strdup(directory);
  assert(buf != NULL);

  directoryLen = strlen(buf);

  if (directoryLen > 0 && buf[directoryLen-1] == PATH_SEPARATOR) {
    buf[directoryLen-1] = '\0';
  }

  result = ATmake("snd-value(filename(<str>))", tempFile(buf, name, extension));

  free(buf);

  return result;
}

ATerm get_path_directory(int conn, const char *path) {
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

ATerm get_path_filename(int conn, const char *path) {
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
  if (filename != NULL) {
    result = ATmake("filename(<str>)", ++filename);
  }
  else {
    result = ATmake("filename(<str>)", copy);
  }

  free(copy);
  
  return ATmake("snd-value(<term>)", result);
}

ATerm get_path_extension(int conn, const char *path) {
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

ATerm make_file(int cid, const char *directory) {
  char *copy, *segment, *segment_end;
  char *extension = NULL;
  ATbool absolutePath = ATfalse;
  IO_File file;
  IO_Path path;
  IO_SegmentList segmentList = IO_makeSegmentListEmpty();
  ATerm result = NULL;

  assert(directory != NULL);

  copy = strdup(directory);
  assert(copy != NULL);

  segment = copy;

  for (segment_end = copy; *segment_end; segment_end++) {
    if (*segment_end == PATH_SEPARATOR) {
      if (segment_end == copy) {
	absolutePath = ATtrue;
      } else {
	*segment_end = EOS;
	segmentList = IO_appendSegmentList(segmentList, 
					   IO_makeSegmentSegment(segment));
      }
      segment = segment_end + 1;
    }
  }

  segment_end = strrchr(segment, EXTENSION_SEPARATOR);
  if (segment_end != NULL) {
    *segment_end = EOS;
    extension = ++segment_end;
  }

  if (absolutePath == ATtrue) {
    path = IO_makePathAbsolute(segmentList);
  }
  else {
    path = IO_makePathRelative(segmentList);
  }

  if (extension != NULL) {
    file = IO_makeFileFile(path, segment, extension);
  } else {
    file = IO_makeFileFile(path, segment, "");
  }
  result = ATmake("file(<term>)", IO_FileToTerm(file));

  free(copy);
  
  return ATmake("snd-value(<term>)", result);
}

ATerm get_file_path(int cid, ATerm file) {
  int pathLen = _POSIX_PATH_MAX + 1;
  char *path = (char*) calloc(pathLen, sizeof(char));
  IO_File io_file = IO_FileFromTerm(file);
  IO_Path io_path = IO_getFilePath(io_file);
  ATbool absolute = IO_isPathAbsolute(io_path);
  IO_SegmentList segments = IO_getPathList(io_path);
  ATerm result;

  if (path == NULL) {
    ATerror("in-output: out of memory");
    return NULL;
  }

  if (absolute) {
    snprintf(path, 1, "%c", PATH_SEPARATOR);
  }

  while (!IO_isSegmentListEmpty(segments)) {
    IO_Segment segment = IO_getSegmentListHead(segments);
    const char* name = IO_getSegmentName(segment);
    int needed = strlen(path) + strlen(name) + 1 + 1;

    if (pathLen < needed) {
      char *tmp = NULL;
      pathLen = needed * 3;
      tmp = (char*) realloc(path, pathLen * sizeof(char));
      if (tmp == NULL) {
	ATerror("in-output: out of memory");
	return NULL;
      }
      else {
	path = tmp;
      }
    }
    
    snprintf(path, needed, "%s%s%c", path, name, PATH_SEPARATOR);
    segments = IO_getSegmentListTail(segments);
  }

  result = ATmake("file-path(<str>)", path);

  return ATmake("snd-value(<term>)", result);
}

ATerm get_file_name(int cid, ATerm file) {
  IO_File io_file = IO_FileFromTerm(file);
  ATerm result = ATmake("file-name(<str>)", IO_getFileName(io_file));

  return ATmake("snd-value(<term>)", result);
}

ATerm get_file_extension(int cid, ATerm file) {
  IO_File io_file = IO_FileFromTerm(file);
  ATerm result = ATmake("file-extension(<str>)", IO_getFileExtension(io_file));

  return ATmake("snd-value(<term>)", result);
}

ATerm get_file_size(int cid, const char* filename) {
  ATerm result = ATmake("file-size(<int>)", getFileSize(filename));

  return ATmake("snd-value(<term>)", result);  
}

void rec_terminate(int cid, ATerm arg) {
  exit(0);
}

static void usage(const char *prg, ATbool is_err) {
  ATwarning(
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-h              display help information (usage)\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    prg, myversion);
  exit(is_err ? 1 : 0);
}

static void version(const char *prg) {
  ATwarning("%s v%s\n", prg, myversion);
  exit(1);
}

int main(int argc, char *argv[]) {
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
    CFG_initConfigApi();
    IO_initIOApi();

    cid = ATBconnect(NULL, NULL, -1, in_output_handler);
    ATBeventloop();
  }

  return 0;
}

