/* $Id$ */

/** \file 
 * \ingroup utils
 */

#include "marking.h"
#include <aterm2.h>

static ATermIndexedSet marks = NULL;
static const int INITIAL_TABLE_SIZE = 1024;
static const int LOAD_PERCENTAGE = 75;

void SG_cleanupMarks(void)
{
  ATindexedSetDestroy(marks);

  marks = NULL;
}

void SG_initMarks(void)
{
  marks = ATindexedSetCreate(INITIAL_TABLE_SIZE, LOAD_PERCENTAGE);

  if (marks == NULL) {
    ATerror("SG_initMarks: unable to allocate table for marking.");
  }
}

void SG_Mark(ATerm t)
{
  ATindexedSetPut(marks, (ATerm) t, NULL);
}

void SG_UnMark(ATerm t)
{
  ATindexedSetRemove(marks, (ATerm) t);
}

ATbool SG_IsMarked(ATerm t)
{
  if (ATindexedSetGetIndex(marks, t) == -1) {
    return ATfalse;
  }

  return ATtrue;
}
