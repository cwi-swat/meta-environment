#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux25_2sym;
static aterm * lf_AUX_Rules2C_Aux25_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Rules2C_Aux25_1sym;
static aterm * lf_AUX_Rules2C_Aux25_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_Rules2C_Aux25( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux25_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux25_1sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf_AUX_Rules2C_Aux25_1 , lf_AUX_Rules2C_Aux25_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux25_2 , lf_AUX_Rules2C_Aux25_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_Rules2C_Aux25( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux25_2( aterm * arg0) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Rules2C_Aux25_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux25_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef2)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , make_list( tmp[ 2])))))));
}
}
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_prefix( atmp00);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( atmp00);
tmp[ 1]= list_last( atmp00);
if( check_sym( tmp[ 1] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 0]);
tmp[ 4]= lf_AUX_Rules2C_Aux25_2( lf_AUX_Rules2C_Aux25_1( make_list( tmp[ 0])));
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 4]);
return ( * ef2)( lf3( cons( make_list( tmp[ 6]) , make_list( tmp[ 3]))));
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf1( lf_AUX_Rules2C_Aux25_2sym , arg0);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux25_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux25_1);
return make_nf1( lf_AUX_Rules2C_Aux25_1sym , arg0);
}

