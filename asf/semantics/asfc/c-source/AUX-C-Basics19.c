#include "support.h"
static Symbol lf_AUX_C_Basics19_1sym;
static ATerm lf_AUX_C_Basics19_1( );
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_C_Basics19( ) {
lf_AUX_C_Basics19_1sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics19_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics19_1 , lf_AUX_C_Basics19_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_C_Basics19( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_C_Basics19( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_C_Basics19_1( ) {
PROF( prof_lf_AUX_C_Basics19_1);
return ( constant0? constant0: ( constant0= ( * ef1)( lf2( (ATerm) ATmakeList( 3 , char_table[ 34] , char_table[ 32] , char_table[ 34])))));
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

