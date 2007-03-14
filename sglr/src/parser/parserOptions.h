/* $Id$ */

/** \file
 * \ingroup parser
 */

#include <aterm2.h>
#include <options.h>

extern int VERBOSE_FLAG;
extern int DEBUG_FLAG;
extern int STATS_FLAG;
extern int OUTPUT_FLAG;
extern int AMBIGUITY_ERROR_FLAG;

void PARSER_initializeDefaultOptions();
void   PARSER_setVerboseFlag(ATbool value);
ATbool PARSER_getVerboseFlag();
void   PARSER_setDebugFlag(ATbool value);
void   PARSER_setStatsFlag(ATbool value);
ATbool PARSER_getStatsFlag();
void   PARSER_setOutputFlag(ATbool value);
ATbool PARSER_getOutputFlag();
void   PARSER_setAmbiguityErrorFlag(ATbool value);
ATbool PARSER_getAmbiguityErrorFlag();

#define PARSER_getDebugFlag (OPT_getFlag(DEBUG_FLAG))
