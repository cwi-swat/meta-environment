#ifndef EVAL_TIDE_H
#define EVAL_TIDE_H

#ifdef USE_TIDE

void Tide_connect();
void Tide_disconnect();
void Tide_step(ATerm position, ATerm env, int stack_level);

#endif

#endif
