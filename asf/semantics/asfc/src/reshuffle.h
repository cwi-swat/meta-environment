#ifndef _RESHUFFLE_H
#define _RESHUFFLE_H   

#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <ASFME-utils.h> 

char *get_output_dir(void);
void generateCode(char *modname, ATerm module);

void compileModules(char *modname,
                    SDF_ModuleList modList, 
                    ASF_CondEquationList eqsList);

PT_Production makeLexicalConstructorProd(SDF_Symbol symbol);

PT_Production flattenSdfProduction(SDF_Production sdfProduction,
                                   SDF_ModuleName sdfModuleName);  

#endif /* _RESHUFFLE_H */
