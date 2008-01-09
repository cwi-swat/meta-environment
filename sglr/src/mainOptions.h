/*$Id$*/

#ifndef __MAIN_OPTIONS_H__
#define __MAIN_OPTIONS_H__

#include <aterm2.h>
#include <options.h>

extern int SGLR_STATS_FLAG;

void MAIN_initializeDefaultOptions();

void         MAIN_setFlattenTreeFlag(ATbool value);
ATbool       MAIN_getFlattenTreeFlag();
void         MAIN_setTextualOutputFlag(ATbool value); 
ATbool       MAIN_getTextualOutputFlag();
void         MAIN_setOutputFileName(const char* outputFileName);
const char  *MAIN_getOutputFileName();
void         MAIN_setInputFileName(const char* inputFileName);
const char  *MAIN_getInputFileName();
void         MAIN_setParseTableName(const char* parseTableName);
const char  *MAIN_getParseTableName();
void         MAIN_setCountPosIndependentAmbsFlag(ATbool flag);
ATbool       MAIN_getCountPosIndependentAmbsFlag();
void         MAIN_setStatsFlag();
#define MAIN_getStatsFlag (OPT_getFlag(SGLR_STATS_FLAG))
void         MAIN_setStatsFilename(const char* statsFilename);
const char  *MAIN_getStatsFileName();

#endif /* __MAIN_OPTIONS_H__ */
