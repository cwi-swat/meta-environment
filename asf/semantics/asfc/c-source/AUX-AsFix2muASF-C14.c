#include "support.h"
static asymbol * lf_AUX_AsFix2muASF_C14_1sym;
static aterm * lf_AUX_AsFix2muASF_C14_1( aterm * arg1 , aterm * arg2);
void register_AUX_AsFix2muASF_C14( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASF_C14_1sym= TmkSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C14_1 , lf_AUX_AsFix2muASF_C14_1sym);
}
void resolve_AUX_AsFix2muASF_C14( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_AsFix2muASF_C14_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_AsFix2muASF_C14_1);
return make_nf2( lf_AUX_AsFix2muASF_C14_1sym , arg0 , arg1);
}

