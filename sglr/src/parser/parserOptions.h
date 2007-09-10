/* $Id$ */

/** \file
 * \ingroup parser
 */

#ifndef __PARSER_OPTIONS_H__
#define __PARSER_OPTIONS_H__

#include <aterm2.h>
#include <options.h>

extern int VERBOSE_FLAG;
extern int DEBUG_FLAG;

void PARSER_initializeDefaultOptions();
void   PARSER_setVerboseFlag(ATbool value);
#define PARSER_getVerboseFlag (OPT_getFlag(VERBOSE_FLAG))
void   PARSER_setDebugFlag(ATbool value);
#define PARSER_getDebugFlag (OPT_getFlag(DEBUG_FLAG))
void   PARSER_setOutputFlag(ATbool value);
ATbool PARSER_getOutputFlag();
void   PARSER_setAmbiguityErrorFlag(ATbool value);
ATbool PARSER_getAmbiguityErrorFlag();

#endif /* __PARSER_OPTIONS_H__ */
