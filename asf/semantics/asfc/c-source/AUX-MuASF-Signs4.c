#include "support.h"
static asymbol * lf_AUX_MuASF_Signs4_1sym;
static aterm * lf_AUX_MuASF_Signs4_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
void register_AUX_MuASF_Signs4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Signs4_1sym= TmkSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"add-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"add-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs4_1 , lf_AUX_MuASF_Signs4_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"SigArg\"),ql(\",\"))") , lf4 , lf4sym);
}
void resolve_AUX_MuASF_Signs4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Signs4_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Signs4_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
t_unprotect( arg0);
return ( * ef2)( atmp00 , ( * ef3)( lf2( make_list( ( * ef4)( ( * ef5)( lf3( cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))));
}
}
if( check_sym( arg0 , ef6sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf4sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( m_not_empty_list( atmp010)) {
t_protect( atmp00);
t_protect( atmp010);
t_unprotect( arg0);
return ( * ef7)( atmp00 , lf4( make_list( atmp010)) , ( * ef3)( lf2( make_list( ( * ef4)( ( * ef5)( lf3( cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))));
}
}
}
}
}
}
return arg0;
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

