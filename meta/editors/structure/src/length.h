#ifndef POSINFO_H
#define POSINFO_H

#include <PT.h>

#include "Editor.h"

PT_ParseTree updateParseTreeLengthInfo(PT_ParseTree parse_tree, SE_Path path,
				       int delta_length);

#endif /* POSINFO_H */
