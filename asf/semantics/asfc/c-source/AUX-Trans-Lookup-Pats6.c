#include "support.h"
static asymbol * lf_AUX_Trans_Lookup_Pats6_1sym;
static aterm * lf_AUX_Trans_Lookup_Pats6_1( );
static asymbol * lf_AUX_Trans_Lookup_Pats6_2sym;
static aterm * lf_AUX_Trans_Lookup_Pats6_2( );
static asymbol * lf_AUX_Trans_Lookup_Pats6_3sym;
static aterm * lf_AUX_Trans_Lookup_Pats6_3( );
static asymbol * lf_AUX_Trans_Lookup_Pats6_4sym;
static aterm * lf_AUX_Trans_Lookup_Pats6_4( );
static asymbol * lf_AUX_Trans_Lookup_Pats6_5sym;
static aterm * lf_AUX_Trans_Lookup_Pats6_5( );
void register_AUX_Trans_Lookup_Pats6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Trans_Lookup_Pats6_1sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Trans_Lookup_Pats6_2sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Lookup_Pats6_3sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Lookup_Pats6_4sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Lookup_Pats6_5sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats6_1 , lf_AUX_Trans_Lookup_Pats6_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats6_2 , lf_AUX_Trans_Lookup_Pats6_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats6_3 , lf_AUX_Trans_Lookup_Pats6_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats6_4 , lf_AUX_Trans_Lookup_Pats6_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats6_5 , lf_AUX_Trans_Lookup_Pats6_5sym);
}
void resolve_AUX_Trans_Lookup_Pats6( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Trans_Lookup_Pats6_5( ) {
PROF( prof_lf_AUX_Trans_Lookup_Pats6_5);
return make_nf0( lf_AUX_Trans_Lookup_Pats6_5sym);
}
aterm * lf_AUX_Trans_Lookup_Pats6_4( ) {
PROF( prof_lf_AUX_Trans_Lookup_Pats6_4);
return make_nf0( lf_AUX_Trans_Lookup_Pats6_4sym);
}
aterm * lf_AUX_Trans_Lookup_Pats6_3( ) {
PROF( prof_lf_AUX_Trans_Lookup_Pats6_3);
return make_nf0( lf_AUX_Trans_Lookup_Pats6_3sym);
}
aterm * lf_AUX_Trans_Lookup_Pats6_2( ) {
PROF( prof_lf_AUX_Trans_Lookup_Pats6_2);
return make_nf0( lf_AUX_Trans_Lookup_Pats6_2sym);
}
aterm * lf_AUX_Trans_Lookup_Pats6_1( ) {
PROF( prof_lf_AUX_Trans_Lookup_Pats6_1);
return make_nf0( lf_AUX_Trans_Lookup_Pats6_1sym);
}

