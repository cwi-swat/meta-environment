#include "support.h"
static asymbol * lf_AUX_AsFix2Sign_C13_1sym;
static aterm * lf_AUX_AsFix2Sign_C13_1( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_AsFix2Sign_C13_2sym;
static aterm * lf_AUX_AsFix2Sign_C13_2( aterm * arg1 , aterm * arg2 , aterm * arg3);
void register_AUX_AsFix2Sign_C13( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2Sign_C13_1sym= TmkSymbol( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_AsFix2Sign_C13_2sym= TmkSymbol( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2Sign_C13_1 , lf_AUX_AsFix2Sign_C13_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2Sign_C13_2 , lf_AUX_AsFix2Sign_C13_2sym);
}
void resolve_AUX_AsFix2Sign_C13( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_AsFix2Sign_C13_2( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_AsFix2Sign_C13_2);
return make_nf3( lf_AUX_AsFix2Sign_C13_2sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_AsFix2Sign_C13_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_AsFix2Sign_C13_1);
return make_nf2( lf_AUX_AsFix2Sign_C13_1sym , arg0 , arg1);
}

