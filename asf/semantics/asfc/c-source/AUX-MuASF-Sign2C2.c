#include "support.h"
static asymbol * lf_AUX_MuASF_Sign2C2_2sym;
static aterm * lf_AUX_MuASF_Sign2C2_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf_AUX_MuASF_Sign2C2_1sym;
static aterm * lf_AUX_MuASF_Sign2C2_1( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_MuASF_Sign2C2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Sign2C2_2sym= TmkSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Type-specifier\"))" , SYM_STRING);
lf_AUX_MuASF_Sign2C2_1sym= TmkSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"SigArg\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C2_1 , lf_AUX_MuASF_Sign2C2_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C2_2 , lf_AUX_MuASF_Sign2C2_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Type-specifier\"))") , lf5 , lf5sym);
}
void resolve_AUX_MuASF_Sign2C2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Sign2C2_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[5];
PROF( prof_lf_AUX_MuASF_Sign2C2_2);
if( check_sym( arg0 , lf_AUX_MuASF_Sign2C2_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf3sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( lf4( make_list( ( * ef3)( ( * ef4)( lf5( make_list( ( * ef5)( ( * ef6)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , make_list( make_char( 109)))))))))))) , ( * ef7)( ( * ef8)( ( * ef6)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 103)) , make_list( atmp100))))))))))));
}
}
}
}
}
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
t_protect( arg1);
tmp[ 2]= lf_AUX_MuASF_Sign2C2_2( lf_AUX_MuASF_Sign2C2_1( make_list( tmp[ 1])) , ( * ef10)( arg1));
if( check_sym( arg1 , ef1sym)) {
tmp[ 3]= arg_0( arg1);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef9)( ( * ef3)( ( * ef4)( lf5( make_list( ( * ef5)( ( * ef6)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , make_list( make_char( 109)))))))))))) , ( * ef7)( ( * ef8)( ( * ef6)( lf3( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 103)) , make_list( tmp[ 4]))))))))) , tmp[ 2]);
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_MuASF_Sign2C2_2sym , arg0 , arg1);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf_AUX_MuASF_Sign2C2_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C2_1);
return make_nf1( lf_AUX_MuASF_Sign2C2_1sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

