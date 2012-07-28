/* $Id$ */

/** \file 
 * \ingroup parser
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#include <MEPT.h>
#include "parseTable.h"
#include "inputString-data.h"

PT_Tree SG_parse(ParseTable *parseTable, InputString string);

#endif  /* _PARSER_H_ */
