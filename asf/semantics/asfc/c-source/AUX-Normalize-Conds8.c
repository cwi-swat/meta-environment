#include "support.h"
static asymbol * lf_AUX_Normalize_Conds8_2sym;
static aterm * lf_AUX_Normalize_Conds8_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * lf_AUX_Normalize_Conds8_1sym;
static aterm * lf_AUX_Normalize_Conds8_1( aterm * arg1);
void register_AUX_Normalize_Conds8( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Normalize_Conds8_2sym= TmkSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Normalize_Conds8_1sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Normalize_Conds8_1 , lf_AUX_Normalize_Conds8_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds8_2 , lf_AUX_Normalize_Conds8_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_Normalize_Conds8( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Normalize_Conds8_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[14];
PROF( prof_lf_AUX_Normalize_Conds8_2);
if( check_sym( arg0 , lf_AUX_Normalize_Conds8_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_unprotect( arg0);
return ( * ef1)( tmp[ 0] , arg1);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef1)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Normalize_Conds8_1sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
t_protect( tmp[ 6]);
if( ! not_empty_list( tmp[ 6])) {
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 1]);
t_protect( tmp[ 5]);
tmp[ 8]= lf_AUX_Normalize_Conds8_2( lf_AUX_Normalize_Conds8_1( make_list( tmp[ 1])) , tmp[ 5]);
if( check_sym( tmp[ 8] , ef2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
tmp[ 11]= arg_2( tmp[ 8]);
if( check_sym( tmp[ 9] , lf3sym)) {
tmp[ 12]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_Normalize_Conds8_1sym)) {
tmp[ 13]= arg_0( tmp[ 10]);
t_protect( tmp[ 12]);
if( ! not_empty_list( tmp[ 12])) {
t_protect( tmp[ 13]);
if( not_empty_list( tmp[ 13])) {
t_protect( tmp[ 7]);
t_protect( tmp[ 13]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 8]);
return ( * ef2)( lf3( make_list( null( ))) , lf_AUX_Normalize_Conds8_1( cons( make_list( tmp[ 7]) , make_list( tmp[ 13]))) , tmp[ 11]);
}
}
}
}
}
t_unprotect( tmp[ 8]);
}
}
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
return make_nf2( lf_AUX_Normalize_Conds8_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Normalize_Conds8_1( aterm * arg0) {
PROF( prof_lf_AUX_Normalize_Conds8_1);
return make_nf1( lf_AUX_Normalize_Conds8_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

