#line 5 "preparation.h.nw"
#ifndef PREPARATION_H
#define PREPARATION_H

#include <aterm.h>

#line 20 "preparation.h.nw"
aterm *RWprepareTerm(arena *ar, aterm *t);
#line 26 "preparation.h.nw"
aterm_list *RWprepareEqs(arena *ar, aterm_list *eqs);
#line 32 "preparation.h.nw"
aterm *RWrestoreTerm(arena *ar, aterm *t);

#line 14 "preparation.h.nw"
#endif
