#ifndef PRIORITIES_H
#define PRIORITIES_H

#include "aterm1.h"
#include "item.h"

ATerm getPrioRight(ATerm prioentry);
ATerm setPrioRight(ATerm prioentry, ATerm prodNr);
ATerm getPrioLeft(ATerm prioentry);
ATerm setPrioLeft(ATerm prioentry, ATerm prodNr);
ATbool isPrioArgument(ATerm prioentry);
ATbool conflicts(Item item, ATerm label);

#endif
