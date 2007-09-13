/*$Id$*/

/** \file
 * \ingroup gss 
 *
 * This file implements the constructor, destructor and accessor functions for
 * a \ref _StatesToBeShifted "shift queue". A shift queue is used to store the 
 * pending shift actions of a level in the GSS. It is equivalent to the set 
 * \f$\mathcal{Q}\f$ in Tomita-style GLR parsing algorithms.
 *
 * \todo Review memory allocation technique and memory management.
 */

#include "shiftQueue.h"
#include "mem-alloc.h"
#include "parserStatistics.h"

static const int BLOCK_SIZE = 16;


/** 
 * This struct is used by the \ref shifter() "parser" to store the pending 
 * shift actions from the current level in the GSS.
 */
struct _StatesToBeShifted {
  int     stateNumber;/**<the state number of the GSS node to be shifted from.*/
  GSSNode gssNode;    /**<the target GSS node of the shift. */
};

static StatesToBeShifted statesToBeShifted = NULL;
static int size = 0;
static int startOfQueue = 0;
static int endOfQueue = 0;


/** 
 * Adds the given state number to shift to and the GSS node to shift from to 
 * the shift queue.
 * 
 * \param stateNum the state number to shift to.
 * \param node the GSS node to shift from.
 */
void GSS_addShiftQueueElement(int stateNum, GSSNode node) {

  if(statesToBeShifted == NULL) {
    size = BLOCK_SIZE;
    statesToBeShifted = malloc(BLOCK_SIZE * sizeof(struct _StatesToBeShifted));
    if (statesToBeShifted == NULL) {
      ATerror("%s:%d Could not allocate %d bits of memory\n", __FILE__, 
	      __LINE__, BLOCK_SIZE * sizeof(struct _StatesToBeShifted));
    }
  }

  if(endOfQueue >= size) {
    size += BLOCK_SIZE;
    statesToBeShifted = realloc(statesToBeShifted, 
				size * sizeof(struct _StatesToBeShifted));
    if (statesToBeShifted == NULL) {
      ATerror("%s:%d Could not allocate %d bits of memory\n", __FILE__, 
	      __LINE__, size * sizeof(struct _StatesToBeShifted));
    }
  }

  statesToBeShifted[endOfQueue].stateNumber = stateNum;
  statesToBeShifted[endOfQueue].gssNode = node;
  endOfQueue++;

  SGLR_STATS_incrementCount(SGLR_STATS_shiftsAddedToShiftQueue);
}

/** 
 * Resets the shift queue.
 */
void GSS_resetShiftQueue(void) {
  if (SGLR_STATS_maxSizeOfShiftQueue < endOfQueue) {
    SGLR_STATS_setCount(SGLR_STATS_maxSizeOfShiftQueue, endOfQueue);
  }

  startOfQueue = 0;
  endOfQueue = 0;
}

/** 
 * Removes the current element from the shift queue.
 */
void GSS_removeShiftQueueElement(void) {  
  startOfQueue++;
}

/** 
 * Returns the current \ref _StatesToBeShifted::stateNumber "state number" in 
 * the shift queue.
 * 
 * \return the current state number in the shift queue.
 */
int GSS_getShiftQueueStateNumber(void) {
  return statesToBeShifted[startOfQueue].stateNumber;
}

/** 
 * Returns the current \ref _StatesToBeShifted::gssNode "GSS node" in the shift 
 * queue.
 * 
 * \return the current GSS node in the shift queue.
 */
GSSNode GSS_getShiftQueueGSSNode(void) {
  return statesToBeShifted[startOfQueue].gssNode;
}

/** 
 * Determines if the shift queue is empty.
 * 
 * \return \c true if the shift queu is empty; \c false otherwise.
 */
ATbool GSS_isShiftQueueEmpty(void) {
  return startOfQueue == endOfQueue ? ATtrue : ATfalse;
}
