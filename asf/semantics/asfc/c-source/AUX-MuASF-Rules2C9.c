#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C9_3sym;
static aterm * lf_AUX_MuASF_Rules2C9_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * lf_AUX_MuASF_Rules2C9_1sym;
static aterm * lf_AUX_MuASF_Rules2C9_1( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C9_2sym;
static aterm * lf_AUX_MuASF_Rules2C9_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * ef28sym;
static funcptr ef28;
void register_AUX_MuASF_Rules2C9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C9_3sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C9_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C9_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C9_1 , lf_AUX_MuASF_Rules2C9_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C9_2 , lf_AUX_MuASF_Rules2C9_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C9_3 , lf_AUX_MuASF_Rules2C9_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_MuASF_Rules2C9( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-select-stat\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-select-stat\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"list2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"list2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats1\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats1\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Rules2C9_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
{
aterm * tmp[26];
PROF( prof_lf_AUX_MuASF_Rules2C9_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C9_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Rules2C9_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg3 , lf_AUX_MuASF_Rules2C9_2sym)) {
{
aterm * atmp30= arg_0( arg3);
t_protect( atmp00);
if( ! not_empty_list( atmp00)) {
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
tmp[ 0]= list_head( atmp10);
if( check_sym( tmp[ 0] , ef8sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 1] , lf5sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 2] , lf6sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
tmp[ 8]= list_head( tmp[ 6]);
if( check_sym( tmp[ 8] , ef10sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
if( check_sym( tmp[ 10] , lf7sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
t_protect( tmp[ 6]);
tmp[ 12]= list_tail( tmp[ 6]);
t_protect( tmp[ 12]);
if( not_empty_list( tmp[ 12])) {
t_protect( atmp10);
tmp[ 13]= list_tail( atmp10);
t_protect( tmp[ 9]);
if( term_equal( ( * ef12)( tmp[ 9]) , ( * ef13)( ))) {
t_protect( tmp[ 13]);
tmp[ 14]= ( * ef15)( lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 13])));
if( check_sym( tmp[ 14] , ef16sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
t_protect( tmp[ 11]);
tmp[ 17]= ( * ef14)( lf7( make_list( tmp[ 11])));
t_protect( tmp[ 12]);
t_protect( tmp[ 7]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 16]);
tmp[ 18]= ( * ef17)( lf_AUX_MuASF_Rules2C9_1( cons( make_list( ( * ef8)( lf5( make_list( tmp[ 12])) , lf6( make_list( tmp[ 7])) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 16]))));
if( check_sym( tmp[ 18] , ef18sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= arg_1( tmp[ 18]);
if( check_sym( tmp[ 19] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 21]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 22]= arg_0( tmp[ 20]);
t_protect( tmp[ 21]);
t_protect( tmp[ 22]);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 23]= lf_AUX_MuASF_Rules2C9_3( lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 21])) , lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 22])) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 23] , ef1sym)) {
tmp[ 24]= arg_0( tmp[ 23]);
tmp[ 25]= arg_1( tmp[ 23]);
t_protect( tmp[ 24]);
t_protect( tmp[ 25]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 23]);
return ( * ef1)( ( * ef11)( tmp[ 17] , tmp[ 24]) , tmp[ 25]);
}
t_unprotect( tmp[ 23]);
}
}
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 8]);
}
else {
t_protect( atmp10);
tmp[ 8]= list_tail( atmp10);
t_protect( tmp[ 7]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( atmp30);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
return ( * ef9)( lf_AUX_MuASF_Rules2C9_1( cons( make_list( ( * ef8)( lf5( make_list( null( ))) , lf6( make_list( tmp[ 7])) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 8]))) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
}
t_protect( tmp[ 6]);
if( is_single_element( tmp[ 6])) {
t_protect( tmp[ 6]);
tmp[ 8]= list_head( tmp[ 6]);
if( check_sym( tmp[ 8] , ef10sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
if( check_sym( tmp[ 10] , lf7sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
t_protect( atmp10);
tmp[ 12]= list_tail( atmp10);
t_protect( tmp[ 9]);
if( term_equal( ( * ef12)( tmp[ 9]) , ( * ef13)( ))) {
t_protect( tmp[ 11]);
tmp[ 13]= ( * ef14)( lf7( make_list( tmp[ 11])));
t_protect( tmp[ 9]);
t_protect( tmp[ 11]);
t_protect( tmp[ 7]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 12]);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 14]= ( * ef9)( lf_AUX_MuASF_Rules2C9_1( cons( make_list( ( * ef8)( lf5( make_list( ( * ef10)( tmp[ 9] , lf7( make_list( tmp[ 11]))))) , lf6( make_list( tmp[ 7])) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 12]))) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 14] , ef1sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
tmp[ 16]= arg_1( tmp[ 14]);
t_protect( tmp[ 15]);
t_protect( tmp[ 16]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 14]);
return ( * ef1)( ( * ef11)( tmp[ 13] , tmp[ 15]) , tmp[ 16]);
}
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 8]);
}
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
return ( * ef1)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( lf4( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , make_list( make_char( 101)))))))))))))))) , arg4);
}
}
else {
t_protect( atmp10);
if( ! not_empty_list( atmp10)) {
t_protect( atmp00);
tmp[ 0]= ( * ef19)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp00)));
if( check_sym( tmp[ 0] , ef10sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 1] , ef20sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 2] , lf7sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( term_equal( ( * ef21)( tmp[ 3]) , ( * ef13)( ))) {
t_protect( tmp[ 4]);
tmp[ 5]= ( * ef14)( lf7( make_list( tmp[ 4])));
t_protect( atmp00);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 6]= ( * ef22)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp00)) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef11)( tmp[ 5] , tmp[ 7]) , tmp[ 8]);
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( atmp30);
tmp[ 5]= ( * ef23)( ( * ef10)( ( * ef20)( tmp[ 3]) , lf7( make_list( tmp[ 4]))) , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)));
t_protect( tmp[ 4]);
tmp[ 6]= ( * ef14)( lf7( make_list( tmp[ 4])));
t_protect( tmp[ 3]);
if( term_equal( ( * ef21)( tmp[ 3]) , ( * ef24)( ))) {
t_protect( atmp00);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 7]= ( * ef25)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp00)) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 7] , ef1sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
t_protect( tmp[ 5]);
t_protect( tmp[ 8]);
tmp[ 10]= ( * ef26)( tmp[ 5] , tmp[ 8]);
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef11)( tmp[ 6] , tmp[ 10]) , tmp[ 9]);
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
else {
t_protect( atmp00);
tmp[ 0]= ( * ef19)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp00)));
if( check_sym( tmp[ 0] , ef10sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 1] , ef20sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 2] , lf7sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( term_equal( ( * ef21)( tmp[ 3]) , ( * ef13)( ))) {
t_protect( tmp[ 4]);
tmp[ 5]= ( * ef14)( lf7( make_list( tmp[ 4])));
t_protect( atmp00);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 6]= ( * ef22)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp00)) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
t_protect( atmp10);
tmp[ 9]= ( * ef17)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp10)));
if( check_sym( tmp[ 9] , ef18sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 12]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 13]);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 14]= lf_AUX_MuASF_Rules2C9_3( lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 12])) , lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 13])) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 14] , ef1sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
tmp[ 16]= arg_1( tmp[ 14]);
t_protect( tmp[ 5]);
t_protect( tmp[ 7]);
tmp[ 17]= ( * ef11)( tmp[ 5] , tmp[ 7]);
t_protect( tmp[ 17]);
t_protect( tmp[ 15]);
tmp[ 18]= ( * ef27)( tmp[ 17] , tmp[ 15]);
t_protect( tmp[ 8]);
t_protect( tmp[ 16]);
tmp[ 19]= ( * ef28)( tmp[ 8] , tmp[ 16]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 17]);
return ( * ef1)( tmp[ 18] , tmp[ 19]);
}
t_unprotect( tmp[ 14]);
}
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( atmp30);
tmp[ 5]= ( * ef23)( ( * ef10)( ( * ef20)( tmp[ 3]) , lf7( make_list( tmp[ 4]))) , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)));
t_protect( tmp[ 4]);
tmp[ 6]= ( * ef14)( lf7( make_list( tmp[ 4])));
t_protect( tmp[ 3]);
if( term_equal( ( * ef21)( tmp[ 3]) , ( * ef24)( ))) {
t_protect( atmp00);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 7]= ( * ef25)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp00)) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 7] , ef1sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
t_protect( atmp10);
tmp[ 10]= ( * ef17)( lf_AUX_MuASF_Rules2C9_1( make_list( atmp10)));
if( check_sym( tmp[ 10] , ef18sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
if( check_sym( tmp[ 11] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 12] , lf_AUX_MuASF_Rules2C9_1sym)) {
tmp[ 14]= arg_0( tmp[ 12]);
t_protect( tmp[ 13]);
t_protect( tmp[ 14]);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 15]= lf_AUX_MuASF_Rules2C9_3( lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 13])) , lf_AUX_MuASF_Rules2C9_1( make_list( tmp[ 14])) , arg2 , lf_AUX_MuASF_Rules2C9_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 15] , ef1sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
tmp[ 17]= arg_1( tmp[ 15]);
t_protect( tmp[ 5]);
t_protect( tmp[ 8]);
t_protect( tmp[ 16]);
tmp[ 18]= ( * ef29)( tmp[ 5] , tmp[ 8] , tmp[ 16]);
t_protect( tmp[ 9]);
t_protect( tmp[ 17]);
tmp[ 19]= ( * ef28)( tmp[ 9] , tmp[ 17]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 15]);
return ( * ef1)( ( * ef11)( tmp[ 6] , tmp[ 18]) , tmp[ 19]);
}
t_unprotect( tmp[ 15]);
}
}
}
t_unprotect( tmp[ 10]);
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
}
}
return make_nf5( lf_AUX_MuASF_Rules2C9_3sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
}
aterm * lf_AUX_MuASF_Rules2C9_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C9_2);
return make_nf1( lf_AUX_MuASF_Rules2C9_2sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C9_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C9_1);
return make_nf1( lf_AUX_MuASF_Rules2C9_1sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

