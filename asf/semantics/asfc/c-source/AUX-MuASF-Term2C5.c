#include "support.h"
static asymbol * lf_AUX_MuASF_Term2C5_2sym;
static aterm * lf_AUX_MuASF_Term2C5_2( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5 , aterm * arg6 , aterm * arg7 , aterm * arg8);
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef28sym;
static funcptr ef28;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef29sym;
static funcptr ef29;
static asymbol * ef30sym;
static funcptr ef30;
static asymbol * ef31sym;
static funcptr ef31;
static asymbol * ef32sym;
static funcptr ef32;
static asymbol * ef33sym;
static funcptr ef33;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * lf_AUX_MuASF_Term2C5_1sym;
static aterm * lf_AUX_MuASF_Term2C5_1( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
void register_AUX_MuASF_Term2C5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Term2C5_2sym= TmkSymbol( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg2\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Term2C5_1sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Term2C5_1 , lf_AUX_MuASF_Term2C5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg2\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Term2C5_2 , lf_AUX_MuASF_Term2C5_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf5 , lf5sym);
}
void resolve_AUX_MuASF_Term2C5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++up\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++up\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-call-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-call-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"is-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"is-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"translate-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"translate-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-trans-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-trans-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"terms2cargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"terms2cargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Term2C5_2( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5 , aterm * arg6 , aterm * arg7) {
{
aterm * tmp[28];
PROF( prof_lf_AUX_MuASF_Term2C5_2);
if( check_sym( arg0 , ef11sym)) {
if( check_sym( arg7 , lf_AUX_MuASF_Term2C5_1sym)) {
{
aterm * atmp70= arg_0( arg7);
tmp[ 0]= ( * ef1)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 116)))))))))));
t_protect( arg5);
t_protect( tmp[ 0]);
if( ! term_equal( arg5 , tmp[ 0])) {
t_protect( arg1);
tmp[ 1]= ( * ef10)( arg1);
if( m_term_equal( tmp[ 1] , arg0)) {
t_protect( arg1);
tmp[ 2]= ( * ef18)( arg1);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef19)( ))) {
t_protect( arg1);
t_protect( arg2);
tmp[ 3]= ( * ef12)( arg1 , arg2);
if( check_sym( tmp[ 3] , ef13sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( tmp[ 4]);
tmp[ 5]= ( * ef14)( tmp[ 4]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef17)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 109)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))) , ( * ef5)( lf4( make_list( tmp[ 4])))))))) , tmp[ 5] , arg4);
}
t_unprotect( tmp[ 3]);
}
if( m_term_equal( tmp[ 2] , arg0)) {
t_protect( arg1);
t_protect( arg2);
tmp[ 3]= ( * ef12)( arg1 , arg2);
if( check_sym( tmp[ 3] , ef13sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( tmp[ 4]);
tmp[ 5]= ( * ef14)( tmp[ 4]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef4)( ( * ef5)( lf4( make_list( tmp[ 4]))) , tmp[ 5] , arg4);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
tmp[ 2]= ( * ef19)( );
if( m_term_equal( tmp[ 1] , tmp[ 2])) {
t_protect( arg1);
tmp[ 3]= ( * ef25)( arg1);
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef31)( ( * ef32)( tmp[ 3]));
if( m_term_equal( tmp[ 4] , arg0)) {
t_protect( tmp[ 3]);
tmp[ 5]= ( * ef23)( tmp[ 3]);
t_protect( arg1);
tmp[ 6]= ( * ef21)( arg1);
if( check_sym( tmp[ 6] , ef22sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( arg0);
t_protect( tmp[ 8]);
t_protect( arg2);
t_protect( arg3);
t_protect( arg4);
t_protect( arg5);
t_protect( arg6);
t_protect( atmp70);
tmp[ 9]= ( * ef33)( arg0 , lf5( make_list( tmp[ 8])) , arg2 , arg3 , arg4 , arg5 , arg6 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
if( check_sym( tmp[ 9] , ef4sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
tmp[ 12]= arg_2( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 9]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef17)( tmp[ 5] , tmp[ 10]))))) , tmp[ 11] , tmp[ 12]);
}
t_unprotect( tmp[ 9]);
}
}
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , ( * ef19)( ))) {
t_protect( arg1);
t_protect( arg2);
t_protect( arg3);
t_protect( arg4);
t_protect( arg5);
t_protect( arg6);
t_protect( atmp70);
tmp[ 5]= lf_AUX_MuASF_Term2C5_2( ( * ef19)( ) , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
if( check_sym( tmp[ 5] , ef4sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= arg_1( tmp[ 5]);
tmp[ 8]= arg_2( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef17)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 109)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))) , tmp[ 6]))))) , tmp[ 7] , tmp[ 8]);
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , ef19sym)) {
if( check_sym( arg5 , ef1sym)) {
{
aterm * atmp50= arg_0( arg5);
if( check_sym( atmp50 , ef2sym)) {
{
aterm * atmp500= arg_0( atmp50);
if( check_sym( atmp500 , ef3sym)) {
{
aterm * atmp5000= arg_0( atmp500);
if( check_sym( atmp5000 , lf3sym)) {
{
aterm * atmp50000= arg_0( atmp5000);
if( check_sym( arg7 , lf_AUX_MuASF_Term2C5_1sym)) {
{
aterm * atmp70= arg_0( arg7);
if( m_not_empty_list( atmp50000)) {
tmp[ 0]= m_list_head( atmp50000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 114))) {
tmp[ 1]= m_list_tail( atmp50000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 101))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
if( m_not_empty_list( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 115))) {
tmp[ 5]= m_list_tail( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 117))) {
tmp[ 7]= m_list_tail( tmp[ 5]);
{
if( m_not_empty_list( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 108))) {
tmp[ 9]= m_list_tail( tmp[ 7]);
{
if( m_is_single_element( tmp[ 9])) {
tmp[ 10]= m_list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 116))) {
t_protect( arg1);
tmp[ 11]= ( * ef10)( arg1);
if( m_term_equal( tmp[ 11] , arg0)) {
t_protect( arg1);
t_protect( atmp70);
tmp[ 12]= ( * ef20)( arg1 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
{
t_protect( tmp[ 12]);
tmp[ 13]= ( * ef23)( tmp[ 12]);
t_protect( arg1);
tmp[ 14]= ( * ef21)( arg1);
if( check_sym( tmp[ 14] , ef22sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , lf5sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( m_not_empty_list( tmp[ 16])) {
t_protect( arg4);
tmp[ 17]= ( * ef1)( ( * ef28)( arg4));
t_protect( arg1);
tmp[ 18]= ( * ef25)( arg1);
t_protect( tmp[ 18]);
t_protect( tmp[ 18]);
tmp[ 19]= ( * ef29)( ( * ef30)( tmp[ 18]) , ( * ef31)( ( * ef32)( tmp[ 18])));
t_protect( tmp[ 19]);
t_protect( tmp[ 16]);
t_protect( arg2);
t_protect( arg3);
t_protect( arg4);
t_protect( tmp[ 17]);
t_protect( arg6);
t_protect( atmp70);
tmp[ 20]= ( * ef33)( tmp[ 19] , lf5( make_list( tmp[ 16])) , arg2 , arg3 , arg4 , tmp[ 17] , arg6 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
if( check_sym( tmp[ 20] , ef4sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
tmp[ 22]= arg_1( tmp[ 20]);
tmp[ 23]= arg_2( tmp[ 20]);
if( check_sym( tmp[ 21] , ef5sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
if( check_sym( tmp[ 24] , lf4sym)) {
tmp[ 25]= arg_0( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( arg6);
tmp[ 26]= ( * ef15)( arg6);
t_protect( tmp[ 22]);
t_protect( tmp[ 26]);
tmp[ 27]= ( * ef16)( tmp[ 22] , tmp[ 26]);
t_protect( tmp[ 25]);
t_protect( tmp[ 23]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 26]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 116)))))))))))))) , ( * ef6)( tmp[ 27] , ( * ef7)( ( * ef8)( ( * ef9)( ( * ef1)( ( * ef17)( tmp[ 13] , ( * ef5)( lf4( make_list( tmp[ 25]))))))))) , tmp[ 23]);
}
}
}
}
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
}
}
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 13]);
t_protect( arg1);
if( term_equal( ( * ef21)( arg1) , ( * ef22)( lf5( make_list( null( )))))) {
t_protect( tmp[ 12]);
tmp[ 13]= ( * ef23)( tmp[ 12]);
t_protect( arg6);
tmp[ 14]= ( * ef15)( arg6);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 116)))))))))))))) , ( * ef6)( tmp[ 14] , ( * ef7)( ( * ef8)( ( * ef9)( ( * ef1)( ( * ef17)( tmp[ 13] , ( * ef5)( lf4( make_list( null( )))))))))) , arg4);
}
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
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
}
}
}
if( check_sym( arg7 , lf_AUX_MuASF_Term2C5_1sym)) {
{
aterm * atmp70= arg_0( arg7);
tmp[ 0]= ( * ef1)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 116)))))))))));
t_protect( arg5);
t_protect( tmp[ 0]);
if( ! term_equal( arg5 , tmp[ 0])) {
t_protect( arg1);
tmp[ 1]= ( * ef10)( arg1);
if( m_term_equal( tmp[ 1] , arg0)) {
t_protect( arg1);
tmp[ 2]= ( * ef21)( arg1);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef22)( lf5( make_list( null( )))))) {
t_protect( arg1);
tmp[ 3]= ( * ef25)( arg1);
t_protect( tmp[ 3]);
if( term_equal( ( * ef26)( tmp[ 3]) , ( * ef11)( ))) {
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef27)( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef17)( ( * ef2)( ( * ef3)( lf3( cons( make_list( make_char( 109)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 99)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 97)) , make_list( make_char( 114))))))))))))) , ( * ef5)( lf4( make_list( tmp[ 4])))))))) , ( * ef24)( ) , arg4);
}
t_unprotect( tmp[ 3]);
t_protect( arg1);
t_protect( atmp70);
tmp[ 3]= ( * ef20)( arg1 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
t_protect( tmp[ 3]);
t_protect( arg0);
if( term_equal( ( * ef26)( tmp[ 3]) , arg0)) {
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef23)( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef17)( tmp[ 4] , ( * ef5)( lf4( make_list( null( ))))))))) , ( * ef24)( ) , arg4);
}
t_unprotect( tmp[ 3]);
}
t_protect( arg1);
tmp[ 3]= ( * ef25)( arg1);
t_protect( arg1);
t_protect( atmp70);
tmp[ 4]= ( * ef20)( arg1 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
t_protect( tmp[ 4]);
tmp[ 5]= ( * ef23)( tmp[ 4]);
t_protect( arg1);
tmp[ 6]= ( * ef21)( arg1);
if( check_sym( tmp[ 6] , ef22sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( tmp[ 3]);
t_protect( tmp[ 3]);
tmp[ 9]= ( * ef29)( ( * ef30)( tmp[ 3]) , ( * ef31)( ( * ef32)( tmp[ 3])));
t_protect( tmp[ 9]);
t_protect( tmp[ 8]);
t_protect( arg2);
t_protect( arg3);
t_protect( arg4);
t_protect( arg5);
t_protect( arg6);
t_protect( atmp70);
tmp[ 10]= ( * ef33)( tmp[ 9] , lf5( make_list( tmp[ 8])) , arg2 , arg3 , arg4 , arg5 , arg6 , lf_AUX_MuASF_Term2C5_1( make_list( atmp70)));
if( check_sym( tmp[ 10] , ef4sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
tmp[ 13]= arg_2( tmp[ 10]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 13]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
return ( * ef4)( ( * ef5)( lf4( make_list( ( * ef1)( ( * ef17)( tmp[ 5] , tmp[ 11]))))) , tmp[ 12] , tmp[ 13]);
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
}
t_protect( tmp[ 1]);
if( term_equal( tmp[ 1] , ( * ef11)( ))) {
t_protect( arg1);
t_protect( arg2);
tmp[ 2]= ( * ef12)( arg1 , arg2);
if( check_sym( tmp[ 2] , ef13sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef14)( tmp[ 3]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef4)( ( * ef5)( lf4( make_list( tmp[ 3]))) , tmp[ 4] , arg4);
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg5 , ef1sym)) {
{
aterm * atmp50= arg_0( arg5);
if( check_sym( atmp50 , ef2sym)) {
{
aterm * atmp500= arg_0( atmp50);
if( check_sym( atmp500 , ef3sym)) {
{
aterm * atmp5000= arg_0( atmp500);
if( check_sym( atmp5000 , lf3sym)) {
{
aterm * atmp50000= arg_0( atmp5000);
if( check_sym( arg7 , lf_AUX_MuASF_Term2C5_1sym)) {
{
aterm * atmp70= arg_0( arg7);
if( m_not_empty_list( atmp50000)) {
t_protect( atmp50000);
if( term_equal( list_head( atmp50000) , make_char( 114))) {
tmp[ 0]= m_list_tail( atmp50000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 101))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 115))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 117))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 108))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_is_single_element( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
t_protect( arg1);
if( term_equal( ( * ef10)( arg1) , ( * ef11)( ))) {
t_protect( arg1);
t_protect( arg2);
tmp[ 5]= ( * ef12)( arg1 , arg2);
if( check_sym( tmp[ 5] , ef13sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
tmp[ 7]= ( * ef14)( tmp[ 6]);
t_protect( arg6);
tmp[ 8]= ( * ef15)( arg6);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
tmp[ 9]= ( * ef16)( tmp[ 7] , tmp[ 8]);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef4)( ( * ef5)( lf4( make_list( tmp[ 6]))) , ( * ef6)( tmp[ 9] , ( * ef7)( ( * ef8)( ( * ef9)( tmp[ 6])))) , arg4);
}
t_unprotect( tmp[ 5]);
}
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
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
}
}
}
}
return make_nf8( lf_AUX_MuASF_Term2C5_2sym , arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , arg7);
}
}
aterm * lf_AUX_MuASF_Term2C5_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Term2C5_1);
return make_nf1( lf_AUX_MuASF_Term2C5_1sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

