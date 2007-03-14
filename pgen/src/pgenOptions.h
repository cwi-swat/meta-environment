/* $Id$ */

#ifndef __PGEN_OPTIONS_H__
#define __PGEN_OPTIONS_H__

#include <aterm2.h>

void PGEN_initializeDefaultOptions(void);

void PGEN_setBafModeFlag(ATbool value);
ATbool PGEN_getBafModeFlag(void);
void PGEN_setATermDebugFlag(ATbool value);
ATbool PGEN_getATermDebugFlag(void);
void PGEN_setGenerationModeFlag(ATbool value);
ATbool PGEN_getGenerationModeFlag(void);
void PGEN_setInputFilename(const char *value);
const char *PGEN_getInputFilename(void);
void PGEN_setStatsFlag(ATbool value);
ATbool PGEN_getStatsFlag(void);
void PGEN_setTopModule(const char *value);
const char *PGEN_getTopModule(void);
void PGEN_setNormalizationModeFlag(ATbool value);
ATbool PGEN_getNormalizationModeFlag(void);
void PGEN_setOutputFilename(const char *value);
const char *PGEN_getOutputFilename(void);
void PGEN_setVerboseModeFlag(ATbool value);
ATbool PGEN_getVerboseModeFlag(void);

#endif /* __PGEN_OPTIONS_H__ */
