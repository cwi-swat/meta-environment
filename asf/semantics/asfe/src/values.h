#ifndef VALUES_H
#define VALUES_H

#include <MEPT-utils.h>

typedef ATermAppl Slice;
PT_Args appendSlice(PT_Args list, Slice slice);

#define ASFtoPT(tree) (PT_makeTreeFromTerm(ASF_makeTermFromTree(tree)))
#define PTtoASF(tree) (ASF_makeTreeFromTerm(PT_makeTermFromTree(tree)))

#define isAsFixEqual(t1,t2) (isEqualModuloWhitespace(t1,t2))
ATbool isEqualModuloWhitespace(PT_Tree asfix1, PT_Tree asfix2);
PT_Tree getFirstArgument(PT_Tree trm);
PT_Args concatElems(PT_Production listProd, PT_Args elems, PT_Args newElems);
PT_Args skipWhitespaceAndSeparator(PT_Args list, PT_Production listProd);
PT_Args prependSlice(Slice slice, PT_Args list);
PT_Args addElemsToArgs(PT_Production listProd, PT_Args elems, PT_Args args);
PT_Args appendElem(PT_Production listProd, PT_Args elems, PT_Tree elem);
PT_Args skipWhitespace(PT_Args list);

#endif
