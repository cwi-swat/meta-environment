#include "support.h"
static asymbol * lf_AUX_AsFix2C2_1sym;
static aterm * lf_AUX_AsFix2C2_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
void register_AUX_AsFix2C2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2C2_1sym= TmkSymbol( "prod(id(\"AsFix2C\"),w(\"\"),[l(\"asfix2muasf1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2C\"),w(\"\"),[l(\"asfix2muasf1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2C2_1 , lf_AUX_AsFix2C2_1sym);
}
void resolve_AUX_AsFix2C2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"asfix2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"asfix2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-left-linear\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-left-linear\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2C2_1( aterm * arg0) {
{
aterm * tmp[5];
PROF( prof_lf_AUX_AsFix2C2_1);
t_protect( arg0);
tmp[ 0]= ( * ef1)( arg0);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
t_protect( tmp[ 1]);
tmp[ 3]= ( * ef3)( tmp[ 1]);
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef4)( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return tmp[ 4];
}
t_unprotect( tmp[ 0]);
return make_nf1( lf_AUX_AsFix2C2_1sym , arg0);
}
}

