#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <stdio.h>
#include <aterm1.h>

#define BITS_PER_LONG (sizeof(unsigned long)*8)
#define CC_BITS	      257
#define CC_LONGS      (((CC_BITS-1)/BITS_PER_LONG)+1)

#define CC_EOF	       256

typedef unsigned long CC_Class[CC_LONGS];
typedef struct
{
  int max_size;
  int size;
  CC_Class *classes;
} CC_Set;

void	 CC_init();

CC_Class *CC_alloc();
void     CC_free(CC_Class *c);
CC_Class *CC_makeClassEmpty();
CC_Class *CC_makeClassAllChars();
CC_Class *CC_ClassFromInt(ATermInt i);
CC_Class *CC_ClassFromTerm(ATerm t);
ATerm	 CC_ClassToTerm(CC_Class *cc);
void     CC_addATermClass(CC_Class *cc, ATerm t);

void CC_addChar(CC_Class *cc, int c);
void CC_addRange(CC_Class *cc, int start, int end);
void CC_removeChar(CC_Class *cc, int c);

void CC_clear(CC_Class *cc);
ATbool CC_copy(CC_Class *source, CC_Class *dest);
ATbool CC_union(CC_Class *cc1, CC_Class *cc2, CC_Class *result);
ATbool CC_intersection(CC_Class *cc1, CC_Class *cc2, CC_Class *result);
ATbool CC_difference(CC_Class *cc, CC_Class *to_remove, CC_Class *result);
ATbool CC_complement(CC_Class *cc, CC_Class *result);

ATbool	 CC_containsChar(CC_Class *cc, int c);
ATbool   CC_isEmpty(CC_Class *cc);
ATbool	 CC_isEOF(CC_Class *cc);
ATbool   CC_isSubset(CC_Class *needle, CC_Class *haystack);
ATbool   CC_isEqual(CC_Class *cc1, CC_Class *cc2);

void     CC_writeToFile(FILE *f, CC_Class *cc);

void      CC_initSet(CC_Set *set);
void      CC_initSetWithSize(CC_Set *set, int size);
void	  CC_copySet(CC_Set *source, CC_Set *dest);
void      CC_flushSet(CC_Set *set);
void      CC_clearSet(CC_Set *set);
CC_Class *CC_addToSet(CC_Set *set);
CC_Class *CC_getFromSet(CC_Set *set, int elem);
void      CC_partitionSet(CC_Set *set);
int       CC_getSetSize(CC_Set *set);
void      CC_writeSetToFile(FILE *f, CC_Set *set);
void      CC_SetIntersection(CC_Set *set, CC_Class *cc, CC_Set *result);
void      CC_SetDifference(CC_Set *set, CC_Class *cc, CC_Set *result);

#endif
