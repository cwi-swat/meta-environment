
#ifndef PREDICTED_H
#define PREDICTED_H

#include <aterm2.h>
#include "characters.h"
#include "itemset.h"

void outgoing(ItemSet itemset, ATermList *prods, CC_Set *chars);
void closure(ATermList items, ItemSet itemset);

#endif
