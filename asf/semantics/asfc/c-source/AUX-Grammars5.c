#include "support.h"
static asymbol * lf_AUX_Grammars5_1sym;
static aterm * lf_AUX_Grammars5_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Grammars5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Grammars5_1sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Symbol\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)") , lf_AUX_Grammars5_1 , lf_AUX_Grammars5_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Symbol\"))") , lf2 , lf2sym);
}
void resolve_AUX_Grammars5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Grammars5_1( aterm * arg0) {
{
aterm * tmp[1];
PROF( prof_lf_AUX_Grammars5_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
tmp[ 0]= arg_0( atmp00);
{
aterm * atmp0000[2];
atmp0000[ 0]= tmp[ 0];
t_protect( atmp0000[ 0]);
if( m_not_empty_list( tmp[ 0])) {
tmp[ 0]= m_list_tail( tmp[ 0]);
atmp0000[ 1]= tmp[ 0];
t_protect( atmp0000[ 1]);
while( m_not_empty_list( tmp[ 0])) {
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
t_unprotect( arg0);
return ( * ef2)( lf_AUX_Grammars5_1( ( * ef1)( lf2( slice( atmp0000[ 0] , atmp0000[ 1])))) , ( * ef2)( ( * ef1)( lf2( make_list( ( * ef3)( ( * ef4)( ))))) , lf_AUX_Grammars5_1( ( * ef1)( lf2( tmp[ 0])))));
}
atmp0000[ 1]= list_tail( atmp0000[ 1]);
tmp[ 0]= atmp0000[ 1];
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( atmp000);
if( ! not_empty_list( atmp000)) {
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( null( ))));
}
if( m_is_single_element( atmp000)) {
tmp[ 0]= m_list_head( atmp000);
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( tmp[ 0])));
}
}
}
}
}
return make_nf1( lf_AUX_Grammars5_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

