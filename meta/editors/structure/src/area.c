#include <stdlib.h>
#include <assert.h>

#include <MEPT.h>
#include <MEPT-utils.h>

#include "area.h"
#include "path.h"
#include "tree.h"
#include "length.h"

/*{{{  SE_Area createArea(PT_ParseTree parse_tree, SE_Path path) */

SE_Area createArea(PT_ParseTree parse_tree, SE_Path path)
{
  int start, length;

  start = calcParseTreeStart(parse_tree, path);

  if (SE_isPathRoot(path)) {
    length = PT_getParseTreeLengthAnno(parse_tree);
  } else {
    SE_Steps steps = SE_getPathSteps(path);
    PT_Tree tree = getTreeAt(PT_getParseTreeTree(parse_tree), steps);
    length = PT_getTreeLengthAnno(tree);
  }

  return SE_makeAreaDefault(start, length);
}

/*}}}  */
/*{{{  ATbool inArea(SE_Area area, int loc) */

ATbool inArea(SE_Area area, int loc)
{
  int start = SE_getAreaStart(area);
  int length = SE_getAreaLength(area);

  return ((start <= loc) && (loc <= (start + length)));
}

/*}}}  */
/*{{{  ATbool afterArea(SE_Area area, int loc) */

ATbool afterArea(SE_Area area, int loc)
{
  int start = SE_getAreaStart(area);
  int length = SE_getAreaLength(area);

  return (start + length < loc);
}

/*}}}  */
/*{{{  ATbool beforeArea(SE_Area area, int loc) */

ATbool beforeArea(SE_Area area, int loc)
{
  int start = SE_getAreaStart(area);

  return (loc < start);
}

/*}}}  */
