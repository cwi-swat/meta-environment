#include "support.h"
static Symbol lf_AUX_AsFix2muASF_C12_2sym;
static ATerm lf_AUX_AsFix2muASF_C12_2( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf_AUX_AsFix2muASF_C12_1sym;
static ATerm lf_AUX_AsFix2muASF_C12_1( ATerm arg1);
void register_AUX_AsFix2muASF_C12( ) {
lf_AUX_AsFix2muASF_C12_2sym= ATmakeSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , 4 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix2muASF_C12_2sym);
lf_AUX_AsFix2muASF_C12_1sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix2muASF_C12_1sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_AsFix2muASF_C12_1 , lf_AUX_AsFix2muASF_C12_1sym);
register_prod( ATparse( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C12_2 , lf_AUX_AsFix2muASF_C12_2sym);
}
void resolve_AUX_AsFix2muASF_C12( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
void init_AUX_AsFix2muASF_C12( ) {
}
ATerm lf_AUX_AsFix2muASF_C12_2( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3) {
PROF( prof_lf_AUX_AsFix2muASF_C12_2);
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg1 , lf_AUX_AsFix2muASF_C12_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
return ( * ef2)( ( * ef3)( lf_AUX_AsFix2muASF_C12_1( make_list( atmp10))) , arg2 , arg3);
}
}
}
}
if( check_sym( arg0 , ef4sym)) {
if( check_sym( arg1 , lf_AUX_AsFix2muASF_C12_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
return ( * ef5)( ( * ef3)( lf_AUX_AsFix2muASF_C12_1( make_list( atmp10))) , arg2 , arg3);
}
}
}
}
return make_nf4( lf_AUX_AsFix2muASF_C12_2sym , arg0 , arg1 , arg2 , arg3);
}
ATerm lf_AUX_AsFix2muASF_C12_1( ATerm arg0) {
PROF( prof_lf_AUX_AsFix2muASF_C12_1);
return make_nf1( lf_AUX_AsFix2muASF_C12_1sym , arg0);
}

