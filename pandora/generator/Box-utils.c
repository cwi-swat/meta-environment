#include "Box-utils.h"

/*{{{  BOX_Box BOX_makeBoxIEmptyLayout(BOX_Box box) */

BOX_Box BOX_makeBoxIEmptyLayout(BOX_Box box)
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
/*{{{  BOX_Box BOX_makeBoxHEmptyLayout(BOX_BoxList boxList) */

BOX_Box BOX_makeBoxHEmptyLayout(BOX_BoxList boxList)
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
/*{{{  BOX_Box BOX_makeBoxHvEmptyLayout(BOX_BoxList boxList) */

BOX_Box BOX_makeBoxHvEmptyLayout(BOX_BoxList boxList)
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
/*{{{  BOX_Box BOX_makeBoxVEmptyLayout(BOX_BoxList boxList) */

BOX_Box BOX_makeBoxVEmptyLayout(BOX_BoxList boxList)
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
