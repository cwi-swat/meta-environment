/* $Id$ */

#include <PTMEPT-utils.h>
#include "builtin-common.h"
#include <sglrInterface.h>
#include <inputStringBuilder.h>
#include <filterOptions.h>
#include <asc-support-me.h>
#include <Library.h>
#include <sys/stat.h>
#include <aterm2.h>
#include <Error-utils.h>
#include <errno.h>

#define INIT_BUF_SIZE 12000
#define INCR_BUF_SIZE 24000
#define READ_BLOCK_SIZE 512
#define BUFFER_COLLECT_SIZE 1256000

static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes);
static PT_Tree unparse_to_bytes(PT_Tree tree);


static char* getFilename(PT_Tree str) {
  ATerm aterm = ATparse(PT_yieldTreeToString(str, ATfalse));
  return ATgetName(ATgetAFun((ATermAppl) aterm));
}


static char* getCommand(PT_Tree str) {
  ATerm aterm = ATparse(PT_yieldTreeToString(str, ATfalse));
  return ATgetName(ATgetAFun((ATermAppl) aterm));
}


static CO_Summary makeGeneralError(const char *msg) {
  ERR_Error error = ERR_makeErrorError(msg, ERR_makeSubjectListEmpty());
  ERR_ErrorList list = ERR_makeErrorListSingle(error);
  ERR_Summary summary = ERR_makeSummarySummary("asf-builtins","asf-builtins",
					       list);


  return (CO_Summary) ERR_liftSummary(summary);
}


/*static CO_Summary makeParseError(ATerm t) {
  ERR_Error error = ERR_ErrorFromTerm(t);
  ERR_Summary summary = ERR_makeSummarySummary("asf-builtins","asf-builtins",
					       ERR_makeErrorListSingle(error));

  return (CO_Summary) ERR_liftSummary(summary);
}*/


static PT_Tree make_natcon(int value) {
  char str[100];
  sprintf(str, "%d", value);
  return (PT_Tree) CO_makeNatConLexToCf(CO_makeLexNatConDigits(str));
}


static CO_Bytes make_bytes(const char *value) {
  int len = strlen(value);
  int i;
  CO_LexByteList list = CO_makeLexByteListEmpty();

  for ( i = len - 1; i >= 0; i--) {
    CO_LexByte byte = CO_makeLexByteByte(value[i]);
    list = CO_makeLexByteListMany(byte, list);
  }

  return CO_makeBytesLexToCf(CO_makeLexBytesBytes(list));
}


static char* getSort(PT_Symbol type) {
  /* return "Boolean" for 
   * cf(parameterized-sort("ParseResult",[sort("Boolean")]))
   */

  if (PT_isSymbolCf(type)) {
    type = PT_getSymbolSymbol(type);
    
    if (PT_isSymbolParameterizedSort(type)) {
      PT_Symbols args = PT_getSymbolParameters(type);

      if (PT_hasSymbolsHead(args)) {
	type = PT_getSymbolsHead(args);

	if (PT_isSymbolSort(type)) {
	  return PT_getSymbolString(type);
	}
      }
    }
  }

  return NULL;
}

static ERR_Error setFile(ERR_Error error, const char* filename)
{
  ERR_SubjectList result = ERR_makeSubjectListEmpty();
  ERR_SubjectList subjects = ERR_getErrorList(error);

  while (!ERR_isSubjectListEmpty(subjects)) {
    ERR_Subject subject = ERR_getSubjectListHead(subjects);
    ERR_Location location;
    if (ERR_isSubjectLocalized(subject)) {
      ERR_Area area;
      location = ERR_getSubjectLocation(subject);
      area = ERR_getLocationArea(location);
      location = ERR_makeLocationAreaInFile(filename, area);
      subject = ERR_setSubjectLocation(subject, location);
    }
    else {
      char *description = ERR_getSubjectDescription(subject);
      location = ERR_makeLocationFile(filename);
      subject = ERR_makeSubjectLocalized(description, location);
    }
    result = ERR_makeSubjectListMany(subject, result);
    subjects = ERR_getSubjectListTail(subjects);
  }

  return ERR_setErrorList(error, ERR_reverseSubjectList(result));
}

static PT_Tree parse_result(const char *sort, PT_ParseTree pt, PT_Tree posFile, ATbool pos) {
  CO_OptLayout l = CO_makeOptLayoutAbsent();
  PT_Symbol type = PT_makeSymbolSort(sort);
  CO_Summary error;

  if (pt == NULL) {
    ERR_Summary parseErrorSummary = SGLR_getErrorSummary();

    if (posFile != NULL) {
      const char* name = getFilename(posFile);
      ERR_ErrorList list = ERR_getSummaryList(parseErrorSummary);
      ERR_Error error = setFile(ERR_getErrorListHead(list), name);
      list = ERR_makeErrorListMany(error, ERR_getErrorListTail(list));
      parseErrorSummary = ERR_setSummaryList(parseErrorSummary, list);
    }

    if (ERR_isValidSummary(parseErrorSummary)) {
      error = (CO_Summary)ERR_liftSummary(parseErrorSummary);
      return (PT_Tree) CO_makeParsetreeXFailure((ATerm) type, l, l, error, l);
    }
    else {
      error = makeGeneralError( "result is not a valid parse tree, or error summary ");
      return (PT_Tree) CO_makeParsetreeXFailure((ATerm) type, l,l, error,l);
    }
  }

  if (PT_isValidParseTree(pt)) {
    int ambs = PT_getParseTreeAmbCnt(pt);
    PT_Tree tree;
    PT_Tree before;
    PT_Tree after;

    if (pos) {
      const char* name = getFilename(posFile);
      pt = PT_addParseTreePosInfo(name, pt);
    }

    tree = PT_getParseTreeTree(pt);

    if (PT_isValidTree(tree)) {
      if (PT_isTreeAmb(tree)) {
        error = makeGeneralError("parse tree is ambiguous at the top ");
        return (PT_Tree) CO_makeParsetreeXFailure((ATerm) type, l,l, error,l);
      }
      else if (PT_isTreeAppl(tree)) {
        before = PT_getParseTreeLayoutBeforeTree(pt);
        after = PT_getParseTreeLayoutAfterTree(pt);

        return (PT_Tree)
          CO_makeParsetreeXSuccess((ATerm) PT_makeSymbolCf(type), 
              (ATerm) type,
              l, l,
              (CO_Bytes) unparse_to_bytes(before),
              l, l,
              CO_makeXCast((ATerm) tree),
              l, l, 
              (CO_Bytes) unparse_to_bytes(after),
              l, l,
              (CO_NatCon) make_natcon(ambs),
              l);
      }
      else {
        error = makeGeneralError( "result is not a valid parse tree -- top node is cyclic or a char ");
        return (PT_Tree) CO_makeParsetreeXFailure((ATerm) type, l,l, error,l);
      }
    }
    else {
      error = makeGeneralError( "result is not a valid tree ");
      return (PT_Tree) CO_makeParsetreeXFailure((ATerm) type, l,l, error,l);
    }
  }
  else {
    error = makeGeneralError( "result is not a valid parse tree ");
    return (PT_Tree) CO_makeParsetreeXFailure((ATerm) type, l,l, error,l);
  }

}


static PT_Tree parse_file(PT_Symbol type, PT_Tree file, ATbool pos) {
  CO_OptLayout l = CO_makeOptLayoutAbsent();
  char *sort = getSort(type);
  char *filename = getFilename(file);
  InputString inputString;

  if (sort == NULL) {
    return  (PT_Tree) CO_makeParsetreeXFailure((ATerm) PT_makeSymbolSort(sort),
        l,l,
        makeGeneralError("complex symbols are not supported"),
        l);
  }

  if (loadParseTable()) {
    SGLR_initialize(); /* TODO: Factor this out so that it is only done once.*/
    inputString = IS_createInputStringFromFile(filename);
    FLT_setSelectTopNonterminalFlag(ATtrue);
    FLT_setTopNonterminal(sort);
    SGLR_resetErrorSummary();
    PT_ParseTree result = SGLR_parse(inputString, getParseTableID());
    return parse_result(sort, result, file, pos);
  }


  return (PT_Tree) CO_makeParsetreeXFailure((ATerm) PT_makeSymbolSort(sort), l,l,
					     makeGeneralError(
					      "no parsetable available"),
					     l);
}


PT_Tree ASFE_parse_file_pos_info(PT_Symbol type, PT_Tree file) {
  return parse_file(type, file, ATtrue);
}

PT_Tree ASFE_parse_file(PT_Symbol type, PT_Tree file) {
  return parse_file(type, file, ATfalse);
}

PT_Tree ASC_parse_file_pos_info(ATerm type, ATerm aterm) {
  PT_Tree file = muASFToTree(aterm);

  return parse_file((PT_Symbol) type, file, ATtrue);
}

PT_Tree ASC_parse_file(ATerm type, ATerm aterm) {
  PT_Tree file = muASFToTree(aterm);

  return parse_file((PT_Symbol) type, file, ATfalse);
}


static PT_Tree parse_bytes(PT_Symbol type, PT_Tree bytes, PT_Tree file, ATbool pos) {
  CO_OptLayout l = CO_makeOptLayoutAbsent();
  const char *sort = getSort(type);
  InputString inputString;

  if (sort == NULL) {
    return  (PT_Tree) CO_makeParsetreeXFailure((ATerm) PT_makeSymbolSort(sort), l,l,
        makeGeneralError("complex symbols are not supported"),
        l);
  }

  if (loadParseTable()) {
    SGLR_initialize(); /* TODO: Factor this out so that it is only done once.*/
    inputString = IS_createInputStringFromString((const unsigned char *)PT_yieldTreeToString(bytes, ATfalse));
    FLT_setSelectTopNonterminalFlag(ATtrue);
    FLT_setTopNonterminal(sort);
    SGLR_resetErrorSummary();
  
    PT_ParseTree result = SGLR_parse(inputString, getParseTableID());
    return parse_result(sort, result, file, pos);
  }

  return (PT_Tree) CO_makeParsetreeXFailure((ATerm) PT_makeSymbolSort(sort), l,l,
		     makeGeneralError("no parsetable available"),
		     l);
}

PT_Tree ASFE_parse_bytes_pos_info(PT_Symbol type, PT_Tree bytes, PT_Tree file) {
  return parse_bytes(type, bytes, file, ATtrue);
}


PT_Tree ASC_parse_bytes_pos_info(ATerm type, ATerm aterm, ATerm file) {
  PT_Tree bytes = muASFToTree(aterm);
  PT_Tree name = muASFToTree(file);

  return parse_bytes((PT_Symbol) type, bytes, name, ATtrue);
}

PT_Tree ASFE_parse_bytes(PT_Symbol type, PT_Tree bytes) {
  return parse_bytes(type, bytes, NULL, ATfalse);
}


PT_Tree ASC_parse_bytes(ATerm type, ATerm aterm) {
  PT_Tree bytes = muASFToTree(aterm);

  return parse_bytes((PT_Symbol) type, bytes, NULL, ATfalse);
}


static PT_Tree unparse_to_bytes(PT_Tree tree) {
  return (PT_Tree) make_bytes(PT_yieldTreeToString(tree, ATfalse));
}


PT_Tree ASFE_unparse_to_bytes(PT_Symbol type, PT_Tree tree) {
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  return (PT_Tree)
        CO_makeReadSuccess(l,l,(CO_Bytes) unparse_to_bytes(tree),l);
}


PT_Tree ASC_unparse_to_bytes(ATerm type, ATerm input) {
  PT_Tree tree = muASFToTree(input);
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  return (PT_Tree) CO_makeReadSuccess(l,l,(CO_Bytes) unparse_to_bytes(tree),l);
}


static PT_Tree unparse_to_file(PT_Tree file, PT_Tree tree) {
  PT_Tree bytes = unparse_to_bytes(tree);
  return write_bytes_to_file(file, bytes);
}


PT_Tree ASFE_unparse_to_file(PT_Symbol type, PT_Tree file, PT_Tree tree) {
  return unparse_to_file(file, tree);
}


PT_Tree ASC_unparse_to_file(ATerm type, ATerm afile, ATerm input) {
  PT_Tree file = muASFToTree(afile);
  PT_Tree tree = muASFToTree(input);

  return unparse_to_file(file, tree);
}


static PT_Tree read_term_from_file(PT_Symbol type, PT_Tree file_arg) {
  const char *filestr = NULL;
  PT_ParseTree inputParseTree;
  CO_OptLayout l = CO_makeOptLayoutAbsent();
  const char *sort = getSort(type);

  if (sort == NULL) {
    return  (PT_Tree) CO_makeParsetreeXFailure((ATerm) PT_makeSymbolSort(sort), l,l,
		makeGeneralError("complex symbols are not supported"),
	       	l);
  }

  /*SG_InitPTGlobals();*/
  filestr = getFilename(file_arg);

  inputParseTree = PT_ParseTreeFromTerm(ATreadFromNamedFile(filestr));

  return parse_result(sort, inputParseTree, NULL, ATfalse);
}


PT_Tree ASFE_read_term_from_file(PT_Symbol symbol, PT_Tree file_arg) {
  return read_term_from_file(symbol, file_arg); 
}


PT_Tree ASC_read_term_from_file(ATerm type, ATerm afile_arg) {
  PT_Tree file_arg = muASFToTree(afile_arg);

  return read_term_from_file((PT_Symbol) type, file_arg);
}


static PT_Tree write_term_to_file(PT_Tree file_arg, PT_Tree tree_arg) {
  PT_ParseTree pt = PT_makeValidParseTreeFromTree(tree_arg);
  char *filestr = NULL;
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  filestr = getFilename(file_arg);

  if (ATwriteToNamedTextFile(PT_ParseTreeToTerm(pt), filestr)) {
    return (PT_Tree) CO_makeWriteSuccess();
  }
  else {
    return (PT_Tree) CO_makeWriteFailure(l,l, 
					 makeGeneralError(strerror(errno)),l);
  }

  return tree_arg;
}


PT_Tree ASFE_write_term_to_file(PT_Symbol type, PT_Tree file_arg, PT_Tree tree_arg) {
  return write_term_to_file(file_arg, tree_arg);
}


PT_Tree ASC_write_term_to_file(ATerm type, ATerm afile_arg, ATerm atree_arg) {
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree tree_arg = muASFToTree(atree_arg);

  return write_term_to_file(file_arg, tree_arg);
}


static size_t getFileSize(const char *s) {
    struct stat st;
    return (stat((char *)s, &st)!=EOF) ? st.st_size : -1L;
}


static char *readFileContents(char *fnam) { 
  char *buf = NULL;
  FILE *fd; 
  unsigned int size;
    
  size = getFileSize(fnam);
    
  if((fd = fopen(fnam, "rb")) == NULL) {
    return NULL;
  } 
    
  if((buf = (char *)malloc(size + 1)) == NULL ) {
    fclose(fd);
    return NULL;
  }

  if(fread(buf, 1, size, fd) != size) {
    free(buf);
    fclose(fd);
    return NULL;
  }

  fclose(fd);
  buf[size] = '\0';
  return buf ;
}


static PT_Tree read_bytes_from_file(PT_Tree input) {
  char *filename = getFilename(input);
  char *buf = NULL;
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  buf = readFileContents(filename);

  if (buf != NULL) {
    return (PT_Tree) 
      CO_makeReadSuccess(l,l,(CO_Bytes) make_bytes(buf),l);
  }

  return (PT_Tree) 
    CO_makeReadFailure(l,l,makeGeneralError(strerror(errno)), l);
}


PT_Tree ASFE_read_bytes_from_file(PT_Symbol type, PT_Tree file_arg) {
  return read_bytes_from_file(file_arg);
}


PT_Tree ASC_read_bytes_from_file(ATerm type, ATerm afile_arg) {
  PT_Tree file_arg = muASFToTree(afile_arg);

  return read_bytes_from_file(file_arg);
}


static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes) {
  char *filename = getFilename(input);
  FILE *fp = NULL;
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  fp = fopen(filename, "wb");

  if (fp != NULL) {
    fputs(PT_yieldTreeToString(bytes, ATfalse), fp);
    fclose(fp);
  }
  else {
    return (PT_Tree) 
      CO_makeWriteFailure(l,l, makeGeneralError(strerror(errno)), l);
  } 

  return (PT_Tree) CO_makeWriteSuccess();
}


PT_Tree ASFE_write_bytes_to_file(PT_Symbol type, PT_Tree file_arg, PT_Tree bytes) {
  return write_bytes_to_file(file_arg, bytes);
}


PT_Tree ASC_write_bytes_to_file(ATerm type, ATerm afile_arg, ATerm abytes_arg) {
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree bytes_arg = muASFToTree(abytes_arg);

  return write_bytes_to_file(file_arg, bytes_arg);
}


static CO_NatCon execute_command(PT_Tree cmd_arg) {
  int result = system(getCommand(cmd_arg));
  char nat[142];

  sprintf(nat, "%d", result);

  return CO_makeNatConLexToCf(CO_makeLexNatConDigits(nat));
}


PT_Tree ASFE_execute_command(PT_Symbol type, PT_Tree cmd_arg) {
  return (PT_Tree) execute_command(cmd_arg);
}


PT_Tree ASC_execute_command(ATerm type, ATerm input) {
  PT_Tree cmd_arg = muASFToTree(input);

  return (PT_Tree) execute_command(cmd_arg);
}


/* This buffer is for read_from_command,
 * for efficiency we have a static buffer that can be reused between
 * calls to read_from_command, but when the size gets to big,
 * we garbage collect it to save space.
 */
static char *checkBuffer(int minSize) {
  static char *buffer = NULL;
  static int bufSize = -1;

  if (minSize == 0) {
    if (bufSize > BUFFER_COLLECT_SIZE) {
      free(buffer);
      buffer = NULL;
    }

    return NULL;
  }

  if (bufSize == -1) {
    bufSize = INIT_BUF_SIZE;
  }

  while (bufSize < minSize) {
    bufSize += INCR_BUF_SIZE;
  }
    
  if (buffer == NULL) {
    buffer = (char*) calloc(bufSize, sizeof(char));
  }
  else {
    buffer = (char*) realloc(buffer, bufSize * sizeof(char));
  }

  if (buffer == NULL) {
    ATerror("buffer: out of memory\n");
    return NULL;
  }

  return buffer;
}


static CO_Read read_from_command(PT_Tree command) {
  CO_OptLayout l = CO_makeOptLayoutAbsent();
  CO_Read result;
  FILE *fp = popen(getCommand(command), "r");
  int bytesRead = 0;
  size_t blockRead = 0;
  char *buffer = NULL;

  if (fp != NULL) {
    do { 
      buffer = checkBuffer(bytesRead + READ_BLOCK_SIZE);
      if (buffer == NULL) {
	return CO_makeReadFailure(l,l,makeGeneralError("out of memory"),l);
      }

      blockRead = fread(buffer+bytesRead, sizeof(char), READ_BLOCK_SIZE, fp);
      bytesRead += blockRead;

    } while (blockRead == READ_BLOCK_SIZE); 

    if (!feof(fp) || ferror(fp)) {
      result = CO_makeReadFailure(l,l,makeGeneralError(strerror(errno)), l);
    }
    else {
      buffer[bytesRead] = '\0';
      result = CO_makeReadSuccess(l, l, make_bytes(buffer), l);
    }

    buffer = checkBuffer(0);
    fclose(fp);
    fp = NULL;
  }
  else {
    result = CO_makeReadFailure(l,l,makeGeneralError(strerror(errno)), l);
  }

  return result;
}


PT_Tree ASFE_read_from_command(PT_Symbol type, PT_Tree command) {
  return (PT_Tree) read_from_command(command);
} 


PT_Tree ASC_read_from_command(ATerm type, ATerm command) {
  PT_Tree cmd_arg = muASFToTree(command);

  return (PT_Tree) read_from_command(cmd_arg);
}


