#ifndef __LONGESTMATCH
#define __LONGESTMATCH

#include <TB.h>
#include "bool.h"

int tree_width(term *);
void print_tree_yield(FILE *, term *);

/*
  Tokenstreams
*/

typedef term token;
typedef term token_stream;

token_stream *get_tokens(term *);

token_stream *init_token_stream(term *);
void          reset_token_stream(token_stream *);
token        *token_stream_next(token_stream *);

#define FIRST(ts)   elm1(fun_args(ts))
#define CUR(ts)     elm2(fun_args(ts))
#define STACK(ts)   elm3(fun_args(ts))

/* 
   Longest match
*/

int lm_comp(token_stream *, token_stream *);
term_list *longest_match(term_list *);

#endif

