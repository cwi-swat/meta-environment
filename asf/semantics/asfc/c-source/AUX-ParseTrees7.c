#include "support.h"
static asymbol * lf_AUX_ParseTrees7_1sym;
static aterm * lf_AUX_ParseTrees7_1( aterm * arg1 , aterm * arg2);
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef24sym;
static funcptr ef24;
static asymbol * ef25sym;
static funcptr ef25;
static asymbol * ef26sym;
static funcptr ef26;
static asymbol * ef27sym;
static funcptr ef27;
static asymbol * ef28sym;
static funcptr ef28;
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
static asymbol * ef34sym;
static funcptr ef34;
static asymbol * ef35sym;
static funcptr ef35;
static asymbol * ef36sym;
static funcptr ef36;
static asymbol * ef37sym;
static funcptr ef37;
static asymbol * ef38sym;
static funcptr ef38;
static asymbol * ef39sym;
static funcptr ef39;
static asymbol * ef40sym;
static funcptr ef40;
static asymbol * ef41sym;
static funcptr ef41;
static asymbol * ef42sym;
static funcptr ef42;
static asymbol * ef43sym;
static funcptr ef43;
static asymbol * ef44sym;
static funcptr ef44;
static asymbol * ef45sym;
static funcptr ef45;
static asymbol * ef46sym;
static funcptr ef46;
static asymbol * ef47sym;
static funcptr ef47;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef50sym;
static funcptr ef50;
static asymbol * ef51sym;
static funcptr ef51;
static asymbol * ef52sym;
static funcptr ef52;
static asymbol * ef56sym;
static funcptr ef56;
static asymbol * ef55sym;
static funcptr ef55;
static asymbol * ef58sym;
static funcptr ef58;
static asymbol * ef59sym;
static funcptr ef59;
static asymbol * ef60sym;
static funcptr ef60;
static asymbol * ef57sym;
static funcptr ef57;
static asymbol * ef61sym;
static funcptr ef61;
static asymbol * ef62sym;
static funcptr ef62;
static asymbol * ef63sym;
static funcptr ef63;
static asymbol * ef64sym;
static funcptr ef64;
static asymbol * ef65sym;
static funcptr ef65;
static asymbol * ef66sym;
static funcptr ef66;
static asymbol * ef67sym;
static funcptr ef67;
static asymbol * ef68sym;
static funcptr ef68;
static asymbol * ef69sym;
static funcptr ef69;
static asymbol * ef70sym;
static funcptr ef70;
static asymbol * ef71sym;
static funcptr ef71;
static asymbol * ef72sym;
static funcptr ef72;
static asymbol * ef73sym;
static funcptr ef73;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef74sym;
static funcptr ef74;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef75sym;
static funcptr ef75;
static asymbol * ef76sym;
static funcptr ef76;
static asymbol * ef80sym;
static funcptr ef80;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef83sym;
static funcptr ef83;
static asymbol * ef92sym;
static funcptr ef92;
static asymbol * ef86sym;
static funcptr ef86;
static asymbol * ef90sym;
static funcptr ef90;
static asymbol * ef91sym;
static funcptr ef91;
static asymbol * ef96sym;
static funcptr ef96;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef85sym;
static funcptr ef85;
static asymbol * ef87sym;
static funcptr ef87;
static asymbol * ef84sym;
static funcptr ef84;
static asymbol * ef88sym;
static funcptr ef88;
static asymbol * ef49sym;
static funcptr ef49;
static asymbol * ef94sym;
static funcptr ef94;
static asymbol * ef95sym;
static funcptr ef95;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef53sym;
static funcptr ef53;
static asymbol * ef97sym;
static funcptr ef97;
static asymbol * ef48sym;
static funcptr ef48;
static asymbol * ef81sym;
static funcptr ef81;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef98sym;
static funcptr ef98;
static asymbol * ef93sym;
static funcptr ef93;
static asymbol * ef82sym;
static funcptr ef82;
static asymbol * ef77sym;
static funcptr ef77;
static asymbol * ef78sym;
static funcptr ef78;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef54sym;
static funcptr ef54;
static asymbol * ef79sym;
static funcptr ef79;
static asymbol * ef89sym;
static funcptr ef89;
void register_AUX_ParseTrees7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ParseTrees7_1sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees7_1 , lf_AUX_ParseTrees7_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_ParseTrees7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"QLiteral\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"QLiteral\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Separator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Separator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"char-class\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"char-class\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef24= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"aprod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"aprod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef25= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef26= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef27= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef28= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef29= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"asfix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"asfix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef30= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef31= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef32= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Section\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Section\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"exports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"exports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"hiddens\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"hiddens\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef36= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef36sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sorts\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sorts\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lexical-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lexical-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"context-free-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"context-free-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef40= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef40sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef41= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"variables\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef41sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"variables\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef42= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef42sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef43= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef43sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef44= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef44sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef45= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attribute\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef45sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attribute\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef46= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attr\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef46sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attr\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef47= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef47sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef48= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef48sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef49= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef49sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef50= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"neg\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef50sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"neg\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef51= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef51sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef52= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef52sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef53= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef53sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef54= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef54sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef55= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ProdSkel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef55sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ProdSkel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef56= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod-skel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef56sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod-skel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef57= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef57sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef58= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef58sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef59= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"agroup\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef59sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"agroup\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef60= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Priority\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef60sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Priority\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef61= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"decr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef61sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"decr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef62= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"incr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef62sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"incr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef63= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prio-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef63sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prio-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef64= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef64sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef65= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef65sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef66= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef66sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef67= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef67sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef68= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef68sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef69= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CondEquation\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef69sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CondEquation\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef70= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef70sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef71= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef71sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef72= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef72sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef73= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ExtAsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef73sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ExtAsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef74= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef74sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef75= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef75sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef76= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef76sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef77= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef77sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef78= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef78sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef79= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef79sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef80= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef80sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef81= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef81sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef82= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef82sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef83= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef83sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef84= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef84sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef85= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef85sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef86= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef86sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef87= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef87sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef88= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef88sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef89= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef89sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef90= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef90sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef91= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef91sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef92= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef92sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef93= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef93sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef94= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef94sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef95= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef95sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef96= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef96sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef97= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef97sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef98= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef98sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ParseTrees7_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[23];
PROF( prof_lf_AUX_ParseTrees7_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef4)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef5sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef6)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef7sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef8)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef9sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef10)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef11sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef12)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef13sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef14)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef15sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef16)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef17sym)) {
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef5)( )) , arg1) , ( * ef3)( ( * ef19)( ) , arg1)) , ( * ef3)( ( * ef20)( ) , arg1)) , ( * ef3)( ( * ef21)( ) , arg1)) , ( * ef3)( ( * ef22)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef23sym)) {
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef3)( ( * ef24)( ) , arg1) , ( * ef3)( ( * ef25)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef26sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef27)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef28sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef29)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef30sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef31)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef32sym)) {
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef3)( ( * ef33)( ) , arg1) , ( * ef3)( ( * ef34)( ) , arg1)) , ( * ef3)( ( * ef35)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef36sym)) {
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef3)( ( * ef37)( ) , arg1) , ( * ef3)( ( * ef38)( ) , arg1)) , ( * ef3)( ( * ef39)( ) , arg1)) , ( * ef3)( ( * ef40)( ) , arg1)) , ( * ef3)( ( * ef41)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef42sym)) {
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef3)( ( * ef43)( ) , arg1) , ( * ef3)( ( * ef44)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef45sym)) {
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef5)( )) , arg1) , ( * ef3)( ( * ef46)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef47sym)) {
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef5)( )) , arg1) , lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef7)( )) , arg1)) , lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef11)( )) , arg1)) , lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef15)( )) , arg1)) , ( * ef3)( ( * ef48)( ) , arg1)) , ( * ef3)( ( * ef49)( ) , arg1)) , ( * ef3)( ( * ef50)( ) , arg1)) , ( * ef3)( ( * ef51)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef52sym)) {
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef53)( ( * ef54)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 102)) , cons( make_list( make_char( 116)) , make_list( make_char( 34)))))))))) , arg1) , lf_AUX_ParseTrees7_1( ( * ef53)( ( * ef54)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 116)) , make_list( make_char( 34))))))))))) , arg1)) , lf_AUX_ParseTrees7_1( ( * ef53)( ( * ef54)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , make_list( make_char( 34))))))))))))))) , arg1)) , lf_AUX_ParseTrees7_1( ( * ef53)( ( * ef54)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 99)) , make_list( make_char( 34))))))))))) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef55sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef56)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef57sym)) {
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef55)( )) , arg1) , ( * ef3)( ( * ef58)( ) , arg1)) , ( * ef3)( ( * ef59)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef60sym)) {
t_protect( arg1);
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef57)( )) , arg1) , ( * ef3)( ( * ef61)( ) , arg1)) , ( * ef3)( ( * ef62)( ) , arg1)) , ( * ef3)( ( * ef63)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef64sym)) {
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef3)( ( * ef65)( ) , arg1) , ( * ef3)( ( * ef66)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef67sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef68)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef69sym)) {
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( ( * ef3)( ( * ef70)( ) , arg1) , ( * ef3)( ( * ef71)( ) , arg1)) , ( * ef3)( ( * ef72)( ) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef73sym)) {
t_protect( arg1);
t_protect( arg1);
t_unprotect( arg0);
return ( * ef18)( ( * ef18)( lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef17)( )) , arg1) , lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef2)( )) , arg1)) , lf_AUX_ParseTrees7_1( ( * ef1)( ( * ef13)( )) , arg1));
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef74sym)) {
t_unprotect( arg0);
return ( * ef3)( ( * ef75)( ) , arg1);
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef76sym)) {
if( check_sym( arg1 , ef77sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef78sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef80sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef81sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef77sym)) {
{
aterm * atmp11100= arg_0( atmp1110);
if( m_term_equal( atmp00 , atmp11100)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
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
if( check_sym( arg0 , ef53sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef81sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef6sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef82sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
if( m_term_equal( atmp00 , atmp11000)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
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
if( check_sym( arg1 , ef77sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef78sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( m_term_equal( atmp00 , atmp100)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
}
}
}
}
}
}
}
if( check_sym( arg0 , ef84sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef81sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
aterm * atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef49sym)) {
{
aterm * atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
aterm * atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef81sym)) {
{
aterm * atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef12sym)) {
{
aterm * atmp1110101= arg_1( atmp111010);
if( check_sym( atmp1110101 , ef82sym)) {
{
aterm * atmp11101010= arg_0( atmp1110101);
if( check_sym( atmp11101010 , ef77sym)) {
{
aterm * atmp111010100= arg_0( atmp11101010);
if( check_sym( atmp111010100 , ef78sym)) {
{
aterm * atmp1110101000= arg_0( atmp111010100);
if( check_sym( atmp1110101000 , ef98sym)) {
{
aterm * atmp11101010000= arg_0( atmp1110101000);
{
aterm * atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
aterm * atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
aterm * atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
aterm * atmp111011000= arg_0( atmp11101100);
{
aterm * atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef82sym)) {
{
aterm * atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef77sym)) {
{
aterm * atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef78sym)) {
{
aterm * atmp1110111000= arg_0( atmp111011100);
if( check_sym( atmp1110111000 , ef54sym)) {
{
aterm * atmp11101110000= arg_0( atmp1110111000);
if( check_sym( atmp11101110000 , lf2sym)) {
{
aterm * atmp111011100000= arg_0( atmp11101110000);
if( m_not_empty_list( atmp111011100000)) {
t_protect( atmp111011100000);
if( term_equal( list_head( atmp111011100000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp111011100000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 42))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( m_term_equal( atmp000 , atmp11101010000)) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef79)( );
}
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
}
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
if( check_sym( arg1 , ef85sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
}
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef87sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp00);
t_unprotect( arg0);
return lf_AUX_ParseTrees7_1( ( * ef88)( atmp00) , arg1);
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef88sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef81sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
aterm * atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef49sym)) {
{
aterm * atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
aterm * atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef81sym)) {
{
aterm * atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef12sym)) {
{
aterm * atmp1110101= arg_1( atmp111010);
if( check_sym( atmp1110101 , ef82sym)) {
{
aterm * atmp11101010= arg_0( atmp1110101);
if( check_sym( atmp11101010 , ef77sym)) {
{
aterm * atmp111010100= arg_0( atmp11101010);
if( check_sym( atmp111010100 , ef78sym)) {
{
aterm * atmp1110101000= arg_0( atmp111010100);
if( check_sym( atmp1110101000 , ef98sym)) {
{
aterm * atmp11101010000= arg_0( atmp1110101000);
{
aterm * atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
aterm * atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
aterm * atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
aterm * atmp111011000= arg_0( atmp11101100);
{
aterm * atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef82sym)) {
{
aterm * atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef77sym)) {
{
aterm * atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef78sym)) {
{
aterm * atmp1110111000= arg_0( atmp111011100);
if( check_sym( atmp1110111000 , ef54sym)) {
{
aterm * atmp11101110000= arg_0( atmp1110111000);
if( check_sym( atmp11101110000 , lf2sym)) {
{
aterm * atmp111011100000= arg_0( atmp11101110000);
if( m_not_empty_list( atmp111011100000)) {
t_protect( atmp111011100000);
if( term_equal( list_head( atmp111011100000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp111011100000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 43))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( m_term_equal( atmp000 , atmp11101010000)) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef79)( );
}
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
}
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
if( check_sym( arg1 , ef85sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef89)( );
}
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
if( term_equal( ( * ef92)( atmp10) , ( * ef86)( ))) {
t_protect( atmp00);
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return lf_AUX_ParseTrees7_1( atmp00 , ( * ef91)( atmp10));
}
t_protect( atmp10);
tmp[ 0]= ( * ef92)( atmp10);
if( check_sym( tmp[ 0] , ef87sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef93sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
if( check_sym( tmp[ 2] , ef81sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
tmp[ 5]= arg_1( tmp[ 2]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , ( * ef4)( ))) {
if( check_sym( tmp[ 5] , ef82sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , ef77sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , ef78sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
t_protect( atmp00);
t_protect( atmp10);
t_protect( atmp00);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef90)( lf_AUX_ParseTrees7_1( atmp00 , ( * ef91)( atmp10)) , lf_AUX_ParseTrees7_1( ( * ef84)( atmp00) , ( * ef85)( ( * ef87)( tmp[ 3]))));
}
}
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
if( check_sym( arg0 , ef94sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
aterm * atmp000= arg_0( atmp00);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef53sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( arg1 , ef81sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
aterm * atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef48sym)) {
{
aterm * atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
aterm * atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef77sym)) {
{
aterm * atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef78sym)) {
{
aterm * atmp11101000= arg_0( atmp1110100);
if( check_sym( atmp11101000 , ef54sym)) {
{
aterm * atmp111010000= arg_0( atmp11101000);
if( check_sym( atmp111010000 , lf2sym)) {
{
aterm * atmp1110100000= arg_0( atmp111010000);
{
aterm * atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
aterm * atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
aterm * atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
aterm * atmp111011000= arg_0( atmp11101100);
{
aterm * atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef93sym)) {
{
aterm * atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef81sym)) {
{
aterm * atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef12sym)) {
{
aterm * atmp111011101= arg_1( atmp11101110);
if( check_sym( atmp111011101 , ef82sym)) {
{
aterm * atmp1110111010= arg_0( atmp111011101);
if( check_sym( atmp1110111010 , ef77sym)) {
{
aterm * atmp11101110100= arg_0( atmp1110111010);
if( check_sym( atmp11101110100 , ef78sym)) {
{
aterm * atmp111011101000= arg_0( atmp11101110100);
if( check_sym( atmp111011101000 , ef98sym)) {
{
aterm * atmp1110111010000= arg_0( atmp111011101000);
{
aterm * atmp11101111= arg_1( atmp1110111);
if( check_sym( atmp11101111 , ef93sym)) {
{
aterm * atmp111011110= arg_0( atmp11101111);
if( check_sym( atmp111011110 , ef77sym)) {
{
aterm * atmp1110111100= arg_0( atmp111011110);
if( check_sym( atmp1110111100 , ef78sym)) {
{
aterm * atmp11101111000= arg_0( atmp1110111100);
{
aterm * atmp111011111= arg_1( atmp11101111);
if( check_sym( atmp111011111 , ef93sym)) {
{
aterm * atmp1110111110= arg_0( atmp111011111);
if( check_sym( atmp1110111110 , ef77sym)) {
{
aterm * atmp11101111100= arg_0( atmp1110111110);
if( check_sym( atmp11101111100 , ef78sym)) {
{
aterm * atmp111011111000= arg_0( atmp11101111100);
{
aterm * atmp1110111111= arg_1( atmp111011111);
if( check_sym( atmp1110111111 , ef93sym)) {
{
aterm * atmp11101111110= arg_0( atmp1110111111);
if( check_sym( atmp11101111110 , ef77sym)) {
{
aterm * atmp111011111100= arg_0( atmp11101111110);
if( check_sym( atmp111011111100 , ef78sym)) {
{
aterm * atmp1110111111000= arg_0( atmp111011111100);
{
aterm * atmp11101111111= arg_1( atmp1110111111);
if( check_sym( atmp11101111111 , ef93sym)) {
{
aterm * atmp111011111110= arg_0( atmp11101111111);
if( check_sym( atmp111011111110 , ef77sym)) {
{
aterm * atmp1110111111100= arg_0( atmp111011111110);
if( check_sym( atmp1110111111100 , ef78sym)) {
{
aterm * atmp11101111111000= arg_0( atmp1110111111100);
if( check_sym( atmp11101111111000 , ef54sym)) {
{
aterm * atmp111011111110000= arg_0( atmp11101111111000);
if( check_sym( atmp111011111110000 , lf2sym)) {
{
aterm * atmp1110111111100000= arg_0( atmp111011111110000);
{
aterm * atmp111011111111= arg_1( atmp11101111111);
if( check_sym( atmp111011111111 , ef93sym)) {
{
aterm * atmp1110111111110= arg_0( atmp111011111111);
if( check_sym( atmp1110111111110 , ef77sym)) {
{
aterm * atmp11101111111100= arg_0( atmp1110111111110);
if( check_sym( atmp11101111111100 , ef78sym)) {
{
aterm * atmp111011111111000= arg_0( atmp11101111111100);
{
aterm * atmp1110111111111= arg_1( atmp111011111111);
if( check_sym( atmp1110111111111 , ef82sym)) {
{
aterm * atmp11101111111110= arg_0( atmp1110111111111);
if( check_sym( atmp11101111111110 , ef77sym)) {
{
aterm * atmp111011111111100= arg_0( atmp11101111111110);
if( check_sym( atmp111011111111100 , ef78sym)) {
{
aterm * atmp1110111111111000= arg_0( atmp111011111111100);
if( check_sym( atmp1110111111111000 , ef54sym)) {
{
aterm * atmp11101111111110000= arg_0( atmp1110111111111000);
if( check_sym( atmp11101111111110000 , lf2sym)) {
{
aterm * atmp111011111111100000= arg_0( atmp11101111111110000);
if( m_not_empty_list( atmp1110100000)) {
t_protect( atmp1110100000);
if( term_equal( list_head( atmp1110100000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp1110100000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( m_not_empty_list( atmp1110111111100000)) {
t_protect( atmp1110111111100000);
if( term_equal( list_head( atmp1110111111100000) , make_char( 34))) {
tmp[ 2]= m_list_tail( atmp1110111111100000);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 125))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 34))) {
if( m_not_empty_list( atmp111011111111100000)) {
t_protect( atmp111011111111100000);
if( term_equal( list_head( atmp111011111111100000) , make_char( 34))) {
tmp[ 4]= m_list_tail( atmp111011111111100000);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 42))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_is_single_element( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 34))) {
if( m_term_equal( atmp000 , atmp1110111010000)) {
if( m_term_equal( atmp010 , atmp111011111000)) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef79)( );
}
}
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
}
}
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
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( arg1 , ef85sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef79)( );
}
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef87sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp00);
t_protect( atmp01);
t_unprotect( arg0);
return lf_AUX_ParseTrees7_1( ( * ef95)( atmp00 , atmp01) , arg1);
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef95sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
aterm * atmp000= arg_0( atmp00);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef53sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( arg1 , ef81sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
aterm * atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef48sym)) {
{
aterm * atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
aterm * atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef77sym)) {
{
aterm * atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef78sym)) {
{
aterm * atmp11101000= arg_0( atmp1110100);
if( check_sym( atmp11101000 , ef54sym)) {
{
aterm * atmp111010000= arg_0( atmp11101000);
if( check_sym( atmp111010000 , lf2sym)) {
{
aterm * atmp1110100000= arg_0( atmp111010000);
{
aterm * atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
aterm * atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
aterm * atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
aterm * atmp111011000= arg_0( atmp11101100);
{
aterm * atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef93sym)) {
{
aterm * atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef81sym)) {
{
aterm * atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef12sym)) {
{
aterm * atmp111011101= arg_1( atmp11101110);
if( check_sym( atmp111011101 , ef82sym)) {
{
aterm * atmp1110111010= arg_0( atmp111011101);
if( check_sym( atmp1110111010 , ef77sym)) {
{
aterm * atmp11101110100= arg_0( atmp1110111010);
if( check_sym( atmp11101110100 , ef78sym)) {
{
aterm * atmp111011101000= arg_0( atmp11101110100);
if( check_sym( atmp111011101000 , ef98sym)) {
{
aterm * atmp1110111010000= arg_0( atmp111011101000);
{
aterm * atmp11101111= arg_1( atmp1110111);
if( check_sym( atmp11101111 , ef93sym)) {
{
aterm * atmp111011110= arg_0( atmp11101111);
if( check_sym( atmp111011110 , ef77sym)) {
{
aterm * atmp1110111100= arg_0( atmp111011110);
if( check_sym( atmp1110111100 , ef78sym)) {
{
aterm * atmp11101111000= arg_0( atmp1110111100);
{
aterm * atmp111011111= arg_1( atmp11101111);
if( check_sym( atmp111011111 , ef93sym)) {
{
aterm * atmp1110111110= arg_0( atmp111011111);
if( check_sym( atmp1110111110 , ef77sym)) {
{
aterm * atmp11101111100= arg_0( atmp1110111110);
if( check_sym( atmp11101111100 , ef78sym)) {
{
aterm * atmp111011111000= arg_0( atmp11101111100);
{
aterm * atmp1110111111= arg_1( atmp111011111);
if( check_sym( atmp1110111111 , ef93sym)) {
{
aterm * atmp11101111110= arg_0( atmp1110111111);
if( check_sym( atmp11101111110 , ef77sym)) {
{
aterm * atmp111011111100= arg_0( atmp11101111110);
if( check_sym( atmp111011111100 , ef78sym)) {
{
aterm * atmp1110111111000= arg_0( atmp111011111100);
{
aterm * atmp11101111111= arg_1( atmp1110111111);
if( check_sym( atmp11101111111 , ef93sym)) {
{
aterm * atmp111011111110= arg_0( atmp11101111111);
if( check_sym( atmp111011111110 , ef77sym)) {
{
aterm * atmp1110111111100= arg_0( atmp111011111110);
if( check_sym( atmp1110111111100 , ef78sym)) {
{
aterm * atmp11101111111000= arg_0( atmp1110111111100);
if( check_sym( atmp11101111111000 , ef54sym)) {
{
aterm * atmp111011111110000= arg_0( atmp11101111111000);
if( check_sym( atmp111011111110000 , lf2sym)) {
{
aterm * atmp1110111111100000= arg_0( atmp111011111110000);
{
aterm * atmp111011111111= arg_1( atmp11101111111);
if( check_sym( atmp111011111111 , ef93sym)) {
{
aterm * atmp1110111111110= arg_0( atmp111011111111);
if( check_sym( atmp1110111111110 , ef77sym)) {
{
aterm * atmp11101111111100= arg_0( atmp1110111111110);
if( check_sym( atmp11101111111100 , ef78sym)) {
{
aterm * atmp111011111111000= arg_0( atmp11101111111100);
{
aterm * atmp1110111111111= arg_1( atmp111011111111);
if( check_sym( atmp1110111111111 , ef82sym)) {
{
aterm * atmp11101111111110= arg_0( atmp1110111111111);
if( check_sym( atmp11101111111110 , ef77sym)) {
{
aterm * atmp111011111111100= arg_0( atmp11101111111110);
if( check_sym( atmp111011111111100 , ef78sym)) {
{
aterm * atmp1110111111111000= arg_0( atmp111011111111100);
if( check_sym( atmp1110111111111000 , ef54sym)) {
{
aterm * atmp11101111111110000= arg_0( atmp1110111111111000);
if( check_sym( atmp11101111111110000 , lf2sym)) {
{
aterm * atmp111011111111100000= arg_0( atmp11101111111110000);
if( m_not_empty_list( atmp1110100000)) {
t_protect( atmp1110100000);
if( term_equal( list_head( atmp1110100000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp1110100000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( m_not_empty_list( atmp1110111111100000)) {
t_protect( atmp1110111111100000);
if( term_equal( list_head( atmp1110111111100000) , make_char( 34))) {
tmp[ 2]= m_list_tail( atmp1110111111100000);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 125))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 34))) {
if( m_not_empty_list( atmp111011111111100000)) {
t_protect( atmp111011111111100000);
if( term_equal( list_head( atmp111011111111100000) , make_char( 34))) {
tmp[ 4]= m_list_tail( atmp111011111111100000);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 43))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_is_single_element( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 34))) {
if( m_term_equal( atmp000 , atmp1110111010000)) {
if( m_term_equal( atmp010 , atmp111011111000)) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef79)( );
}
}
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
}
}
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
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef53sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( arg1 , ef85sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef87sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef82sym)) {
{
aterm * atmp1000= arg_0( atmp100);
t_protect( atmp00);
t_protect( atmp1000);
t_unprotect( arg0);
t_unprotect( arg1);
return lf_AUX_ParseTrees7_1( atmp00 , atmp1000);
}
}
}
}
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
tmp[ 0]= ( * ef96)( atmp10);
if( check_sym( tmp[ 0] , ef87sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef93sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
if( check_sym( tmp[ 2] , ef81sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
tmp[ 5]= arg_1( tmp[ 2]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , ( * ef4)( ))) {
if( check_sym( tmp[ 5] , ef82sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , ef77sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , ef78sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 3] , ef93sym)) {
tmp[ 9]= arg_0( tmp[ 3]);
tmp[ 10]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 9] , ef81sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
t_protect( tmp[ 11]);
if( term_equal( tmp[ 11] , ( * ef14)( ))) {
if( check_sym( tmp[ 12] , ef82sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , ef77sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , ef78sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 10] , ef93sym)) {
tmp[ 16]= arg_0( tmp[ 10]);
tmp[ 17]= arg_1( tmp[ 10]);
if( check_sym( tmp[ 16] , ef81sym)) {
tmp[ 18]= arg_0( tmp[ 16]);
tmp[ 19]= arg_1( tmp[ 16]);
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , ( * ef4)( ))) {
if( check_sym( tmp[ 19] , ef82sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , ef77sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 21] , ef78sym)) {
tmp[ 22]= arg_0( tmp[ 21]);
if( m_term_equal( atmp010 , tmp[ 15])) {
t_protect( atmp00);
t_protect( atmp10);
t_protect( atmp00);
t_protect( atmp010);
t_protect( tmp[ 17]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef90)( lf_AUX_ParseTrees7_1( atmp00 , ( * ef91)( atmp10)) , lf_AUX_ParseTrees7_1( ( * ef94)( atmp00 , ( * ef53)( atmp010)) , ( * ef85)( ( * ef87)( tmp[ 17]))));
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
{
aterm * atmp01= arg_1( arg0);
if( check_sym( arg1 , ef85sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef89)( );
}
}
}
}
}
}
}
}
if( check_sym( arg1 , ef83sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
t_protect( atmp11);
t_unprotect( arg1);
return lf_AUX_ParseTrees7_1( arg0 , atmp11);
}
}
}
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef89)( );
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

