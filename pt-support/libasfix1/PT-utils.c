#include <assert.h>

#include "PT-utils.h"

#define ANNO_LENGTH "length"

/*{{{  ATbool PT_isSymbolIter(PT_Symbol arg) */

ATbool PT_isSymbolIter(PT_Symbol arg)
{
  return PT_isSymbolIterStarSep(arg) ||
         PT_isSymbolIterStar(arg)    ||
         PT_isSymbolIterPlusSep(arg) ||
         PT_isSymbolIterPlus(arg);
}

/*}}}  */
/*{{{  ATbool PT_isListVar(PT_Tree arg)  */

ATbool PT_isListVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getTreeSymbol(arg);
   
    return PT_isSymbolIter(symbol); 
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isStarVar(PT_Tree arg)  */

ATbool PT_isStarVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getTreeSymbol(arg);
   
    return PT_isSymbolIterStar(symbol) || PT_isSymbolIterStarSep(symbol); 
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isPlusVar(PT_Tree arg)  */

ATbool PT_isPlusVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getTreeSymbol(arg);
   
    return PT_isSymbolIterPlus(symbol) || PT_isSymbolIterPlusSep(symbol); 
  }

  return ATfalse;
}

/*}}}  */

/*{{{  PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr) */

PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr)
{
  ATermList arg_list = (ATermList)PT_makeTermFromArgs(args);
  ATerm arg = ATelementAt(arg_list, arg_nr);
  return PT_makeTreeFromTerm(arg);
}

/*}}}  */
/*{{{  PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr) */

PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr)
{
  ATermList arg_list = (ATermList)PT_makeTermFromArgs(args);
  arg_list = ATreplace(arg_list, PT_makeTermFromTree(arg), arg_nr);
  return PT_makeArgsFromTerm((ATerm)arg_list);
}

/*}}}  */
/*{{{  PT_Args PT_concatArgs(PT_Args args1, PT_Args args2) */

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2)
{
  return PT_makeArgsFromTerm((ATerm)ATconcat(
                                      (ATermList)PT_makeTermFromArgs(args1),
                                      (ATermList)PT_makeTermFromArgs(args2)));
}

/*}}}  */
/*{{{  PT_Args PT_appendArgs(PT_Args args, PT_Tree arg) */

PT_Args PT_appendArgs(PT_Args args, PT_Tree arg)
{
  return PT_makeArgsFromTerm((ATerm)ATappend(
                                      (ATermList)PT_makeTermFromArgs(args),
                                      (ATerm)PT_makeTermFromTree(arg)));
}

/*}}}  */
/*{{{  PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor, */

PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor,
                             PT_TreeVisitorData data)
{
  ATermList store;
  PT_Args newArgs = PT_makeArgsEmpty();

  /* apply func to each element */
  for (store = ATempty;
      PT_hasArgsHead(args);
      args = PT_getArgsTail(args)) {
    store = ATinsert(store,
                     PT_makeTermFromTree(
                     visitor(PT_getArgsHead(args),data)));
  }

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Tree newTree = PT_makeTreeFromTerm(ATgetFirst(store));
    newArgs = PT_makeArgsList(newTree,newArgs);
  }

  return newArgs;
}

/*}}}  */
/*{{{  PT_Symbols PT_foreachSymbolInSymbols(symbols, visitor, data)  */

PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols, PT_SymbolVisitor visitor, 
                                     PT_SymbolVisitorData data) 
{
  ATermList store;
  PT_Symbols newSymbols = PT_makeSymbolsEmpty();

  /* apply func to each element */
  store = ATempty;
  while (PT_hasSymbolsHead(symbols)) {
    store = ATinsert(store,
                     PT_makeTermFromSymbol(
                     visitor(PT_getSymbolsHead(symbols), data)));
    if (PT_hasSymbolsTail(symbols)) {
      symbols = PT_getSymbolsTail(symbols);
    }
    else {
      break;
    }
  }

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Symbol newSymbol = PT_makeSymbolFromTerm(ATgetFirst(store));
    newSymbols = PT_makeSymbolsList(newSymbol,newSymbols);
  }

  return newSymbols;
}

/*}}}  */

/*{{{  int PT_getSymbolsLength(PT_Symbols symbols) */

int PT_getSymbolsLength(PT_Symbols symbols)
{
  return ATgetLength((ATermList)PT_makeTermFromSymbols(symbols));
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolsSymbolAt(PT_Symbols symbols, int index) */

PT_Symbol PT_getSymbolsSymbolAt(PT_Symbols symbols, int index)
{
  return PT_makeSymbolFromTerm(
           ATelementAt((ATermList)PT_makeTermFromSymbols(symbols), index));
}

/*}}}  */

PT_Symbols PT_appendSymbols(PT_Symbols symbols, PT_Symbol symbol)
{
  return PT_makeSymbolsFromTerm(
           (ATerm)ATappend((ATermList)PT_makeTermFromSymbols(symbols),
                           PT_makeTermFromSymbol(symbol)));

}

/*{{{  PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor, */

PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor,
                               PT_AttrVisitorData data)
{
  ATermList store;
  PT_Attrs newAttrs;

  /* apply func to each element */
  store = ATempty;
  while (PT_hasAttrsHead(attrs)) {
    store = ATinsert(store,
                     PT_makeTermFromAttr(
                     visitor(PT_getAttrsHead(attrs), data)));
    if (PT_hasAttrsTail(attrs)) { 
      attrs = PT_getAttrsTail(attrs);
    } 
    else {
      break;
    }
  }

  if (ATisEmpty(store)) {
    ATerror("PT_foreachAttrInAttrs: plus list contains no elements");
    return (PT_Attrs) NULL;
  }

  newAttrs = PT_makeAttrsSingle(PT_makeAttrFromTerm(ATgetFirst(store)));
  store = ATgetNext(store);

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Attr newAttr = PT_makeAttrFromTerm(ATgetFirst(store));
    newAttrs = PT_makeAttrsMany(newAttr,newAttrs);
  }

  return newAttrs;
}

/*}}}  */

/*{{{  static PT_Attr PT_matchAttr(PT_Attr attr, PT_AttrVisitorData data) */

/*{{{  typedef struct PT_BoolAttrTuple_Tag */

typedef struct PT_BoolAttrTuple_Tag {
  ATbool bool;
  PT_Attr attr;
} PT_BoolAttrTuple;


/*}}}  */

static PT_Attr PT_matchAttr(PT_Attr attr, PT_AttrVisitorData data)
{
  if (PT_isEqualAttr(((PT_BoolAttrTuple*)data)->attr,attr)) {
    ((PT_BoolAttrTuple*)data)->bool = ATtrue;
  }

  return attr;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr) */

ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr)
{
  PT_Attributes attributes = PT_getProductionAttributes(prod);
  PT_Attrs attrs;
  PT_BoolAttrTuple data;

  if (PT_isAttributesNoAttrs(attributes)) {
    return ATfalse;
  } 

  attrs = PT_getAttributesAttrs(attributes); 

  data.bool = ATfalse;
  data.attr = attr;

  PT_foreachAttrInAttrs(attrs, PT_matchAttr, (PT_AttrVisitorData)&data);

  return data.bool;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionBracketAttr(PT_Production prod) */

ATbool PT_hasProductionBracketAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrBracket());
}

/*}}}  */
/*{{{  ATbool PT_hasProductionMemoAttr(PT_Production prod) */

ATbool PT_hasProductionMemoAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrMemo());
}

/*}}}  */
/*{{{  ATbool PT_hasProductionTraverseAttr(PT_Production prod) */

ATbool PT_hasProductionTraverseAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrTraverse());
}

/*}}}  */
/*{{{  PT_Tree PT_removeTreeAnnotations(PT_Tree arg) */

PT_Tree PT_removeTreeAnnotations(PT_Tree arg)
{
  ATerm atArg = PT_makeTermFromTree(arg);
  
  if (AT_getAnnotations(atArg) != NULL) {
    atArg = AT_removeAnnotations(atArg);
  }

  return PT_makeTreeFromTerm(atArg);
}

/*}}}  */
/*{{{  ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key) */

ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key)
{
  ATerm atTree = PT_makeTermFromTree(tree);

  return ATgetAnnotation(atTree, key);
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value) */

PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value)
{
  ATerm t = PT_makeTermFromTree(tree);

  t = ATsetAnnotation(t, key, value);

  return PT_makeTreeFromTerm(t);
}

/*}}}  */
/*{{{  ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key) */

ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key)
{
  ATerm atParseTree = PT_makeTermFromParseTree(parse_tree);

  return ATgetAnnotation(atParseTree, key);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeAnnotation(parse_tree, ATerm key, ATerm value) */

PT_ParseTree PT_setParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key, ATerm value)
{
  ATerm t = PT_makeTermFromParseTree(parse_tree);

  t = ATsetAnnotation(t, key, value);

  return PT_makeParseTreeFromTerm(t);
}

/*}}}  */
/*{{{  int PT_getArgsLength(PT_Args args) */

int PT_getArgsLength(PT_Args args)
{
   return ATgetLength((ATermList)PT_makeTermFromArgs(args));
}

/*}}}  */

/*{{{  static PT_Args annotateArgsWithLength(PT_Args args, int *length) */

static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length);

static PT_Args annotateArgsWithLength(PT_Args args, int *length)
{
  PT_Tree head;
  PT_Args tail;
  int head_length, tail_length;

  if (PT_isArgsEmpty(args)) {
    *length = 0;
    return args;
  }

  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);

  head = annotateTreeWithLength(head, &head_length);
  tail = annotateArgsWithLength(tail, &tail_length);

  *length = head_length + tail_length;

  return PT_makeArgsList(head, tail);
}

/*}}}  */
/*{{{  static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length) */

static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length)
{
  if (PT_hasTreeString(tree)) {
    *length = strlen(PT_getTreeString(tree));
  }
  else if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = annotateArgsWithLength(args, length);
    tree = PT_setTreeArgs(tree, args);
  }
  else {
    ATerror("unknown tree type: %t\n", PT_makeTermFromTree(tree));
  }

  return PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
			      ATmake("<int>", *length));

}

/*}}}  */
/*{{{  PT_Tree PT_annotateTreeWithLength(PT_Tree tree) */

PT_Tree PT_annotateTreeWithLength(PT_Tree tree)
{
  int length;

  return annotateTreeWithLength(tree, &length);
}

/*}}}  */
/*{{{  PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree) */

PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree)
{
  int length;

  PT_Tree tree = PT_getParseTreeTree(parse_tree);
  tree = PT_annotateTreeWithLength(tree);

  length = PT_getTreeLengthAnno(tree);
  length += strlen(PT_getParseTreeLayoutBeforeTree(parse_tree));
  length += strlen(PT_getParseTreeLayoutAfterTree(parse_tree));
  
  parse_tree = PT_setParseTreeTree(parse_tree, tree);
  parse_tree = PT_setParseTreeLengthAnno(parse_tree, length);

  return parse_tree;
}

/*}}}  */
/*{{{  int PT_getParseTreeLengthAnno(PT_ParseTree parse_tree) */

int PT_getParseTreeLengthAnno(PT_ParseTree parse_tree)
{
  ATerm anno = PT_getParseTreeAnnotation(parse_tree, ATparse(ANNO_LENGTH));

  assert(anno && ATgetType(anno) == AT_INT);

  return ATgetInt((ATermInt)anno);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length) */

PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length)
{
  return PT_setParseTreeAnnotation(parse_tree, ATparse(ANNO_LENGTH),
				   (ATerm)ATmakeInt(length));
}

/*}}}  */
/*{{{  int PT_getTreeLengthAnno(PT_Tree tree) */

int PT_getTreeLengthAnno(PT_Tree tree)
{
  ATerm anno = PT_getTreeAnnotation(tree, ATparse(ANNO_LENGTH));
  assert(anno);
  return ATgetInt((ATermInt)anno);
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length) */

PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length)
{
  return PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
			     (ATerm)ATmakeInt(length));
}

/*}}}  */
/*{{{  PT_Attrs PT_reverseAttrs(PT_Attrs attrs) */
PT_Attrs PT_reverseAttrs(PT_Attrs attrs)
{
  return PT_makeAttrsFromTerm(
           (ATerm)ATreverse(
                    (ATermList)PT_makeTermFromAttrs(attrs)));
}

/*}}}  */
