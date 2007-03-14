/* $Id$ */

#ifndef EVAL_TIDE_H
#define EVAL_TIDE_H

#define TIDE_STEP(tree, env, depth) Tide_step(PT_getTreeAnnotation((PT_Tree) tree, pos_info), env, depth)
void Tide_connect(int port);
void Tide_disconnect();
void Tide_step(ATerm position, ATerm env, int stack_level);

extern ATerm pos_info;

#endif
