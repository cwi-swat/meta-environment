#include "support.h"
static asymbol * lf_AUX_Check_List_Pats5_2sym;
static aterm * lf_AUX_Check_List_Pats5_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_Check_List_Pats5_1sym;
static aterm * lf_AUX_Check_List_Pats5_1( aterm * arg1);
void register_AUX_Check_List_Pats5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Check_List_Pats5_2sym= TmkSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"terms-contains-list-vars\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Check_List_Pats5_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Check_List_Pats5_1 , lf_AUX_Check_List_Pats5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"terms-contains-list-vars\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats5_2 , lf_AUX_Check_List_Pats5_2sym);
}
void resolve_AUX_Check_List_Pats5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"term-contains-list-vars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"term-contains-list-vars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Check_List_Pats5_2( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_Check_List_Pats5_2);
if( check_sym( arg0 , lf_AUX_Check_List_Pats5_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_unprotect( arg0);
return ( * ef2)( ( * ef3)( tmp[ 0]) , lf_AUX_Check_List_Pats5_2( lf_AUX_Check_List_Pats5_1( make_list( tmp[ 1]))));
}
else {
t_unprotect( arg0);
return ( * ef1)( );
}
}
}
return make_nf1( lf_AUX_Check_List_Pats5_2sym , arg0);
}
}
aterm * lf_AUX_Check_List_Pats5_1( aterm * arg0) {
PROF( prof_lf_AUX_Check_List_Pats5_1);
return make_nf1( lf_AUX_Check_List_Pats5_1sym , arg0);
}

