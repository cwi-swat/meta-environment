#include "support.h"
static asymbol * lf_AUX_WfAsFixTerm2_1sym;
static aterm * lf_AUX_WfAsFixTerm2_1( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * ef31sym;
static funcptr ef31;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef30sym;
static funcptr ef30;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef32sym;
static funcptr ef32;
static asymbol * ef33sym;
static funcptr ef33;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef34sym;
static funcptr ef34;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef35sym;
static funcptr ef35;
static asymbol * ef36sym;
static funcptr ef36;
static asymbol * ef37sym;
static funcptr ef37;
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef38sym;
static funcptr ef38;
static asymbol * ef39sym;
static funcptr ef39;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
void register_AUX_WfAsFixTerm2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFixTerm2_1sym= TmkSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm2_1 , lf_AUX_WfAsFixTerm2_1sym);
}
void resolve_AUX_WfAsFixTerm2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"syms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"syms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterm-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterm-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef36= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef36sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_WfAsFixTerm2_1( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_WfAsFixTerm2_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_unprotect( arg0);
return ( * ef1)( ( * ef3)( ));
}
}
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
t_unprotect( arg0);
return ( * ef1)( atmp00);
}
}
}
if( check_sym( arg0 , ef4sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef5sym)) {
t_unprotect( arg0);
return ( * ef4)( ( * ef5)( ));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef6sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef7sym)) {
{
aterm * atmp0000= arg_0( atmp000);
t_protect( atmp0000);
t_unprotect( arg0);
return ( * ef4)( ( * ef6)( ( * ef7)( lf_AUX_WfAsFixTerm2_1( atmp0000))));
}
}
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef8sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp0001= arg_1( atmp000);
t_protect( atmp0000);
t_protect( atmp0001);
t_unprotect( arg0);
return ( * ef4)( ( * ef6)( ( * ef8)( lf_AUX_WfAsFixTerm2_1( atmp0000) , ( * ef9)( lf_AUX_WfAsFixTerm2_1( ( * ef4)( ( * ef6)( atmp0001)))))));
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef10sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp01);
t_unprotect( arg0);
return lf_AUX_WfAsFixTerm2_1( atmp01);
}
}
}
if( check_sym( arg0 , ef11sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef12sym)) {
{
aterm * atmp01= arg_1( arg0);
t_protect( arg0);
tmp[ 0]= arg0;
t_protect( tmp[ 0]);
if( term_equal( ( * ef16)( ( * ef17)( ( * ef18)( )) , ( * ef13)( tmp[ 0] , ( * ef14)( ))) , ( * ef19)( ))) {
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( ( * ef20)( ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef14)( )) , ( * ef21)( )) , lf_AUX_WfAsFixTerm2_1( ( * ef13)( tmp[ 0] , ( * ef22)( )))) , ( * ef19)( ))) {
t_unprotect( arg0);
return ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef14)( )) , ( * ef15)( ));
}
}
t_unprotect( tmp[ 0]);
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef23sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
t_protect( arg0);
tmp[ 0]= arg0;
tmp[ 1]= ( * ef19)( );
t_protect( tmp[ 0]);
t_protect( tmp[ 1]);
if( term_equal( ( * ef24)( ( * ef25)( ) , ( * ef13)( tmp[ 0] , ( * ef15)( ))) , tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( ( * ef26)( ( * ef27)( ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef15)( )) , ( * ef15)( ))) , ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef15)( )) , ( * ef28)( )) , ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef15)( )) , ( * ef29)( )) , ( * ef27)( ( * ef13)( tmp[ 0] , ( * ef30)( )))) , ( * ef19)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 1]);
return ( * ef13)( tmp[ 0] , ( * ef15)( ));
}
}
t_protect( tmp[ 0]);
t_protect( tmp[ 1]);
if( term_equal( ( * ef24)( ( * ef29)( ) , ( * ef13)( tmp[ 0] , ( * ef15)( ))) , tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( ( * ef31)( ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef15)( )) , ( * ef15)( )) , ( * ef13)( ( * ef13)( tmp[ 0] , ( * ef15)( )) , ( * ef29)( )) , ( * ef27)( ( * ef13)( tmp[ 0] , ( * ef30)( )))) , ( * ef19)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 1]);
return ( * ef13)( tmp[ 0] , ( * ef15)( ));
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef32sym)) {
{
aterm * atmp01= arg_1( arg0);
return ( * ef13)( arg0 , ( * ef15)( ));
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef33sym)) {
{
aterm * atmp01= arg_1( arg0);
return ( * ef13)( arg0 , ( * ef15)( ));
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef34sym)) {
{
aterm * atmp01= arg_1( arg0);
return ( * ef13)( arg0 , ( * ef15)( ));
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef35sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef1sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef2sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return ( * ef11)( ( * ef35)( ) , ( * ef7)( ( * ef1)( ( * ef2)( atmp01000))));
}
}
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef36sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef1sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef2sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return ( * ef11)( ( * ef36)( ) , ( * ef7)( ( * ef1)( ( * ef2)( atmp01000))));
}
}
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef37sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef1sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef2sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return ( * ef11)( ( * ef37)( ) , ( * ef7)( ( * ef1)( ( * ef2)( atmp01000))));
}
}
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef28sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef1sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef2sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return ( * ef11)( ( * ef28)( ) , ( * ef7)( ( * ef1)( ( * ef2)( atmp01000))));
}
}
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef38sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef1sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef2sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return ( * ef11)( ( * ef38)( ) , ( * ef7)( ( * ef1)( ( * ef2)( atmp01000))));
}
}
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef39sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef7sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef1sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef2sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return ( * ef11)( ( * ef39)( ) , ( * ef7)( ( * ef1)( ( * ef2)( atmp01000))));
}
}
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef29sym)) {
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp01);
t_unprotect( arg0);
return ( * ef11)( ( * ef29)( ) , atmp01);
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef25sym)) {
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp01);
t_unprotect( arg0);
return ( * ef11)( ( * ef25)( ) , atmp01);
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
t_unprotect( arg0);
return ( * ef1)( ( * ef3)( ));
}
}

