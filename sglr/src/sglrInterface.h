/*  $Id$  */

/*
 * The interface to the public SGLR functions.
 */

#ifndef _SGLR_INTERFACE_H_
#define _SGLR_INTERFACE_H_  1

#include <aterm1.h>
#include <aterm2.h>
#include <MEPT.h>
#include <parserOptions.h>
#include <Error.h>

#include "ptable.h"
#include "inputString-data.h"

typedef struct _apigen_prepared *SGLR_ParseTable;

void SGLR_initialize();
ATbool SGLR_isInitialized();

int SGLR_loadParseTable(const char *parseTableName, PTBL_ParseTable tbl);
ATbool SGLR_isParseTableLoaded(const char *parseTableName);

ERR_Summary SGLR_getErrorSummary();
void SGLR_resetErrorSummary();
PT_ParseTree SGLR_parse(InputString inputString, const char *parseTableName);

#endif  /* _SGLR_INTERFACE_H_ */
