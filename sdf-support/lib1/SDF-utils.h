#ifndef _SDF_UTILS_H
#define _SDF_UTILS_H

#include "SDF.h"

char      *SDFgetModuleName (SDF_Module sdfModule);

ATermList  SDFgetGrammars              (SDF_Module module);
typedef    void (*SDFGrammarFunc)      (SDF_Grammar, ATerm *);
void       SDFforeachGrammar           (SDF_Grammar     grammar,
					SDFGrammarFunc  func,
					void           *user_data);
void       SDFforeachGrammarInSections (SDF_Sections    sections,
					SDFGrammarFunc  func,
					void           *user_data);
void       SDFforeachGrammarInModule   (SDF_Module      module,
					SDFGrammarFunc  func,
					void           *user_data);


ATermList  SDFgetImports    (SDF_Module module);

ATermList  SDFgetLexicalProductions(SDF_Module module);

#endif /* _SDF_UTILS_H */
