#ifndef EVAL_TIDE_H
#define EVAL_TIDE_H

#ifdef USE_TIDE
#define TIDE_STEP(tree, env, depth) Tide_step(PT_getTreeAnnotation((PT_Tree) tree, ATmake("posinfo")), env, depth)
void Tide_connect();
void Tide_disconnect();
void Tide_step(ATerm position, ATerm env, int stack_level);

#else

#define TIDE_STEP(posinfo, env, depth)

#endif

#endif
