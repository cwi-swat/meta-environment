#ifndef AREA_H
#define AREA_H

#include <MEPT.h>

#include "EditorData.h"

SE_Area createArea(PT_ParseTree parse_tree, SE_Path path);
ATbool inArea(SE_Area area, int loc);
ATbool afterArea(SE_Area area, int loc);
ATbool beforeArea(SE_Area area, int loc);

#endif /* AREA_H */
