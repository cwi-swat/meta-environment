#include "support.h"
static asymbol * lf_AUX_Trans_Set_Pats6_1sym;
static aterm * lf_AUX_Trans_Set_Pats6_1( );
static asymbol * lf_AUX_Trans_Set_Pats6_2sym;
static aterm * lf_AUX_Trans_Set_Pats6_2( );
static asymbol * lf_AUX_Trans_Set_Pats6_3sym;
static aterm * lf_AUX_Trans_Set_Pats6_3( );
static asymbol * lf_AUX_Trans_Set_Pats6_4sym;
static aterm * lf_AUX_Trans_Set_Pats6_4( );
static asymbol * lf_AUX_Trans_Set_Pats6_5sym;
static aterm * lf_AUX_Trans_Set_Pats6_5( );
static asymbol * lf_AUX_Trans_Set_Pats6_6sym;
static aterm * lf_AUX_Trans_Set_Pats6_6( );
static asymbol * lf_AUX_Trans_Set_Pats6_7sym;
static aterm * lf_AUX_Trans_Set_Pats6_7( );
static asymbol * lf_AUX_Trans_Set_Pats6_8sym;
static aterm * lf_AUX_Trans_Set_Pats6_8( );
static asymbol * lf_AUX_Trans_Set_Pats6_9sym;
static aterm * lf_AUX_Trans_Set_Pats6_9( );
static asymbol * lf_AUX_Trans_Set_Pats6_10sym;
static aterm * lf_AUX_Trans_Set_Pats6_10( );
static asymbol * lf_AUX_Trans_Set_Pats6_11sym;
static aterm * lf_AUX_Trans_Set_Pats6_11( );
void register_AUX_Trans_Set_Pats6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Trans_Set_Pats6_1sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Trans_Set_Pats6_2sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_3sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_4sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_5sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_6sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r1-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_7sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r1-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_8sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r2-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_9sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r2-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_10sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r3-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Trans_Set_Pats6_11sym= TmkSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r3-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_1 , lf_AUX_Trans_Set_Pats6_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_2 , lf_AUX_Trans_Set_Pats6_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_3 , lf_AUX_Trans_Set_Pats6_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_4 , lf_AUX_Trans_Set_Pats6_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_5 , lf_AUX_Trans_Set_Pats6_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r1-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_6 , lf_AUX_Trans_Set_Pats6_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r1-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_7 , lf_AUX_Trans_Set_Pats6_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r2-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_8 , lf_AUX_Trans_Set_Pats6_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r2-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_9 , lf_AUX_Trans_Set_Pats6_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r3-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_10 , lf_AUX_Trans_Set_Pats6_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[ql(\"r3-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SPatType\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats6_11 , lf_AUX_Trans_Set_Pats6_11sym);
}
void resolve_AUX_Trans_Set_Pats6( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Trans_Set_Pats6_11( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_11);
return make_nf0( lf_AUX_Trans_Set_Pats6_11sym);
}
aterm * lf_AUX_Trans_Set_Pats6_10( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_10);
return make_nf0( lf_AUX_Trans_Set_Pats6_10sym);
}
aterm * lf_AUX_Trans_Set_Pats6_9( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_9);
return make_nf0( lf_AUX_Trans_Set_Pats6_9sym);
}
aterm * lf_AUX_Trans_Set_Pats6_8( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_8);
return make_nf0( lf_AUX_Trans_Set_Pats6_8sym);
}
aterm * lf_AUX_Trans_Set_Pats6_7( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_7);
return make_nf0( lf_AUX_Trans_Set_Pats6_7sym);
}
aterm * lf_AUX_Trans_Set_Pats6_6( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_6);
return make_nf0( lf_AUX_Trans_Set_Pats6_6sym);
}
aterm * lf_AUX_Trans_Set_Pats6_5( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_5);
return make_nf0( lf_AUX_Trans_Set_Pats6_5sym);
}
aterm * lf_AUX_Trans_Set_Pats6_4( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_4);
return make_nf0( lf_AUX_Trans_Set_Pats6_4sym);
}
aterm * lf_AUX_Trans_Set_Pats6_3( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_3);
return make_nf0( lf_AUX_Trans_Set_Pats6_3sym);
}
aterm * lf_AUX_Trans_Set_Pats6_2( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_2);
return make_nf0( lf_AUX_Trans_Set_Pats6_2sym);
}
aterm * lf_AUX_Trans_Set_Pats6_1( ) {
PROF( prof_lf_AUX_Trans_Set_Pats6_1);
return make_nf0( lf_AUX_Trans_Set_Pats6_1sym);
}

