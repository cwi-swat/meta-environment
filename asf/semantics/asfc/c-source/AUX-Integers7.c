#include "support.h"
static asymbol * lf_AUX_Integers7_1sym;
static aterm * lf_AUX_Integers7_1( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef1sym;
static funcptr ef1;
void register_AUX_Integers7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers7_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\">\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\">\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Integers7_1 , lf_AUX_Integers7_1sym);
}
void resolve_AUX_Integers7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers7_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[1];
PROF( prof_lf_AUX_Integers7_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp00);
t_protect( atmp10);
tmp[ 0]= ( * ef3)( atmp00 , atmp10);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef2)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( );
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef4)( );
}
t_unprotect( tmp[ 0]);
}
}
if( check_sym( arg1 , ef5sym)) {
{
aterm * atmp10= arg_0( arg1);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( );
}
}
}
}
if( check_sym( arg0 , ef5sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef4)( );
}
}
if( check_sym( arg1 , ef5sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
t_protect( atmp00);
t_unprotect( arg0);
t_unprotect( arg1);
return lf_AUX_Integers7_1( ( * ef1)( atmp10) , ( * ef1)( atmp00));
}
}
}
}
return make_nf2( lf_AUX_Integers7_1sym , arg0 , arg1);
}
}

