#ifndef PATH_H
#define PATH_H

#include <PT.h>

#include "Editor.h"

SE_Steps stepUp(SE_Steps steps);
SE_Path pathUp(SE_Path path);
SE_Path pathDown(SE_Path path);
SE_Path pathLeft(SE_Path path);
SE_Path pathRight(SE_Path path);

SE_Path getPathInParseTree(PT_ParseTree parse_tree, int location, int length);
ATbool isChildPath(SE_Path child, SE_Path parent);

#endif
