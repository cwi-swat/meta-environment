#include "support.h"
static asymbol * lf_AUX_Check_List_Pats14_2sym;
static aterm * lf_AUX_Check_List_Pats14_2( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Check_List_Pats14_1sym;
static aterm * lf_AUX_Check_List_Pats14_1( aterm * arg1);
void register_AUX_Check_List_Pats14( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Check_List_Pats14_2sym= TmkSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Check_List_Pats14_1sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Check_List_Pats14_1 , lf_AUX_Check_List_Pats14_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats14_2 , lf_AUX_Check_List_Pats14_2sym);
}
void resolve_AUX_Check_List_Pats14( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_Check_List_Pats14_2( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_Check_List_Pats14_2);
if( check_sym( arg0 , lf_AUX_Check_List_Pats14_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_unprotect( arg0);
return ( * ef1)( tmp[ 0]);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_unprotect( arg0);
return ( * ef2)( ( * ef1)( tmp[ 0]) , lf_AUX_Check_List_Pats14_2( lf_AUX_Check_List_Pats14_1( make_list( tmp[ 1]))));
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf1( lf_AUX_Check_List_Pats14_2sym , arg0);
}
}
aterm * lf_AUX_Check_List_Pats14_1( aterm * arg0) {
PROF( prof_lf_AUX_Check_List_Pats14_1);
return make_nf1( lf_AUX_Check_List_Pats14_1sym , arg0);
}

