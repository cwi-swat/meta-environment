#ifndef PATH_H
#define PATH_H

#include <MEPT.h>

#include "EditorData.h"

SE_Steps stepUp(SE_Steps steps);
SE_Path pathUp(SE_Path path);
SE_Path pathDown(SE_Path path);
SE_Path pathLeft(SE_Path path);
SE_Path pathRight(SE_Path path);

SE_Path getPathInParseTree(PT_ParseTree parse_tree, int location, int length);
SE_Path getPathInParseTreeAtPosInfo(PT_ParseTree parse_tree, ATerm posInfo);
ATbool isChildPath(SE_Path child, SE_Path parent);

#endif
