/*{{{  includes */

#include <stdio.h>
#include <atb-tool.h>

#include "tifs.h"

/*}}}  */

/*{{{  static ATermList replaceToolName(ATermList tifs, char *tool) */

static ATermList replaceToolName(ATermList tifs, char *tool)
{
  ATermList result = ATempty;
  ATermPlaceholder ph = ATmakePlaceholder(ATparse(tool));

  while (!ATisEmpty(tifs)) {
    ATerm tif = ATgetFirst(tifs);
    ATermAppl appl = (ATermAppl) tif;
    appl = ATsetArgument(appl, (ATerm)ph, 0);
    result = ATinsert(result, (ATerm)appl);
    tifs = ATgetNext(tifs);
  }

  return result;
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  ATermList tifs1;
  ATermList tifs2;
  ATermList mergedTifs;

  ATBinit(argc, argv, &bottomOfStack);

  tifs1 = read_tifs_from_named_file(argv[1]);
  tifs1 = extract_tool_from_tifs(tifs1, argv[2]);
  tifs1 = replaceToolName(tifs1, argv[5]);

  tifs2 = read_tifs_from_named_file(argv[3]);
  tifs2 = extract_tool_from_tifs(tifs2, argv[4]);
  tifs2 = replaceToolName(tifs2, argv[5]);

  mergedTifs = ATconcat(tifs1, tifs2);
  mergedTifs = generalize_tifs(mergedTifs);
  mergedTifs = unify_tifs(mergedTifs);

  write_tifs_to_named_file(mergedTifs, argv[6]);

  return 0;
}

/*}}}  */
