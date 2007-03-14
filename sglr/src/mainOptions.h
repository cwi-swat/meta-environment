/*$Id$*/

#ifndef __MAIN_OPTIONS_H__
#define __MAIN_OPTIONS_H__

#include <aterm2.h>

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

#endif /* __MAIN_OPTIONS_H__ */
