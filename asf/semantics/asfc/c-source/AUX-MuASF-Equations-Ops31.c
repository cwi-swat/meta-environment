#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Equations_Ops31_2sym ;
static ATerm lf_AUX_MuASF_Equations_Ops31_2 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf_AUX_MuASF_Equations_Ops31_1sym ;
static ATerm lf_AUX_MuASF_Equations_Ops31_1 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
void register_AUX_MuASF_Equations_Ops31 ( ) {
lf_AUX_MuASF_Equations_Ops31_2sym = ATmakeSymbol ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops31_2sym ) ;
lf_AUX_MuASF_Equations_Ops31_1sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops31_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_MuASF_Equations_Ops31_1 , lf_AUX_MuASF_Equations_Ops31_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Equations_Ops31_2 , lf_AUX_MuASF_Equations_Ops31_2sym ) ;
}
void resolve_AUX_MuASF_Equations_Ops31 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_MuASF_Equations_Ops31 ( ) {
}
ATerm lf_AUX_MuASF_Equations_Ops31_2 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
FUNC_ENTRY ( lf_AUX_MuASF_Equations_Ops31_2sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops31_2sym , arg0 , arg1 , arg2 , arg3 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
if ( check_sym ( arg1 , lf_AUX_MuASF_Equations_Ops31_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( ! not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef6 ) ( arg2 , arg3 ) ) ;
}
else {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf_AUX_MuASF_Equations_Ops31_1 ( make_list ( atmp10 ) ) ) , arg2 , arg3 ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef4sym ) ) {
if ( check_sym ( arg1 , lf_AUX_MuASF_Equations_Ops31_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( ! not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef7 ) ( arg2 , arg3 ) ) ;
}
else {
FUNC_EXIT ( ( * ef5 ) ( ( * ef3 ) ( lf_AUX_MuASF_Equations_Ops31_1 ( make_list ( atmp10 ) ) ) , arg2 , arg3 ) ) ;
}
}
}
}
FUNC_EXIT ( make_nf4 ( lf_AUX_MuASF_Equations_Ops31_2sym , arg0 , arg1 , arg2 , arg3 ) ) ;
}
ATerm lf_AUX_MuASF_Equations_Ops31_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Equations_Ops31_1sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops31_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Equations_Ops31_1sym , arg0 ) ) ;
}

