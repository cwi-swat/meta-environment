#include <PTMEPT-utils.h>
#include "builtin-common.h"
#include <sglr.h>
#include <asc-support-me.h>
#include <Library.h>
#include <sys/stat.h>
#include <aterm2.h>

static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes);
static PT_Tree unparse_to_bytes(PT_Tree tree);

/*{{{ until parse errors have an ADT, this is the parse error API  */

#define LINE 1
#define COLUMN 2
#define OFFSET 3
#define getErrorInfo(error, info) (ATgetInt((ATermInt) ATgetArgument((ATermAppl) ATelementAt((ATermList) ATgetArgument((ATermAppl) (error),0),info),0))) 

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
/*{{{  static PT_Tree make_bytes(const char *value) */

static PT_Tree make_bytes(const char *value)
{
  return PT_makeTreeLexToCf(PT_makeSymbolSort("Bytes"), 
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
/*{{{  static PT_Tree parse_result(ATerm result) */

static PT_Tree parse_result(ATerm result)
{
  CO_OptLayout l = CO_makeOptLayoutAbsent();

  if (result == NULL) {
    return (PT_Tree) CO_makeParseResultNoValidResult();
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
	    CO_makeParseResultTree(PT_getSymbolString(symbol),
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

      return (PT_Tree) CO_makeParseResultNoValidResult();
    }
    else {
      return (PT_Tree) CO_makeParseResultNoValidResult();
    }
  }
  else if (SGisParseError(result)) {
      int line = getErrorInfo(result, LINE);
      int col = getErrorInfo(result, COLUMN);
      int offset = getErrorInfo(result, OFFSET);

      return (PT_Tree) CO_makeParseResultError(l,l,
				     (CO_NatCon) make_natcon(line),
				     l,l,
				     (CO_NatCon) make_natcon(col),
				     l,l,
				     (CO_NatCon) make_natcon(offset),
				     l);
  }
  else {
    return (PT_Tree) CO_makeParseResultNoValidResult();
  }

  return (PT_Tree) CO_makeParseResultNoValidResult();
}

/*}}}  */

/*{{{  static PT_Tree parse_file(PT_Tree file) */

static PT_Tree parse_file(PT_Tree file)
{
  char  toolname[] = "parse-file-builtin";
  ATerm language = ATmake("<str>", toolname);

  if (initParser(toolname, language)) {
    ATerm result = SGparseFile(toolname, language, NULL, PT_yieldTree(file)); 
    return parse_result(result);
  }

  return (PT_Tree) CO_makeParseResultNoParsetable();
}

/*}}}  */
/*{{{  PT_Tree ASFE_parse_file(PT_Tree input) */

PT_Tree ASFE_parse_file(PT_Tree input)
{
  PT_Tree file = CO_getFunctionArgument(input,0);

  return parse_file(file);
}

/*}}}  */
/*{{{  PT_Tree ASC_parse_file(ATerm aterm, ATerm akey, ATerm avalue) */

PT_Tree ASC_parse_file(ATerm aterm)
{
  PT_Tree file = muASFToTree(aterm);

  return parse_file(file);
}

/*}}}  */

/*{{{  static PT_Tree parse_bytes(PT_Tree bytes) */

static PT_Tree parse_bytes(PT_Tree bytes)
{
  char  toolname[] = "parse-file-builtin";
  ATerm language = ATparse(toolname);

  if (initParser(toolname, language)) {
    ATerm result = SGparseString(language, NULL, PT_yieldTree(bytes)); 
    return parse_result(result);
  }

  return (PT_Tree) CO_makeParseResultNoParsetable();
}

/*}}}  */
/*{{{  PT_Tree ASFE_parse_bytes(PT_Tree input) */

PT_Tree ASFE_parse_bytes(PT_Tree input)
{
  PT_Tree bytes = CO_getFunctionArgument(input,0);

  return parse_bytes(bytes);
}

/*}}}  */
/*{{{  PT_Tree ASC_parse_bytes(ATerm aterm) */

PT_Tree ASC_parse_bytes(ATerm aterm)
{
  PT_Tree bytes = muASFToTree(aterm);

  return parse_bytes(bytes);
}

/*}}}  */

/*{{{  static PT_Tree unparse_to_bytes(PT_Tree tree) */

static PT_Tree unparse_to_bytes(PT_Tree tree)
{
  return make_bytes(PT_yieldTree(tree));
}

/*}}}  */
/*{{{  PT_Tree ASFE_unparse_to_bytes(PT_Tree input) */

PT_Tree ASFE_unparse_to_bytes(PT_Tree input)
{
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return unparse_to_bytes(tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_unparse(ATerm input) */

PT_Tree ASC_unparse_to_bytes(ATerm input)
{
  PT_Tree tree = muASFToTree(input);

  return unparse_to_bytes(tree);
}

/*}}}  */

/*{{{  static PT_Tree unparse_to_file(PT_Tree tree) */

static PT_Tree unparse_to_file(PT_Tree file, PT_Tree tree)
{
  PT_Tree bytes = unparse_to_bytes(tree);
  write_bytes_to_file(file, bytes);
}

/*}}}  */
/*{{{  PT_Tree ASFE_unparse_to_file(PT_Tree input) */

PT_Tree ASFE_unparse_to_file(PT_Tree input)
{
  PT_Tree file = CO_getFunctionArgument(input,0);
  PT_Tree tree = CO_getFunctionArgument(input,0);

  return unparse_to_file(file, tree);
}

/*}}}  */
/*{{{  PT_Tree ASC_unparse_to_file(ATerm afile, ATerm input) */

PT_Tree ASC_unparse_to_file(ATerm afile, ATerm input)
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

  filestr = PT_yieldTree(file_arg);

  term = ATreadFromNamedFile(filestr);

  return parse_result(term);
}

/*}}}  */
/*{{{  PT_Tree ASF_read_term_from_file(PT_Tree input) */

PT_Tree ASFE_read_term_from_file(PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);/*{{{*//*}}}*/
  PT_Tree result = NULL;

  result = read_term_from_file(file_arg); 

  return result ? result : input;
}

/*}}}  */
/*{{{  PT_Tree ASC_read_term_from_file(ATerm afile_arg) */

PT_Tree ASC_read_term_from_file(ATerm afile_arg)
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

  filestr = PT_yieldTree(file_arg);

  if (filestr != NULL && strlen(filestr) > 2) {
    filestr[strlen(filestr) -1 ] = '\0';
    ATwriteToNamedTextFile(PT_ParseTreeToTerm(pt), filestr+1);
  }

  return tree_arg;
}

/*}}}  */
/*{{{  PT_Tree ASFE_write_term_to_file(PT_Tree input) */

PT_Tree ASFE_write_term_to_file(PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);
  PT_Tree tree_arg = CO_getFunctionArgument(input, 1);

  return write_term_to_file(file_arg, tree_arg);
}

/*}}}  */
/*{{{  PT_Tree write_term_to_file(PT_Tree input) */

PT_Tree ASC_write_term_to_file(ATerm afile_arg, ATerm atree_arg)
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
  char *filename = PT_yieldTree(input);
  char *buf = NULL;

  buf = readFileContents(filename);

  if (buf != NULL) {
    return make_bytes(buf);
  }

  return make_bytes("");
}

/*}}}  */
/*{{{  PT_Tree ASFE_read_bytes_from_file(PT_Tree input) */

PT_Tree ASFE_read_bytes_from_file(PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);

  return read_bytes_from_file(file_arg);
}

/*}}}  */
/*{{{  PT_Tree ASC_read_bytes_from_file(ATerm afile_arg) */

PT_Tree ASC_read_bytes_from_file(ATerm afile_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);

  return read_bytes_from_file(file_arg);
}

/*}}}  */

/*{{{  static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes) */

static PT_Tree write_bytes_to_file(PT_Tree input, PT_Tree bytes)
{
  char *filename = PT_yieldTree(input);
  FILE *fp = NULL;

  if (!(fp = fopen(filename, "wb"))) {
    fputs(PT_yieldTree(bytes), fp);
    fclose(fp);
  }

  return bytes;
}

/*}}}  */
/*{{{  PT_Tree ASFE_write_bytes_to_file(PT_Tree input) */

PT_Tree ASFE_write_bytes_to_file(PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);
  PT_Tree bytes = CO_getFunctionArgument(input, 1);

  return write_bytes_to_file(file_arg, bytes);
}

/*}}}  */
/*{{{  PT_Tree ASC_write_bytes_to_file(ATerm afile_arg, ATerm abytes_arg) */

PT_Tree ASC_write_bytes_to_file(ATerm afile_arg, ATerm abytes_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree bytes_arg = muASFToTree(abytes_arg);

  return write_bytes_to_file(file_arg, bytes_arg);
}

/*}}}  */
