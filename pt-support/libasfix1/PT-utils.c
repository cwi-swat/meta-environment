
#include "PT-utils.h"

ATbool PT_isSymbolIter(PT_Symbol arg)
{
  return PT_isSymbolIterStarSep(arg) ||
         PT_isSymbolIterStar(arg)    ||
         PT_isSymbolIterPlusSep(arg) ||
         PT_isSymbolIterPlus(arg);
}

ATbool PT_isListVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getTreeSymbol(arg);
   
    return PT_isSymbolIter(symbol); 
  }

  return ATfalse;
}

ATbool PT_isStarVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getTreeSymbol(arg);
   
    return PT_isSymbolIterStar(symbol) || PT_isSymbolIterStarSep(symbol); 
  }

  return ATfalse;
}

ATbool PT_isPlusVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getTreeSymbol(arg);
   
    return PT_isSymbolIterPlus(symbol) || PT_isSymbolIterPlusSep(symbol); 
  }

  return ATfalse;
}

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2)
{
  return PT_makeArgsFromTerm((ATerm)ATconcat(
                                      (ATermList)PT_makeTermFromArgs(args1),
                                      (ATermList)PT_makeTermFromArgs(args2)));
}

PT_Args PT_appendArgs(PT_Args args, PT_Tree arg)
{
  return PT_makeArgsFromTerm((ATerm)ATappend(
                                      (ATermList)PT_makeTermFromArgs(args),
                                      (ATerm)PT_makeTermFromTree(arg)));
}

PT_Tree PT_getArgsTreeAt(PT_Args args, int index)
{
  return PT_makeTreeFromTerm(
           ATelementAt((ATermList)PT_makeTermFromArgs(args), index));
}

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

PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols, 
                                     PT_SymbolVisitor visitor, 
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

int PT_getSymbolsLength(PT_Symbols symbols)
{
  return ATgetLength((ATermList)PT_makeTermFromSymbols(symbols));
}

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

typedef struct PT_BoolAttrTuple_Tag {
  ATbool bool;
  PT_Attr attr;
} PT_BoolAttrTuple;

static PT_Attr PT_matchAttr(PT_Attr attr, PT_AttrVisitorData data)
{
  if (PT_isEqualAttr(((PT_BoolAttrTuple*)data)->attr,attr)) {
    ((PT_BoolAttrTuple*)data)->bool = ATtrue;
  }

  return attr;
}

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

ATbool PT_hasProductionBracketAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrBracket());
}

ATbool PT_hasProductionMemoAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrMemo());
}

ATbool PT_hasProductionTraverseAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrTraverse());
}

PT_Tree PT_removeTreeAnnotations(PT_Tree arg)
{
  ATerm atArg = PT_makeTermFromTree(arg);
  
  if (AT_getAnnotations(atArg) != NULL) {
    atArg = AT_removeAnnotations(atArg);
  }

  return PT_makeTreeFromTerm(atArg);
}

ATerm PT_getTreeAnnotation(PT_Tree arg, ATerm label)
{
  ATerm atArg = PT_makeTermFromTree(arg);

  return ATgetAnnotation(atArg, label);
}

int PT_getArgsLength(PT_Args args)
{
   return ATgetLength((ATermList)PT_makeTermFromArgs(args));
}
