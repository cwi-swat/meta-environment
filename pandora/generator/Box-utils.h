#include "Box.h"

BOX_Box BOX_makeIBox(BOX_Box box);
BOX_Box BOX_makeHBox(BOX_BoxList boxList);
BOX_Box BOX_makeHBoxWithHs(BOX_BoxList boxList, const char *hs);
BOX_Box BOX_makeHVBox(BOX_BoxList boxList);
BOX_Box BOX_makeVBox(BOX_BoxList boxList);
