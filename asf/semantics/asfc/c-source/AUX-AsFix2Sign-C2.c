#include  "support.h"
static Symbol lf_AUX_AsFix2Sign_C2_1sym ;
static ATerm lf_AUX_AsFix2Sign_C2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
void register_AUX_AsFix2Sign_C2 ( ) {
lf_AUX_AsFix2Sign_C2_1sym = ATmakeSymbol ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"asfix2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2Sign_C2_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"AFun\"),ql(\".\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"asfix2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2Sign_C2_1 , lf_AUX_AsFix2Sign_C2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"AFun\"),ql(\".\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_AsFix2Sign_C2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"syntax2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[l(\"syntax2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"module-name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"module-name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"get-org-modname\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"get-org-modname\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sections\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sections\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_AsFix2Sign_C2 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_AsFix2Sign_C2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2Sign_C2_1sym , ATmakeAppl ( lf_AUX_AsFix2Sign_C2_1sym , arg0 , arg1 ) ) ;
tmp [ 0 ] = ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = lf2 ( make_list ( ( * ef3 ) ( ) ) ) ) ) ) ;
tmp [ 1 ] = ( * ef4 ) ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef2 ) ( arg0 , ( constant1 ? constant1 : ( constant1 = lf2 ( make_list ( ( * ef5 ) ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( tmp [ 1 ] , tmp [ 3 ] , arg1 ) ) ;
}
FUNC_EXIT ( make_nf2 ( lf_AUX_AsFix2Sign_C2_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

