/* $Id$ */

/*{{{  includes */

#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

/*}}}  */

/*{{{  globals */

static ATbool sharing_on;
static ATbool characters_on;
static ATbool characters_sharing_on;
static ATbool productions_on;
static ATbool layout_on;
static ATbool literals_on;

static long   unique_key;
static size_t size;

#define  INITIAL_SIZE 4096
#define  STEP_SIZE    2048

/*}}}  */

/*{{{  static void vappend(char *str, const char* format, va_list ap) */

static char* vappend(char *str, const char* format, va_list ap)
{
  int count;
  int length = strlen(str);

  /* vsnprintf returns the number of chars that (would) have been printed.
   * So if the new strlen is smaller than expected, we realloc to a new size
   * that is at least the size needed for this append and then some more.
   */

  count = vsnprintf(str+length,size - length,format,ap);

  if (strlen(str) < count + length) {
    size += (STEP_SIZE + count);

    str = realloc(str,size * sizeof(char));

    if (str == NULL) {
      ATerror("vappend: unable to allocate memory\n");
      return NULL;
    }

    count = vsnprintf(str+length,size - length,format,ap);

    assert(strlen(str) >= count + length);
  }

  return str;
}

/*}}}  */
/*{{{  static void append(char *str, const char* format, ...) */

static char* append(char *str, const char* format, ...)
{
   va_list ap;

   va_start(ap,format); 
   str = vappend(str,format,ap);
   va_end(ap);

   return str;
}

/*}}}  */

/*{{{  char* escape(const char* str) */

static char* escape(const char* str)
{
  int i,j;
  int len = strlen(str);
  char *escaped = (char*) malloc(5 * len * sizeof(char) + 5);

  if (escaped == NULL) {
    ATerror("escape: could not allocate enough memory for escaping:\n%s\n",str);
    return NULL;
  }

  i = 0;
  j = 0;

  for (; i < len; i++, j++) {
    switch(str[i]) {
    case '\n':
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j] = 'n';
      break;
    case '\t':
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j] = 't';
      break; 
    case '\\':
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j++] = '\\';
      escaped[j]   = '\\';
      break;
    case '\"':
      escaped[j++] = '\\';
      /* drop intended */
    default: 
      escaped[j] = str[i];
      break;
    }
  }

  escaped[j] = '\0';

  return escaped;
}

/*}}}  */

/*{{{  static long makeNodeId(PT_Tree tree) */

static long makeNodeId(PT_Tree tree)
{
  long key;

  if (sharing_on) {
    key = (long) tree;
  }
  else {
    key = ++unique_key;
  }

  return key;
}

/*}}}  */

/*{{{  static void printNode(char *dot, int parent, int node, char *contents) */

static char* printNode(char *dot, int parent, int node, char *contents)
{
   char *escaped = escape(contents);

   dot = append(dot,"\tN%d [label=\"%s\" shape=%s] \n", 
                     node, escaped,
                     productions_on ? "box" : "ellipse" );

   if (parent != 0) {
     dot = append(dot,"\tN%d -> N%d\n",parent,node);
   }

  free(escaped);

  return dot;
}

/*}}}  */
/*{{{  static void printAmbNode(char *dot, int parent, int node, char *contents) */

static char* printAmbNode(char *dot, int parent, int node, char *contents)
{
   char *escaped = escape(contents);

   dot = append(dot,"\tN%d [label=\"%s\" "
	            "shape=diamond color=grey style=\"bold,filled\"]\n", 
	   node, escaped);

   if (parent != 0) {
     dot = append(dot,"\tN%d -> N%d\n",parent,node);
   }

   free(escaped);

   return dot;
}

/*}}}  */
/*{{{  static char* printCharNode(char *dot, int parent, int node, char *contents) */

static char* printCharNode(char *dot, int parent, int node, char *contents)
{
   char *escaped = escape(contents);

   dot = append(dot,"\tN%d_%d [label=\"%s\" shape=%s] \n", 
                     node, parent, escaped,
                     productions_on ? "box" : "ellipse" );

   if (parent != 0) {
     dot = append(dot,"\tN%d -> N%d_%d\n",parent,node,parent);
   }

  free(escaped);

  return dot;
}

/*}}}  */

/*{{{  static void treeToDot(char *dot, int *len, PT_Tree tree, int parent) */

static char* treeToDot(char *dot, PT_Tree tree, int parent)
{
  long key = makeNodeId(tree);

  if (PT_isTreeChar(tree)) {
    /*{{{  handle characters */

    if (characters_on) {
      char ch[2] = { '\0', '\0'};
      ch[0] = PT_getTreeCharacter(tree);

      if (characters_sharing_on) {
        dot = printNode(dot,parent,key,ch);
      }
      else {
	dot = printCharNode(dot,parent,key,ch);
      }
    }

    /*}}}  */
  }
  else if (PT_isTreeLit(tree)) {
    /*{{{  handle literal */

    if (literals_on) {
      dot = printNode(dot,parent,key,PT_getTreeString(tree));
    }

    /*}}}  */
  }
  else if (PT_isTreeAppl(tree)) {
    /*{{{  handle appl */

    PT_Args args = PT_getTreeArgs(tree);
    PT_Production prod = PT_getTreeProd(tree);
    PT_Symbol rhs = PT_getProductionRhs(prod);
    ATbool layout = PT_isTreeLayout(tree);
    ATbool literal = PT_isSymbolLit(rhs); /* for asfix2 compliance */

    if (!layout && (literals_on || !literal)) {
      dot = printNode(dot,parent,key,productions_on ?
				PT_yieldProduction(PT_getTreeProd(tree)) :
				PT_yieldSymbol(rhs));
    } 
    else if (layout_on && layout) {
      dot = printNode(dot,parent,key, "LAYOUT?");
    }

    if ((layout_on || !layout) && (literals_on || !literal)) {
      for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
	  PT_Tree arg = PT_getArgsHead(args);
	  dot = treeToDot(dot,arg,key);
      }
    }

    /*}}}  */
  }
  else if (PT_isTreeAmb(tree)) {
    /*{{{  handle amb cluster */

    PT_Args args = PT_getTreeArgs(tree);
    PT_Tree first = PT_getArgsHead(args);
    PT_Production prod = PT_getTreeProd(first);
    PT_Symbol symbol = PT_getProductionRhs(prod);
      
    dot = printAmbNode(dot,parent,key,PT_yieldSymbol(symbol));

    for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      dot = treeToDot(dot,arg,key);
    }

    /*}}}  */
  }
  else {
    ATerror("treeToDot: unhandled tree: %t\n", tree);
    return NULL;
  }

  return dot;
}

/*}}}  */

/*{{{  char* PT_printTreeToDot(PT_Tree tree, ATbool sharing, ATbool characters,  */

char* PT_printTreeToDot(PT_Tree tree, ATbool sharing, ATbool characters, 
			ATbool characters_sharing, ATbool productions, 
			ATbool layout, ATbool literals)
{
  char color[] = "black";
  char *dot = NULL;

  sharing_on = sharing;
  characters_on = characters;
  characters_sharing_on = characters_sharing;
  productions_on = productions;
  layout_on = layout;
  literals_on = literals;

  unique_key = 0;
  size = INITIAL_SIZE;

  dot = (char*) malloc(size * sizeof(char));

  if (dot == NULL) {
    ATerror("PT_printTreeToDot: unable to allocate memory\n");
    return NULL;
  }

  dot[0] = '\0';

  dot = append(dot,"strict digraph ParseTree {\n"
	      "\tordering=out\n"
	      "\tedge[dir=none color=%s]\n"
	      "\tnode[color=%s]\n\n",
	      color,
	      color);

  dot = treeToDot(dot,tree,0);

  dot = append(dot,"}\n");

  return dot;
}

/*}}}  */
/*{{{  char* PT_printParseTreeToDot(PT_ParseTree parsetree, ATbool sharing,  */

char* PT_printParseTreeToDot(PT_ParseTree parsetree, ATbool sharing, 
			     ATbool characters, ATbool characters_sharing,
			     ATbool productions, ATbool layout, 
			     ATbool literals)
{
  return PT_printTreeToDot(PT_getParseTreeTop(parsetree),sharing,characters,
			   characters_sharing, productions, layout, literals);
}

/*}}}  */
