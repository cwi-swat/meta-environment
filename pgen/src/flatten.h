#ifndef FLATTEN_H
#define FLATTEN_H 

#include "ksdf2table.h"

ATerm SDFflattenProd(ATerm prod);
ATerm SDFflattenSymbol(ATerm symbol);
ATerm SDFflattenLookAhead(ATerm prod, ATbool nested); 

#endif
