#include "support.h"
static asymbol * lf_AUX_Trans_Set_Pats5_2sym;
static aterm * lf_AUX_Trans_Set_Pats5_2( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_Trans_Set_Pats5_1sym;
static aterm * lf_AUX_Trans_Set_Pats5_1( aterm * arg1);
void register_AUX_Trans_Set_Pats5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Trans_Set_Pats5_2sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"set-patterns\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SPatType\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Trans_Set_Pats5_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Trans_Set_Pats5_1 , lf_AUX_Trans_Set_Pats5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"set-patterns\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SPatType\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats5_2 , lf_AUX_Trans_Set_Pats5_2sym);
}
void resolve_AUX_Trans_Set_Pats5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"set-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SPatType\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"set-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SPatType\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Trans_Set_Pats5_2( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[8];
PROF( prof_lf_AUX_Trans_Set_Pats5_2);
if( check_sym( arg1 , lf_AUX_Trans_Set_Pats5_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
if( is_single_element( atmp10)) {
t_protect( atmp10);
tmp[ 0]= list_head( atmp10);
t_unprotect( arg1);
return ( * ef1)( arg0 , ( * ef2)( lf_AUX_Trans_Set_Pats5_1( make_list( tmp[ 0]))) , arg2);
}
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
tmp[ 0]= list_head( atmp10);
t_protect( atmp10);
tmp[ 1]= list_tail( atmp10);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( arg0);
t_protect( tmp[ 0]);
t_protect( arg2);
tmp[ 2]= ( * ef1)( arg0 , ( * ef2)( lf_AUX_Trans_Set_Pats5_1( make_list( tmp[ 0]))) , arg2);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Trans_Set_Pats5_1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( arg0);
t_protect( tmp[ 1]);
t_protect( arg2);
tmp[ 5]= lf_AUX_Trans_Set_Pats5_2( arg0 , lf_AUX_Trans_Set_Pats5_1( make_list( tmp[ 1])) , arg2);
if( check_sym( tmp[ 5] , ef2sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_Trans_Set_Pats5_1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 4]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 5]);
return ( * ef2)( lf_AUX_Trans_Set_Pats5_1( cons( make_list( tmp[ 4]) , make_list( tmp[ 7]))));
}
}
}
t_unprotect( tmp[ 5]);
}
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf3( lf_AUX_Trans_Set_Pats5_2sym , arg0 , arg1 , arg2);
}
}
aterm * lf_AUX_Trans_Set_Pats5_1( aterm * arg0) {
PROF( prof_lf_AUX_Trans_Set_Pats5_1);
return make_nf1( lf_AUX_Trans_Set_Pats5_1sym , arg0);
}

