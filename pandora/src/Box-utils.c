#include "Box-utils.h"

/*{{{  BOX_Box BOX_makeIBox(BOX_Box box) */

BOX_Box BOX_makeIBox(BOX_Box box)
{
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions spaceOptions = BOX_makeSpaceOptionOptionsEmpty(); 
  
  return BOX_makeBoxI(optLayout,
		      spaceOptions,
		      optLayout,
		      optLayout,
		      box,
		      optLayout);
}

/*}}}  */
/*{{{  BOX_Box BOX_makeHBox(BOX_BoxList boxList) */

BOX_Box BOX_makeHBox(BOX_BoxList boxList)
{
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions spaceOptions = BOX_makeSpaceOptionOptionsEmpty(); 

  return BOX_makeBoxH(optLayout,
		      spaceOptions,
		      optLayout,
		      optLayout,
		      boxList,
		      optLayout);
}

/*}}}  */
/*{{{  BOX_Box BOX_makeHBoxWithHs(BOX_BoxList boxList, const char* hs) */

BOX_Box BOX_makeHBoxWithHs(BOX_BoxList boxList, const char* hs)
{
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions spaceOptions = BOX_makeSpaceOptionOptionsSingle(BOX_makeSpaceOptionDefault(BOX_makeSpaceSymbolHorizontal(),optLayout, optLayout, BOX_makeNatConLexToCf(BOX_makeLexNatConDigits(hs)))); 

  return BOX_makeBoxH(optLayout,
		      spaceOptions,
		      optLayout,
		      optLayout,
		      boxList,
		      optLayout);
}

/*}}}  */
/*{{{  BOX_Box BOX_makeHVBox(BOX_BoxList boxList) */

BOX_Box BOX_makeHVBox(BOX_BoxList boxList)
{
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions spaceOptions = BOX_makeSpaceOptionOptionsEmpty(); 
  
  return BOX_makeBoxHv(optLayout,
		       spaceOptions,
		       optLayout,
		       optLayout,
		       boxList,
		       optLayout);
}

/*}}}  */
/*{{{  BOX_Box BOX_makeVBox(BOX_BoxList boxList) */

BOX_Box BOX_makeVBox(BOX_BoxList boxList)
{
  BOX_OptLayout optLayout = BOX_makeOptLayoutAbsent();
  BOX_SpaceOptionOptions spaceOptions = BOX_makeSpaceOptionOptionsEmpty(); 
  
  return BOX_makeBoxV(optLayout,
		      spaceOptions,
		      optLayout,
		      optLayout,
		      boxList,
		      optLayout);
}

/*}}}  */
