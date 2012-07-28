#include <MEPT-utils.h>
#include <assert.h>

#define AMB_CONSTRUCTOR_ATTR "cons(\"ambiguity-constructor\")"

static PT_Attr AmbConstructor = NULL;

PT_Tree ASC_ambToConstructor(PT_Tree amb) 
{
  PT_Args ambs;
  PT_Args elems;
  PT_Tree l;
  PT_Tree c;
  PT_Symbol symbol = NULL;
  PT_Symbol listSymbol;
  PT_Tree list;
  PT_Attributes attributes;
  PT_Tree result;
  ATerm annos;

  assert(PT_isTreeAmb(amb));

  annos = PT_getTreeAnnotations(amb);

  ambs = PT_getTreeArgs(amb);
  elems = PT_makeArgsEmpty();
  l = PT_makeTreeLayoutEmpty();
  c = PT_makeTreeLit(",");

  while (PT_hasArgsHead(ambs)) {
    PT_Tree alt = PT_getArgsHead(ambs);
    ambs = PT_getArgsTail(ambs);
    elems = PT_makeArgsMany(alt, elems);

    if (PT_hasArgsHead(ambs)) {
      elems = PT_makeArgsMany(l, elems);
      elems = PT_makeArgsMany(c, elems);
      elems = PT_makeArgsMany(l, elems);
    }
    else {
      symbol = PT_getProductionRhs(PT_getTreeProd(alt));
    }
  }

  assert(symbol != NULL);
  if (PT_isSymbolCf(symbol)) {
    listSymbol = PT_makeSymbolIterStarSep(PT_getSymbolSymbol(symbol), 
					  PT_makeSymbolLit(","));
    listSymbol = PT_makeSymbolCf(listSymbol);
    list = PT_makeTreeAppl(PT_makeProductionList(listSymbol), elems);
  }
  else {
    /* TODO: support kernel and lexical ambiguities */
    return amb;
  }

  if (AmbConstructor == NULL) {
    AmbConstructor = PT_makeAttrTerm(ATparse(AMB_CONSTRUCTOR_ATTR));
    PT_protectAttr(&AmbConstructor);
  }

  attributes = PT_makeAttributesAttrs(PT_makeAttrsSingle(
			 PT_makeAttrTerm(ATparse(AMB_CONSTRUCTOR_ATTR))));

  result =  PT_applyFunction("amb", symbol, PT_makeArgsSingle(list),
			  attributes);

  if (annos != NULL) {
    result = PT_setTreeAnnotations(result, annos);
  }

  return result;
}

ATbool ASC_isAmbiguityConstructor(PT_Tree tree) 
{
  if (AmbConstructor == NULL) {
    AmbConstructor = PT_makeAttrTerm(ATparse(AMB_CONSTRUCTOR_ATTR));
    PT_protectAttr(&AmbConstructor);
  }

  if (PT_hasTreeProd(tree)) {
    return PT_hasProductionCertainAttr(PT_getTreeProd(tree),
				       AmbConstructor);
  }
  return ATfalse;
}
  
PT_Tree ASC_constructorToAmb(PT_Tree tree) 
{
  PT_Tree list;
  PT_Args args;
  PT_Args ambs;
  ATerm annos;
  PT_Tree result;

  annos = PT_getTreeAnnotations(tree);

  if(!ASC_isAmbiguityConstructor(tree)) {
    return tree;
  }

  list = PT_getArgsTreeAt(PT_getTreeArgs(tree), 4);
  args = PT_getTreeArgs(list);

  ambs = PT_makeArgsEmpty();

  while (PT_hasArgsHead(args)) {
    PT_Tree head = PT_getArgsHead(args);

    args = PT_getArgsTail(args);
    ambs = PT_makeArgsMany(head, ambs);

    if (PT_hasArgsHead(args)) {
      assert(PT_getArgsLength(args) >= 3);
      args = PT_getArgsTail(args);
      args = PT_getArgsTail(args);
      args = PT_getArgsTail(args);
    }
  }

  result = PT_makeTreeAmb(ambs);

  if (annos != NULL) {
    result = PT_setTreeAnnotations(result, annos);
  }

  return result;
}
