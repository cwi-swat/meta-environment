#ifndef _SDF2PT_H
#define _SDF2PT_H

#include <PT-utils.h>
#include <SDF-utils.h>
#include <ASF-utils.h> 

PT_Production
makeLexicalConstructorProd(SDF_Symbol symbol);

PT_Production flattenSdfProduction(SDF_Production sdfProduction,
                                   SDF_ModuleName sdfModuleName);

#endif /* _SDF2PT_H */ 
