#include "support.h"
static asymbol * lf_AUX_Normalize_Conds15_2sym;
static aterm * lf_AUX_Normalize_Conds15_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf_AUX_Normalize_Conds15_1sym;
static aterm * lf_AUX_Normalize_Conds15_1( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
void register_AUX_Normalize_Conds15( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Normalize_Conds15_2sym= TmkSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Normalize_Conds15_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Normalize_Conds15_1 , lf_AUX_Normalize_Conds15_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds15_2 , lf_AUX_Normalize_Conds15_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
}
void resolve_AUX_Normalize_Conds15( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-arg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-arg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Normalize_Conds15_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[26];
PROF( prof_lf_AUX_Normalize_Conds15_2);
if( check_sym( arg0 , lf_AUX_Normalize_Conds15_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 2] , lf_AUX_Normalize_Conds15_1sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 99))) {
t_protect( tmp[ 4]);
tmp[ 6]= list_tail( tmp[ 4]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 111))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 110))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 115))) {
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
tmp[ 9]= list_head( tmp[ 5]);
t_protect( tmp[ 5]);
tmp[ 10]= list_tail( tmp[ 5]);
t_protect( tmp[ 10]);
if( is_single_element( tmp[ 10])) {
t_protect( tmp[ 10]);
tmp[ 11]= list_head( tmp[ 10]);
t_protect( tmp[ 9]);
t_protect( arg1);
tmp[ 12]= ( * ef4)( tmp[ 9] , arg1);
if( check_sym( tmp[ 12] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= arg_1( tmp[ 12]);
tmp[ 15]= arg_2( tmp[ 12]);
if( check_sym( tmp[ 13] , lf_AUX_Normalize_Conds15_1sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , lf4sym)) {
tmp[ 17]= arg_0( tmp[ 14]);
t_protect( tmp[ 16]);
if( is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
tmp[ 18]= list_head( tmp[ 16]);
t_protect( tmp[ 11]);
t_protect( tmp[ 15]);
tmp[ 19]= lf_AUX_Normalize_Conds15_2( lf_AUX_Normalize_Conds15_1( make_list( tmp[ 11])) , tmp[ 15]);
if( check_sym( tmp[ 19] , ef3sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
tmp[ 21]= arg_1( tmp[ 19]);
tmp[ 22]= arg_2( tmp[ 19]);
if( check_sym( tmp[ 20] , lf_AUX_Normalize_Conds15_1sym)) {
tmp[ 23]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 21] , lf4sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
t_protect( tmp[ 23]);
if( is_single_element( tmp[ 23])) {
t_protect( tmp[ 23]);
tmp[ 25]= list_head( tmp[ 23]);
t_protect( tmp[ 17]);
t_protect( tmp[ 24]);
t_protect( tmp[ 22]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 19]);
return ( * ef3)( lf_AUX_Normalize_Conds15_1( make_list( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf_AUX_Normalize_Conds15_1( cons( make_list( tmp[ 18]) , make_list( tmp[ 25])))))) , lf4( cons( make_list( tmp[ 17]) , make_list( tmp[ 24]))) , tmp[ 22]);
}
}
}
}
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 18]);
}
}
}
}
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , lf_AUX_Normalize_Conds15_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_unprotect( arg0);
return ( * ef4)( tmp[ 0] , arg1);
}
}
}
return make_nf2( lf_AUX_Normalize_Conds15_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Normalize_Conds15_1( aterm * arg0) {
PROF( prof_lf_AUX_Normalize_Conds15_1);
return make_nf1( lf_AUX_Normalize_Conds15_1sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

