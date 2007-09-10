/*$Id$*/

/** \file
 * \ingroup gss
 */

#ifndef _SHIFT_QUEUE_
#define _SHIFT_QUEUE_

#include "gssNode-api.h"

typedef struct _StatesToBeShifted *StatesToBeShifted;

void    GSS_removeShiftQueueElement(void);
void    GSS_resetShiftQueue(void);
void    GSS_addShiftQueueElement(int stateNum, GSSNode node);
int     GSS_getShiftQueueStateNumber(void);
GSSNode GSS_getShiftQueueGSSNode(void);
ATbool  GSS_isShiftQueueEmpty(void);

#endif
