/*$Id$*/

/** \file
 * \ingroup parseTable
 */

#ifndef _INTERNALPARSETABLE_H_
#define _INTERNALPARSETABLE_H_

#include <aterm2.h>
#include <Error-utils.h>
#include <MEPT.h>
#include "tokens.h"
#include "ptable.h" /* ptable-support */

typedef struct _ParseTable ParseTable;

typedef enum _ActionKind {ERROR, SHIFT, REDUCE, REDUCE_LA, ACCEPT}  ActionKind;

int    SGLR_PTBL_getStartState(ParseTable *pt);
size_t SGLR_PTBL_getNumberOfStates(ParseTable *pt);
size_t SGLR_PTBL_getNumberOfProductions(ParseTable *pt);
int    SGLR_PTBL_getMaxProductionLength(ParseTable *pt);

ATbool SGLR_PTBL_hasPriorities(ParseTable *pt);
ATbool SGLR_PTBL_hasRejects(ParseTable *pt);
ATbool SGLR_PTBL_hasPrefers(ParseTable *pt);
ATbool SGLR_PTBL_hasAvoids(ParseTable *pt);
ATbool SGLR_PTBL_hasPreferences(ParseTable *pt);


PTBL_Actions SGLR_PTBL_lookupAction(ParseTable *pt, int s, Token c);
int          SGLR_PTBL_lookupGoto(ParseTable *pt, int s, int l);
PT_Production  SGLR_PTBL_lookupProduction(ParseTable *pt, int c);
PT_Production  SGLR_PTBL_lookupBracketProd(ParseTable *pt, PT_Symbol r);
ATbool    SGLR_PTBL_prodIsInjection(ParseTable *pt, PT_Production p);
ATbool    SGLR_PTBL_prodIsUserDefinedInjection(ParseTable *pt, PT_Production p);
ATbool    SGLR_PTBL_hasProductionPriority(ParseTable *pt, PT_Production p);
ATermList SGLR_PTBL_lookupGtrPriority(ParseTable *pt, PT_Production p);
ATbool    SGLR_PTBL_isPriorityGreater(ParseTable *pt, int argNumber, PT_Production p0, PT_Production p1);


size_t SGLR_PTBL_countGotos(register PTBL_Gotos goto_lst);
size_t SGLR_PTBL_countChoices(register PTBL_Choices choices); 

ParseTable *SGLR_PTBL_initializeParseTable(int startState, size_t numstates, size_t numprods, size_t action_entries, size_t goto_entries, const char *path);
  
void SGLR_PTBL_fillParseTable(ParseTable *pt, PTBL_States states);
void SGLR_PTBL_processProductions(ParseTable *pt, PTBL_Labels prods);
void SGLR_PTBL_processPriorities(ParseTable *pt, register PTBL_Priorities prios);

ActionKind  SGLR_PTBL_actionKind(PTBL_Action a);

void        SGLR_PTBL_initErrorList();
void        SGLR_PTBL_addErrorError(const char *path, const char *desc);
ATbool      SGLR_PTBL_isErrorListEmpty();
ERR_Error   SGLR_PTBL_makeErrorError();
ERR_Summary SGLR_PTBL_makeErrorSummary(const char *path);

void        SGLR_PTBL_discardParseTable(ParseTable *pt);

#endif /* _INTERNALPARSETABLE_H_ */
