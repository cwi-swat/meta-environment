/** \file 
 * Initialization of the sdf-metrics package.
 */

#include "sdfMetrics.h"

#ifndef ASF_MAIN
#define ASF_MAIN
#endif
#include "ExtractSDF.c"

/*extern void  register_ExtractSDF();
extern void resolve_ExtractSDF();
*/

void SDF_METRICS_register(void) {
  register_ExtractSDF();
}

void SDF_METRICS_resolve(void) {
  resolve_ExtractSDF();
}

void SDF_METRICS_init(void) {
  init_ExtractSDF();
}
