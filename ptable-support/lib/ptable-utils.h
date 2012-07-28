/* $Id$ */

#include <ptable.h>

/* Note that a PTBL_Production is a PT_Production from the pt-support
 * package. You may always cast these types. Future versions of 
 * ApiGen might solve this by introducing modulariy of adt files.
 */
PTBL_Production PTBL_LookUpProduction(PTBL_ParseTable pt, int label);
