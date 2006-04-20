#ifndef ASC_AMBIGUITY_H
#define ASC_AMBIGUITY_H
#include <MEPT.h>

PT_Tree ASC_ambToConstructor(PT_Tree amb);
ATbool ASC_isAmbiguityConstructor(PT_Tree tree);
PT_Tree ASC_constructorToAmb(PT_Tree tree);

#endif /* ASC_AMBIGUITY_H */
