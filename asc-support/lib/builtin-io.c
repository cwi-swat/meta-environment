#include <PTMEPT-utils.h>
#include "builtin-common.h"
#include <sglr.h>
#include <asc-support-me.h>
#include <Library.h>
#include <sys/stat.h>
#include <aterm2.h>
#include <ErrorAPI-utils.h>
#include <errno.h>

static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes);
static PT_Tree unparse_to_bytes(PT_Tree tree);

/*{{{ until parse errors have an ADT, this is the parse error API  */

#define LINE 1
#define COLUMN 2
#define OFFSET 3
#define getErrorInfo(error, info) (ATgetInt((ATermInt) ATgetArgument((ATermAppl) ATelementAt((ATermList) ATgetArgument((ATermAppl) (error),0),info),0))) 

/*}}}  */

/*{{{  static char* getFilename(PT_Tree str)  */

static char* getFilename(PT_Tree str) 
{
  ATerm aterm = ATparse(PT_yieldTree(str));
  return ATgetName(ATgetAFun((ATermAppl) aterm));
}

/*}}}  */

/*{{{  static CO_Feedback makeGeneralError(char *producer, char *msg) */

static CO_Feedback makeGeneralError(char *producer, char *msg)
{
  ERR_Feedback feedback = ERR_makeFeedbackError(producer,
						msg,
						ERR_makeSubjectListEmpty());

  return (CO_Feedback) ERR_liftFeedback(feedback);
}

/*}}}  */
/*{{{  static CO_Feedback makeParseErrorFeedback(char *producer, char *file,  */

static CO_Feedback makeParseError(char *producer, char *file, ATerm error)
{
  int line = getErrorInfo(error, LINE);
  int col = getErrorInfo(error, COLUMN);
  int offset = getErrorInfo(error, OFFSET);
  ERR_Subject subject;
  ERR_Area area;
  ERR_Location location;
  ERR_Feedback feedback;
  
  area = ERR_makeAreaArea(line, col, line, col, offset, offset);
  location = ERR_makeLocationLocation(file, area);
  subject = ERR_makeSubjectSubject("cursor", location);
  feedback = ERR_makeFeedbackError(producer, "parse-error",
				   ERR_makeSubjectListSingle(subject));

  return (CO_Feedback) ERR_liftFeedback(feedback);
}

/*}}}  */

/*{{{  static PT_Tree make_natcon(int value) */

static PT_Tree make_natcon(int value)
{
  char str[100];
  sprintf(str, "%d", value);
  return PT_makeTreeLexToCf(PT_makeSymbolSort("NatCon"), 
			    PT_makeTreeFlatLexicalFromString(str));
}

/*}}}  */
/*{{{  static CO_Bytes make_bytes(const char *value) */

static CO_Bytes make_bytes(const char *value)
{
  return (CO_Bytes) PT_makeTreeLexToCf(PT_makeSymbolSort("Bytes"), 
			    PT_makeTreeFlatLexicalFromString(value));
}

/*}}}  */

/*{{{  static ATbool initParser(char *toolname, ATerm language) */

static ATbool initParser(char *toolname, ATerm language)
{
  ATerm pt = getParseTable();

  if (pt != NULL) {
    SGinitParser(ATfalse);
    SG_ASFIX2ME_ON();
    SG_OUTPUT_ON();
    SG_TOOLBUS_OFF();

    SGopenLanguageFromTerm(toolname, language, getParseTable());

    return ATtrue;
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static PT_Tree parse_result(char *builtin, char *file, ATerm result) */

static PT_Tree parse_result(char *builtin, char *file, ATerm result)
{
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  if (result == NULL) {
    return (PT_Tree) CO_makeParseResultFailure(l,l,
	       makeGeneralError(builtin, "unknown error during parsing"),l);
  }

  if (SGisParseTree(result)) {
    PT_ParseTree pt = PT_ParseTreeFromTerm(result);
    int ambs = PT_getParseTreeAmbCnt(pt);
    PT_Tree tree = PT_getParseTreeTree(pt);
    PT_Tree before = PT_getParseTreeLayoutBeforeTree(pt);
    PT_Tree after = PT_getParseTreeLayoutAfterTree(pt);
    PT_Tree tmp;
    PT_Symbol symbol;

    if (PT_isTreeAmb(tree)) {
      tmp = PT_getArgsHead(PT_getTreeArgs(tree));
    }
    else {
      tmp = tree;
    }

    if (PT_isTreeAppl(tmp)) {
      PT_Production prod = PT_getTreeProd(tmp);

      symbol = PT_getProductionRhs(prod);

      if (PT_isSymbolCf(symbol)) {
	symbol = PT_getSymbolSymbol(symbol);

	if (PT_isSymbolSort(symbol)) {
	  return (PT_Tree)
	    CO_makeParseResultSuccess(PT_getSymbolString(symbol),
					l, l,
					(CO_Bytes) unparse_to_bytes(before),
					l, l,
					(ATerm) tree,
					l, l, 
					(CO_Bytes) unparse_to_bytes(after),
					l, l,
					(CO_NatCon) make_natcon(ambs),
					l);
	}
      }
    }
    {
      CO_Feedback error = makeGeneralError(builtin,
					   "result is not a valid parse tree");
      return (PT_Tree) CO_makeParseResultFailure(l,l, error,l);
    }
  }
  else if (SGisParseError(result)) {
    return (PT_Tree) makeParseError(builtin, file, result);
  }

  ATwarning("result is: %t\n", result);
  return (PT_Tree) 
    makeGeneralError(builtin, "unknown parse tree format");
}

/*}}}  */

/*{{{  static PT_Tree parse_file(PT_Tree file) */

static PT_Tree parse_file(PT_Tree file)
{
  char  toolname[] = "parse-file";
  ATerm language = ATmake("<str>", toolname);
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  if (initParser(toolname, language)) {
    char *filename = getFilename(file);
    ATerm result = SGparseFile(toolname, language, NULL, filename);
    return parse_result(toolname, filename, result);
  }

  return (PT_Tree) CO_makeParseResultFailure(l,l,
					     makeGeneralError(toolname, "no parsetable available"),
					     l);
}

/*}}}  */
/*{{{  PT_Tree ASFE_parse_file(PT_Tree input) */

PT_Tree ASFE_parse_file(PT_Symbol type, PT_Tree file)
{
  return parse_file(file);
}

/*}}}  */
/*{{{  PT_Tree ASC_parse_file(ATerm type, ATerm aterm, ATerm akey, ATerm avalue) */

PT_Tree ASC_parse_file(ATerm type, ATerm aterm)
{
  PT_Tree file = muASFToTree(aterm);

  return parse_file(file);
}

/*}}}  */

/*{{{  static PT_Tree parse_bytes(PT_Tree bytes) */

static PT_Tree parse_bytes(PT_Tree bytes)
{
  char  toolname[] = "parse-bytes";
  ATerm language = ATparse(toolname);
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  if (initParser(toolname, language)) {
    ATerm result = SGparseString(language, NULL, PT_yieldTree(bytes)); 
    return parse_result(toolname, "anonymous", result);
  }

  return (PT_Tree) CO_makeParseResultFailure(l,l,
					     makeGeneralError(toolname, "no parsetable available"),
					     l);
}

/*}}}  */
/*{{{  PT_Tree ASFE_parse_bytes(PT_Tree input) */

PT_Tree ASFE_parse_bytes(PT_Symbol type, PT_Tree bytes)
{
  return parse_bytes(bytes);
}

/*}}}  */
/*{{{  PT_Tree ASC_parse_bytes(ATerm aterm) */

PT_Tree ASC_parse_bytes(ATerm type, ATerm aterm)
{
  PT_Tree bytes = muASFToTree(aterm);

  return parse_bytes(bytes);
}

/*}}}  */

/*{{{  static PT_Tree unparse_to_bytes(PT_Tree tree) */

static PT_Tree unparse_to_bytes(PT_Tree tree)
{
  return (PT_Tree) make_bytes(PT_yieldTree(tree));
}

/*}}}  */
/*{{{  PT_Tree ASFE_unparse_to_bytes(PT_Tree input) */

PT_Tree ASFE_unparse_to_bytes(PT_Symbol type, PT_Tree tree)
{
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  return (PT_Tree)
        CO_makeBytesResultSuccess(l,l,(CO_Bytes) unparse_to_bytes(tree),l);
}

/*}}}  */
/*{{{  PT_Tree ASC_unparse(ATerm input) */

PT_Tree ASC_unparse_to_bytes(ATerm type, ATerm input)
{
  PT_Tree tree = muASFToTree(input);
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  return (PT_Tree)
        CO_makeBytesResultSuccess(l,l,(CO_Bytes) unparse_to_bytes(tree),l);
}

/*}}}  */

/*{{{  static PT_Tree unparse_to_file(PT_Tree tree) */

static PT_Tree unparse_to_file(PT_Tree file, PT_Tree tree)
{
  PT_Tree bytes = unparse_to_bytes(tree);
  return write_bytes_to_file(file, bytes);
}

/*}}}  */
/*{{{  PT_Tree ASFE_unparse_to_file(PT_Tree input) */

PT_Tree ASFE_unparse_to_file(PT_Symbol type, PT_Tree file, PT_Tree tree)
{
  return unparse_to_file(file, tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_unparse_to_file(ATerm afile, ATerm input) */

PT_Tree ASC_unparse_to_file(ATerm type, ATerm afile, ATerm input)
{
  PT_Tree file = muASFToTree(afile);
  PT_Tree tree = muASFToTree(input);

  return unparse_to_file(file, tree);
}

/*}}}  */

/*{{{  static PT_Tree read_term_from_file(PT_Tree file_arg) */

static PT_Tree read_term_from_file(PT_Tree file_arg)
{
  char *filestr = NULL;
  ATerm term;

  SG_InitPTGlobals();
  filestr = getFilename(file_arg);

  term = ATreadFromNamedFile(filestr);

  return parse_result("read-term-from-file", filestr, term);
}

/*}}}  */
/*{{{  PT_Tree ASFE_read_term_from_file(PT_Tree input) */

PT_Tree ASFE_read_term_from_file(PT_Symbol symbol, PT_Tree file_arg)
{
  return read_term_from_file(file_arg); 
}

/*}}}  */
/*{{{  PT_Tree ASC_read_term_from_file(ATerm afile_arg) */

PT_Tree ASC_read_term_from_file(ATerm type, ATerm afile_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree result = NULL;

  result = read_term_from_file(file_arg);

  return result ? result : PT_makeTreeLit("TODO: make proper normal form");
}

/*}}}  */

/*{{{  static PT_Tree write_term_to_file(PT_Tree input) */

static PT_Tree write_term_to_file(PT_Tree file_arg, PT_Tree tree_arg)
{
  PT_ParseTree pt = PT_makeValidParseTreeFromTree(tree_arg);
  char *filestr = NULL;
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  filestr = getFilename(file_arg);

  if (ATwriteToNamedTextFile(PT_ParseTreeToTerm(pt), filestr)) {
    return (PT_Tree) CO_makeWriteResultSuccess();
  }
  else {
    return (PT_Tree) CO_makeWriteResultFailure(l,l,
			       makeGeneralError("write-term-to-file",
						strerror(errno)),l);
  }

  return tree_arg;
}

/*}}}  */
/*{{{  PT_Tree ASFE_write_term_to_file(PT_Tree input) */

PT_Tree ASFE_write_term_to_file(PT_Symbol type, PT_Tree file_arg, PT_Tree tree_arg)
{
  return write_term_to_file(file_arg, tree_arg);
}

/*}}}  */
/*{{{  PT_Tree write_term_to_file(PT_Tree input) */

PT_Tree ASC_write_term_to_file(ATerm type, ATerm afile_arg, ATerm atree_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree tree_arg = muASFToTree(atree_arg);

  return write_term_to_file(file_arg, tree_arg);
}

/*}}}  */

/*{{{  static size_t getFileSize(const char *s) */

static size_t getFileSize(const char *s)
{
    struct stat st;
    return (stat((char *)s, &st)!=EOF) ? st.st_size : -1L;
}

/*}}}  */
/*{{{  static char *readFileContents(char *fnam) */

static char *readFileContents(char *fnam)
{ 
  char *buf = NULL;
  FILE *fd; 
  int size;
    
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

/*}}}  */

/*{{{  static PT_Tree read_bytes_from_file(PT_Tree input) */

static PT_Tree read_bytes_from_file(PT_Tree input)
{
  char *filename = getFilename(input);
  char *buf = NULL;
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  buf = readFileContents(filename);

  if (buf != NULL) {
    return (PT_Tree) 
      CO_makeBytesResultSuccess(l,l,(CO_Bytes) make_bytes(buf),l);
  }

  return (PT_Tree) 
    CO_makeBytesResultFailure(l,l,makeGeneralError("read-bytes-from-file",
						   strerror(errno)),

			      l);
}

/*}}}  */
/*{{{  PT_Tree ASFE_read_bytes_from_file(PT_Tree input) */

PT_Tree ASFE_read_bytes_from_file(PT_Symbol type, PT_Tree file_arg)
{
  return read_bytes_from_file(file_arg);
}

/*}}}  */
/*{{{  PT_Tree ASC_read_bytes_from_file(ATerm afile_arg) */

PT_Tree ASC_read_bytes_from_file(ATerm type, ATerm afile_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);

  return read_bytes_from_file(file_arg);
}

/*}}}  */

/*{{{  static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes) */

static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes)
{
  char *filename = getFilename(input);
  FILE *fp = NULL;
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  fp = fopen(filename, "wb");

  if (fp != NULL) {
    fputs(PT_yieldTree(bytes), fp);
    fclose(fp);
  }
  else {
    return (PT_Tree) 
      CO_makeWriteResultFailure(l,l,
				makeGeneralError("write-bytes-to-file",
				strerror(errno)),
				l);
  } 

  return (PT_Tree) CO_makeWriteResultSuccess();
}

/*}}}  */
/*{{{  PT_Tree ASFE_write_bytes_to_file(PT_Tree input) */

PT_Tree ASFE_write_bytes_to_file(PT_Symbol type, PT_Tree file_arg, PT_Tree bytes)
{
  return write_bytes_to_file(file_arg, bytes);
}

/*}}}  */
/*{{{  PT_Tree ASC_write_bytes_to_file(ATerm type, ATerm afile_arg, ATerm abytes_arg) */

PT_Tree ASC_write_bytes_to_file(ATerm type, ATerm afile_arg, ATerm abytes_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree bytes_arg = muASFToTree(abytes_arg);

  return write_bytes_to_file(file_arg, bytes_arg);
}

/*}}}  */
