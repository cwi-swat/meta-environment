#include "support.h"
static Symbol lf_AUX_WfAsFix3_1sym;
static ATerm lf_AUX_WfAsFix3_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
void register_AUX_WfAsFix3( ) {
lf_AUX_WfAsFix3_1sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix3_1sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix3_1 , lf_AUX_WfAsFix3_1sym);
}
void resolve_AUX_WfAsFix3( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"abbrevs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"abbrevs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"pairs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"pairs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_WfAsFix3( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_WfAsFix3_1( ATerm arg0) {
PROF( prof_lf_AUX_WfAsFix3_1);
return ( * ef1)( arg0 , ( * ef2)( ( * ef2)( arg0 , ( constant0? constant0: ( constant0= ( * ef3)( )))) , ( constant1? constant1: ( constant1= ( * ef4)( )))));
}

