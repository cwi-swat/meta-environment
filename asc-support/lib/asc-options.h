/* $Id$ */
#ifndef __ASC_OPTIONS_H__
#define __ASC_OPTIONS_H__

#include <aterm2.h>

void ASC_initializeDefaultOptions();

void ASC_setVerboseFlag(ATbool value);
void ASC_setPrefixFunction(const char *function);
void ASC_setOutputFilename(const char *output);
void ASC_setResultNonTermName(const char *result);
void ASC_setStatsFlag(ATbool value);
void ASC_setBafmodeFlag(ATbool value);
void ASC_setOutputFlag(ATbool value);
void ASC_setNumberOfParseTrees(int nInputs);

ATbool ASC_getVerboseFlag();
const char *ASC_getPrefixFunction();
const char *ASC_getOutputFilename();
const char *ASC_getResultNonTermName();
ATbool ASC_getStatsFlag();
ATbool ASC_getBafmodeFlag();
ATbool ASC_getOutputFlag(); 
int ASC_getNumberOfParseTrees();

#endif /* __ASC_OPTIONS_H__ */
