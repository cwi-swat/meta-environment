#ifndef __MATCH_H__
#define __MATCH_H__


extern env *Bindings1, *Bindings2;

term     *substitute(term *, env *);
term     *substitute_list(term *, env *);
TBbool    match(term *, term *, env *, env *);
TBbool    match1(term *, term *);
TBbool    match_list(term *, term *);

TBbool    cmatchp(term *, term *);

void     init_match(void);

#endif /* __MATCH_H__ */



