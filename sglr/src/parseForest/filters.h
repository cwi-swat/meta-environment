/* $Id$ */

/** \file
 * \ingroup parseForest
 * 
 *  The parser maintains a compact representation of a set of parse trees
 * in the form of a parse forest. We use the generic terms to represent
 * these.
 *
 * Parse forests are constructed using the functions SG_createTreeNode(), and
 * |SG_Amb|. The function |SG_Amb| actually constructs forests, by
 * maintaining a lookup structure that maps terms onto sets of terms: an
 * ambiguity cluster.
 */

#ifndef _FILTERS_H_
#define _FILTERS_H_

#include "parseTable.h"
#include "inputString-data.h"
#include <MEPT.h>

PT_ParseTree FLT_filter(ParseTable *pt, PT_Tree t, InputString input);

#endif  /* _FILTERS_H_ */
