/* 
  %% $Id$
*/

#ifndef _PARSER
#define _PARSER

#include <TB.h>
#include "parse-table.h"

term *parse(parse_table *lr, int(*getchar)(void));

typedef int label;

#endif
