#include "support.h"
static asymbol * lf_AUX_C_Basics18_1sym;
static aterm * lf_AUX_C_Basics18_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
void register_AUX_C_Basics18( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics18_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-call-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-call-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics18_1 , lf_AUX_C_Basics18_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_C_Basics18( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics18_1( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_C_Basics18_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( m_not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 101))) {
tmp[ 0]= m_list_tail( atmp000);
t_protect( tmp[ 0]);
tmp[ 1]= ( * ef7)( ( * ef1)( lf2( cons( make_list( make_char( 101)) , make_list( tmp[ 0])))));
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef2)( ( * ef3)( ( * ef4)( ) , ( * ef5)( ( * ef6)( tmp[ 1]))));
}
}
}
}
}
}
return ( * ef6)( ( * ef7)( arg0));
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

