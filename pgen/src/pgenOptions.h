/* $Id$ */

#ifndef __PGEN_OPTIONS_H__
#define __PGEN_OPTIONS_H__

#include <aterm2.h>
#include <options.h>

extern int PGEN_STATS_FLAG;
extern int PGEN_VERBOSE_MODE_FLAG;

void PGEN_initializeDefaultOptions(void);

void PGEN_setSafModeFlag(ATbool value);
ATbool PGEN_getSafModeFlag(void);
void PGEN_setCollectFlag(ATbool value);
ATbool PGEN_getCollectFlag(void);
void PGEN_setGenerationModeFlag(ATbool value);
ATbool PGEN_getGenerationModeFlag(void);
void PGEN_setInputFilename(const char *value);
const char *PGEN_getInputFilename(void);
void PGEN_setStatsFlag(ATbool value);
/*ATbool PGEN_getStatsFlag(void);*/
#define PGEN_getStatsFlag (OPT_getFlag(PGEN_STATS_FLAG))
void PGEN_setStatsFilename(const char* statsFilename);
const char *PGEN_getStatsFileName();
void PGEN_setTopModule(const char *value);
const char *PGEN_getTopModule(void);
void PGEN_setNormalizationModeFlag(ATbool value);
ATbool PGEN_getNormalizationModeFlag(void);
void PGEN_setDefinitionModeFlag(ATbool value);
ATbool PGEN_getDefinitionModeFlag(void);
void PGEN_setOutputFilename(const char *value);
const char *PGEN_getOutputFilename(void);
void PGEN_setSearchPath(const char *value);
const char *PGEN_getSearchPath(void);
void PGEN_setVerboseModeFlag(ATbool value);
/*ATbool PGEN_getVerboseModeFlag(void);*/
#define PGEN_getVerboseModeFlag (OPT_getFlag(PGEN_VERBOSE_MODE_FLAG))

#endif /* __PGEN_OPTIONS_H__ */
