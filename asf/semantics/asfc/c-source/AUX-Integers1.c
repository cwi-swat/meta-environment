#include "support.h"
static asymbol * lf_AUX_Integers1_1sym;
static aterm * lf_AUX_Integers1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
void register_AUX_Integers1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers1_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-/\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-/\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers1_1 , lf_AUX_Integers1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers1_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[1];
PROF( prof_lf_AUX_Integers1_1);
t_protect( arg0);
t_protect( arg1);
tmp[ 0]= ( * ef2)( arg0 , arg1);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef3)( ))) {
t_unprotect( tmp[ 0]);
return ( * ef1)( arg0 , arg1);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef4)( ( * ef5)( lf2( make_list( make_char( 48)))));
}
t_unprotect( tmp[ 0]);
return make_nf2( lf_AUX_Integers1_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

