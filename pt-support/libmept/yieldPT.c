/* $Id$ */

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <assert.h> 

#include "MEPT-utils.h"

/*}}}  */
/*{{{  defines */

#define INITIAL_BUFFER_SIZE 4*1024

#define AMB_CLUSTER_START "\n<<<<<<<<<<\n"
#define AMB_CLUSTER_SEP   "\n==========\n"
#define AMB_CLUSTER_END   "\n>>>>>>>>>>\n"

/*}}}  */
/*{{{  structures and types */

typedef void (*charYielder)(char c);
typedef void (*ambiguityAcceptor)(PT_Args ambiguities);

typedef struct _TreeYielder
{
  charYielder yieldChar;
  ambiguityAcceptor acceptAmbiguities;
} *TreeYielder;

/*}}}  */
/*{{{  function declarations */

static void countChar(char c);
static void yieldCharToFile(char c);
static void yieldCharToBuffer(char c);
static void visitArgs(PT_Args args, TreeYielder yielder);

/*}}}  */

/*{{{  variables */

static unsigned long treeCount = 0;
static struct _TreeYielder yielder = { countChar, NULL };

static FILE *outputFile = NULL;
static struct _TreeYielder treeToFile = { yieldCharToFile, NULL };

static char *bufferStart = NULL;
static char *bufferCur = NULL;
static unsigned int bufferCapacity = 0;
static struct _TreeYielder treeToBuffer = { yieldCharToBuffer, NULL };

/*}}}  */

/*{{{  static char descape(const char **p) */

static char descape(const char **p)
{
  char c;

  if (**p == '\\') {
    (*p)++;
    switch (**p) {
      case 'n':
	c = '\n';
	break;
      case 't':
	c = '\t';
	break;
      case ' ':
      case '`':
	c = **p;
	break;
      default:
	c = '\\';
	break;
    }
  }
  else {
    c = **p;
  }

  return c;
}

/*}}}  */

/*{{{  static void visitTree(PT_Tree tree, TreeYielder yielder) */

static void visitTree(PT_Tree tree, TreeYielder yielder)
{
  if (PT_isTreeChar(tree)) {
    yielder->yieldChar(PT_getTreeCharacter(tree));
  }
  else if (PT_isTreeLit(tree)) {
    const char *s = PT_getTreeString(tree);
    while (*s) {
      char c = descape(&s);
      yielder->yieldChar(c);
      s++;
    }
  }
  else if (PT_isTreeAppl(tree)) {
    visitArgs(PT_getTreeArgs(tree), yielder);
  }
  else if (PT_isTreeAmb(tree)) {
    if (yielder->acceptAmbiguities == NULL) {
      visitTree(PT_getArgsHead(PT_getTreeArgs(tree)), yielder);
    }
    else {
      ATabort("yieldAll ambiguities not yet implemented.");
    }
  }
  else {
    ATabort("visitTree: unknown tree: %t\n", tree);
  }
}

/*}}}  */
/*{{{  static void visitArgs(PT_Args args, TreeYielder yielder) */

static void visitArgs(PT_Args args, TreeYielder yielder)
{
  while (PT_hasArgsHead(args)) {
    visitTree(PT_getArgsHead(args), yielder);
    args = PT_getArgsTail(args);
  }
}

/*}}}  */

/*{{{  static void countChar(char c) */

static void countChar(char c)
{
  treeCount++;
  if ((treeCount & 0xFFFFF) == 0) {
    fprintf(stderr, "\rcount: %ld", treeCount);
  }
}

/*}}}  */
/*{{{  unsigned long PT_getTreeLength(PT_Tree tree) */

unsigned long PT_getTreeLength(PT_Tree tree)
{
  treeCount = 0;
  visitTree(tree, &yielder);

  return treeCount;
}

/*}}}  */

/*{{{  static void yieldCharToFile(char c) */

static void yieldCharToFile(char c)
{
  fputc((int)c, outputFile);
}

/*}}}  */
/*{{{  static void yieldTreeToFile(PT_Tree tree, FILE *f, ATbool yieldAllAmbiguities) */

static void yieldTreeToFile(PT_Tree tree, FILE *f, ATbool yieldAllAmbiguities)
{
  if (yieldAllAmbiguities) {
    treeToFile.acceptAmbiguities = NULL; /* TODO */
  }

  outputFile = f;
  visitTree(tree, &treeToFile);
  outputFile = NULL;

  fflush(f);
  treeToFile.acceptAmbiguities = NULL;
}

/*}}}  */
/*{{{  static void yieldArgsToFile(PT_Args args, FILE *f, ATbool yieldAllAmbiguities) */

static void yieldArgsToFile(PT_Args args, FILE *f, ATbool yieldAllAmbiguities)
{
  if (yieldAllAmbiguities) {
    treeToFile.acceptAmbiguities = NULL; /* TODO */
  }

  outputFile = f;
  visitArgs(args, &treeToFile);
  outputFile = NULL;

  fflush(f);
  treeToFile.acceptAmbiguities = NULL;
}

/*}}}  */

/*{{{  static void yieldCharToBuffer(char c) */

static void yieldCharToBuffer(char c)
{
  if (bufferCapacity == 0) {
    bufferCapacity = INITIAL_BUFFER_SIZE;
    bufferStart = (char *) malloc(bufferCapacity * sizeof(char));
    bufferCur = bufferStart;
  }
  else if (bufferCapacity <= (bufferCur - bufferStart)) {
    unsigned int index = bufferCur - bufferStart;
    if (bufferCapacity < 1*1024*1024*1024) {
      bufferCapacity = bufferCapacity * 2;
    }
    else {
      bufferCapacity += 4*1024*1024;
    }
    bufferStart = (char *) realloc(bufferStart, bufferCapacity);
    bufferCur = bufferStart + index;
  }

  assert(bufferStart != NULL);
  assert(bufferCur - bufferStart <= bufferCapacity);

  *bufferCur++ = c;
}

/*}}}  */
/*{{{  static char *yieldTreeToBuffer(PT_Tree tree, ATbool yieldAllAmbiguities) */

static char *yieldTreeToBuffer(PT_Tree tree, ATbool yieldAllAmbiguities)
{
  if (yieldAllAmbiguities) {
    treeToBuffer.acceptAmbiguities = NULL; /* TODO */
  }

  bufferCur = bufferStart;
  visitTree(tree, &treeToBuffer);
  yieldCharToBuffer('\0');
  treeToBuffer.acceptAmbiguities = NULL;

  return bufferStart;
}

/*}}}  */
/*{{{  static char *yieldArgsToBuffer(PT_Args args, ATbool yieldAllAmbiguities) */

static char *yieldArgsToBuffer(PT_Args args, ATbool yieldAllAmbiguities)
{
  if (yieldAllAmbiguities) {
    treeToBuffer.acceptAmbiguities = NULL; /* TODO */
  }

  memset(bufferStart, 0, bufferCapacity);
  bufferCur = bufferStart;
  visitArgs(args, &treeToBuffer);
  yieldCharToBuffer('\0');
  treeToBuffer.acceptAmbiguities = NULL;

  return bufferStart;
}

/*}}}  */

#if 0
/*{{{  char *PT_yieldTree(PT_Tree tree)  */

char *PT_yieldTree(PT_Tree tree) 
{
  return PT_yieldTreeVisualAmbs(tree, ATfalse);
}

/*}}}  */
/*{{{  char *PT_yieldArgs(PT_Args args) */

char *PT_yieldArgs(PT_Args args)
{
  return PT_yieldArgsVisualAmbs(args, ATfalse);
}

/*}}}  */
/*{{{  char *PT_yieldParseTree(PT_ParseTree tree) */

char *PT_yieldParseTree(PT_ParseTree tree)
{
  return PT_yieldParseTreeVisualAmbs(tree, ATfalse);
}

/*}}}  */
/*{{{  char *PT_yieldAny(ATerm tree) */

char *PT_yieldAny(ATerm tree)
{
  return PT_yieldAnyVisualAmbs(tree, ATfalse);
}

/*}}}  */
/*{{{  char *PT_yieldTreeVisualAmbs(PT_Tree tree, ATbool yieldAllAmbiguities) */

char *PT_yieldTreeVisualAmbs(PT_Tree tree, ATbool yieldAllAmbiguities)
{
  return yieldTreeToBuffer(tree, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  char *PT_yieldArgs(PT_Args args, ATbool yieldAllAmbiguities) */

char *PT_yieldArgsVisualAmbs(PT_Args args, ATbool yieldAllAmbiguities)
{
  return yieldArgsToBuffer(args, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  char *PT_yieldParseTreeVisualAmbs(PT_ParseTree tree, ATbool yieldAllAmbiguities) */

char *PT_yieldParseTreeVisualAmbs(PT_ParseTree tree, ATbool yieldAllAmbiguities)
{
  return PT_yieldTreeVisualAmbs(PT_getParseTreeTop(tree), yieldAllAmbiguities);
}

/*}}}  */
/*{{{  char *PT_yieldAnyVisualAmbs(ATerm t, ATbool yieldAllAmbiguities) */

char *PT_yieldAnyVisualAmbs(ATerm t, ATbool yieldAllAmbiguities)
{
  if (PT_isParseTreeTop(PT_ParseTreeFromTerm(t))) {
    return PT_yieldParseTreeVisualAmbs(PT_ParseTreeFromTerm(t),
				       yieldAllAmbiguities);
  }
  else if (PT_isTreeAmb(PT_TreeFromTerm(t))) {
    PT_Args args = PT_getTreeArgs(PT_TreeFromTerm(t));
    return yieldArgsToBuffer(args, yieldAllAmbiguities);
  }
  else if (ATmatch(t,"appl(<term>,<term>)", NULL, NULL) 
        || ATmatch(t,"amb(<term>)", NULL)
        || ATmatch(t,"<int>", NULL)
        || ATmatch(t,"lit(<term>)", NULL)) {
    return PT_yieldTreeVisualAmbs(PT_TreeFromTerm(t), yieldAllAmbiguities);
  }
  else {
    ATabort("PT_yieldAny: Unknown term: %t\n", t);
    return NULL;
  }
}

/*}}}  */
#endif

/*{{{  char *PT_yieldTreeToString(PT_Tree tree, ATbool yieldAllAmbiguities) */

char *PT_yieldTreeToString(PT_Tree tree, ATbool yieldAllAmbiguities)
{
  return yieldTreeToBuffer(tree, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  char *PT_yieldArgsToString(PT_Args args, ATbool yieldAllAmbiguities) */

char *PT_yieldArgsToString(PT_Args args, ATbool yieldAllAmbiguities)
{
  return yieldArgsToBuffer(args, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  char *PT_yieldParseTreeToString(PT_ParseTree pt, ATbool yieldAllAmbiguities) */

char *PT_yieldParseTreeToString(PT_ParseTree pt, ATbool yieldAllAmbiguities)
{
  return yieldTreeToBuffer(PT_getParseTreeTop(pt), yieldAllAmbiguities);
}

/*}}}  */
/*{{{  char *PT_yieldAnyToString(ATerm t, ATbool yieldAllAmbiguities) */

char *PT_yieldAnyToString(ATerm t, ATbool yieldAllAmbiguities)
{
  if (PT_isParseTreeTop(PT_ParseTreeFromTerm(t))) {
    return PT_yieldParseTreeToString(PT_ParseTreeFromTerm(t),
				     yieldAllAmbiguities);
  }
  else if (PT_isTreeAmb(PT_TreeFromTerm(t))) {
    PT_Args args = PT_getTreeArgs(PT_TreeFromTerm(t));
    return PT_yieldArgsToString(args, yieldAllAmbiguities);
  }
  else if (ATmatch(t,"appl(<term>,<term>)", NULL, NULL) 
        || ATmatch(t,"amb(<term>)", NULL)
        || ATmatch(t,"<int>", NULL)
        || ATmatch(t,"lit(<term>)", NULL)) {
    return PT_yieldTreeToString(PT_TreeFromTerm(t), yieldAllAmbiguities);
  }
  else {
    ATabort("PT_yieldAnyToString: Unknown term: %t\n", t);
    return NULL;
  }
}

/*}}}  */

/*{{{  void PT_yieldTreeToFile(PT_Tree tree, FILE *f, ATbool yieldAllAmbiguities) */

void PT_yieldTreeToFile(PT_Tree tree, FILE *f, ATbool yieldAllAmbiguities)
{
  return yieldTreeToFile(tree, f, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  void PT_yieldArgsToFile(PT_Args args, FILE *f, ATbool yieldAllAmbiguities) */

void PT_yieldArgsToFile(PT_Args args, FILE *f, ATbool yieldAllAmbiguities)
{
  return yieldArgsToFile(args, f, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  void PT_yieldParseTreeToFile(PT_ParseTree pt, FILE *f, ATbool yieldAllAmbiguities) */

void PT_yieldParseTreeToFile(PT_ParseTree pt, FILE *f, ATbool yieldAllAmbiguities)
{
  return yieldTreeToFile(PT_getParseTreeTop(pt), f, yieldAllAmbiguities);
}

/*}}}  */
/*{{{  void PT_yieldAnyToFile(ATerm t, FILE *f, ATbool yieldAllAmbiguities) */

void PT_yieldAnyToFile(ATerm t, FILE *f, ATbool yieldAllAmbiguities)
{
  if (PT_isParseTreeTop(PT_ParseTreeFromTerm(t))) {
    PT_yieldParseTreeToFile(PT_ParseTreeFromTerm(t), f, yieldAllAmbiguities);
  }
  else if (PT_isTreeAmb(PT_TreeFromTerm(t))) {
    PT_Args args = PT_getTreeArgs(PT_TreeFromTerm(t));
    PT_yieldArgsToFile(args, f, yieldAllAmbiguities);
  }
  else if (ATmatch(t,"appl(<term>,<term>)", NULL, NULL) 
        || ATmatch(t,"amb(<term>)", NULL)
        || ATmatch(t,"<int>", NULL)
        || ATmatch(t,"lit(<term>)", NULL)) {
    PT_yieldTreeToFile(PT_TreeFromTerm(t), f, yieldAllAmbiguities);
  }
  else {
    ATabort("PT_yieldAnyToFile: Unknown term: %t\n", t);
  }
}

/*}}}  */
