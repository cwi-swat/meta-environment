#include "support.h"
static Symbol lf_AUX_ParseTrees8_1sym;
static ATerm lf_AUX_ParseTrees8_1( ATerm arg1 , ATerm arg2);
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef19sym;
static funcptr ef19;
static Symbol ef20sym;
static funcptr ef20;
static Symbol ef21sym;
static funcptr ef21;
static Symbol ef22sym;
static funcptr ef22;
static Symbol ef23sym;
static funcptr ef23;
static Symbol ef24sym;
static funcptr ef24;
static Symbol ef25sym;
static funcptr ef25;
static Symbol ef26sym;
static funcptr ef26;
static Symbol ef27sym;
static funcptr ef27;
static Symbol ef28sym;
static funcptr ef28;
static Symbol ef29sym;
static funcptr ef29;
static Symbol ef30sym;
static funcptr ef30;
static Symbol ef31sym;
static funcptr ef31;
static Symbol ef32sym;
static funcptr ef32;
static Symbol ef33sym;
static funcptr ef33;
static Symbol ef34sym;
static funcptr ef34;
static Symbol ef35sym;
static funcptr ef35;
static Symbol ef36sym;
static funcptr ef36;
static Symbol ef37sym;
static funcptr ef37;
static Symbol ef38sym;
static funcptr ef38;
static Symbol ef39sym;
static funcptr ef39;
static Symbol ef40sym;
static funcptr ef40;
static Symbol ef41sym;
static funcptr ef41;
static Symbol ef42sym;
static funcptr ef42;
static Symbol ef43sym;
static funcptr ef43;
static Symbol ef44sym;
static funcptr ef44;
static Symbol ef45sym;
static funcptr ef45;
static Symbol ef46sym;
static funcptr ef46;
static Symbol ef47sym;
static funcptr ef47;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef50sym;
static funcptr ef50;
static Symbol ef51sym;
static funcptr ef51;
static Symbol ef52sym;
static funcptr ef52;
static Symbol ef56sym;
static funcptr ef56;
static Symbol ef55sym;
static funcptr ef55;
static Symbol ef58sym;
static funcptr ef58;
static Symbol ef59sym;
static funcptr ef59;
static Symbol ef60sym;
static funcptr ef60;
static Symbol ef57sym;
static funcptr ef57;
static Symbol ef61sym;
static funcptr ef61;
static Symbol ef62sym;
static funcptr ef62;
static Symbol ef63sym;
static funcptr ef63;
static Symbol ef64sym;
static funcptr ef64;
static Symbol ef65sym;
static funcptr ef65;
static Symbol ef66sym;
static funcptr ef66;
static Symbol ef67sym;
static funcptr ef67;
static Symbol ef68sym;
static funcptr ef68;
static Symbol ef69sym;
static funcptr ef69;
static Symbol ef70sym;
static funcptr ef70;
static Symbol ef71sym;
static funcptr ef71;
static Symbol ef72sym;
static funcptr ef72;
static Symbol ef73sym;
static funcptr ef73;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef74sym;
static funcptr ef74;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef75sym;
static funcptr ef75;
static Symbol ef76sym;
static funcptr ef76;
static Symbol ef80sym;
static funcptr ef80;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef83sym;
static funcptr ef83;
static Symbol ef92sym;
static funcptr ef92;
static Symbol ef86sym;
static funcptr ef86;
static Symbol ef90sym;
static funcptr ef90;
static Symbol ef91sym;
static funcptr ef91;
static Symbol ef96sym;
static funcptr ef96;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef85sym;
static funcptr ef85;
static Symbol ef87sym;
static funcptr ef87;
static Symbol ef84sym;
static funcptr ef84;
static Symbol ef88sym;
static funcptr ef88;
static Symbol ef49sym;
static funcptr ef49;
static Symbol ef94sym;
static funcptr ef94;
static Symbol ef95sym;
static funcptr ef95;
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef53sym;
static funcptr ef53;
static Symbol ef97sym;
static funcptr ef97;
static Symbol ef48sym;
static funcptr ef48;
static Symbol ef81sym;
static funcptr ef81;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef98sym;
static funcptr ef98;
static Symbol ef93sym;
static funcptr ef93;
static Symbol ef82sym;
static funcptr ef82;
static Symbol ef77sym;
static funcptr ef77;
static Symbol ef78sym;
static funcptr ef78;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef54sym;
static funcptr ef54;
static Symbol ef79sym;
static funcptr ef79;
static Symbol ef89sym;
static funcptr ef89;
void register_AUX_ParseTrees8( ) {
lf_AUX_ParseTrees8_1sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees8_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees8_1 , lf_AUX_ParseTrees8_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_ParseTrees8( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"QLiteral\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"QLiteral\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Separator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Separator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"char-class\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"char-class\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef19= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef20= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef22= lookup_func( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef24= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"aprod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"aprod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef25= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef26= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef27= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef28= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef29= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"asfix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"asfix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef30= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef31= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef32= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Section\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef32sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Section\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef33sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"exports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef34sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"exports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"hiddens\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef35sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"hiddens\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef36= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef36sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sorts\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef37sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"sorts\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lexical-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef38sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lexical-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"context-free-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef39sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"context-free-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef40= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef40sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef41= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"variables\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef41sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"variables\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef42= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef42sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef43= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef43sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef44= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef44sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef45= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attribute\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef45sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Attribute\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef46= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attr\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef46sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"attr\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef47= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef47sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef48= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef48sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef49= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef49sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef50= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"neg\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef50sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"neg\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef51= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef51sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef52= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef52sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef53= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef53sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef54= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef54sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef55= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ProdSkel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef55sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ProdSkel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef56= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod-skel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef56sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prod-skel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef57= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef57sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef58= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef58sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef59= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"agroup\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef59sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"agroup\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef60= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Priority\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef60sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Priority\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef61= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"decr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef61sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"decr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef62= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"incr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef62sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"incr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef63= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prio-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef63sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"prio-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef64= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef64sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef65= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef65sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"no-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef66= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef66sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef67= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef67sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef68= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef68sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef69= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CondEquation\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef69sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"CondEquation\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef70= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef70sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef71= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef71sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef72= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef72sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef73= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ExtAsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef73sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ExtAsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef74= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef74sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef75= lookup_func( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef75sym= lookup_sym( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef76= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef76sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef77= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef77sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef78= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef78sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef79= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef79sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef80= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef80sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef81= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef81sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef82= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef82sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef83= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef83sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef84= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef84sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef85= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef85sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef86= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef86sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef87= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef87sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef88= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef88sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef89= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef89sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef90= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef90sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef91= lookup_func( ATreadFromString( "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef91sym= lookup_sym( ATreadFromString( "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef92= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef92sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef93= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef93sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef94= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef94sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef95= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef95sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef96= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef96sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef97= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef97sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef98= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef98sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
static ATerm constant5= NULL;
static ATerm constant6= NULL;
static ATerm constant7= NULL;
static ATerm constant8= NULL;
static ATerm constant9= NULL;
static ATerm constant10= NULL;
static ATerm constant11= NULL;
static ATerm constant12= NULL;
static ATerm constant13= NULL;
static ATerm constant14= NULL;
static ATerm constant15= NULL;
static ATerm constant16= NULL;
static ATerm constant17= NULL;
static ATerm constant18= NULL;
static ATerm constant19= NULL;
static ATerm constant20= NULL;
static ATerm constant21= NULL;
static ATerm constant22= NULL;
static ATerm constant23= NULL;
static ATerm constant24= NULL;
static ATerm constant25= NULL;
static ATerm constant26= NULL;
static ATerm constant27= NULL;
static ATerm constant28= NULL;
static ATerm constant29= NULL;
static ATerm constant30= NULL;
static ATerm constant31= NULL;
static ATerm constant32= NULL;
static ATerm constant33= NULL;
static ATerm constant34= NULL;
static ATerm constant35= NULL;
static ATerm constant36= NULL;
static ATerm constant37= NULL;
static ATerm constant38= NULL;
static ATerm constant39= NULL;
static ATerm constant40= NULL;
static ATerm constant41= NULL;
static ATerm constant42= NULL;
static ATerm constant43= NULL;
static ATerm constant44= NULL;
static ATerm constant45= NULL;
static ATerm constant46= NULL;
static ATerm constant47= NULL;
static ATerm constant48= NULL;
static ATerm constant49= NULL;
static ATerm constant50= NULL;
static ATerm constant51= NULL;
static ATerm constant52= NULL;
static ATerm constant53= NULL;
static ATerm constant54= NULL;
static ATerm constant55= NULL;
static ATerm constant56= NULL;
static ATerm constant57= NULL;
static ATerm constant58= NULL;
static ATerm constant59= NULL;
void init_AUX_ParseTrees8( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
ATprotect( & constant5);
ATprotect( & constant6);
ATprotect( & constant7);
ATprotect( & constant8);
ATprotect( & constant9);
ATprotect( & constant10);
ATprotect( & constant11);
ATprotect( & constant12);
ATprotect( & constant13);
ATprotect( & constant14);
ATprotect( & constant15);
ATprotect( & constant16);
ATprotect( & constant17);
ATprotect( & constant18);
ATprotect( & constant19);
ATprotect( & constant20);
ATprotect( & constant21);
ATprotect( & constant22);
ATprotect( & constant23);
ATprotect( & constant24);
ATprotect( & constant25);
ATprotect( & constant26);
ATprotect( & constant27);
ATprotect( & constant28);
ATprotect( & constant29);
ATprotect( & constant30);
ATprotect( & constant31);
ATprotect( & constant32);
ATprotect( & constant33);
ATprotect( & constant34);
ATprotect( & constant35);
ATprotect( & constant36);
ATprotect( & constant37);
ATprotect( & constant38);
ATprotect( & constant39);
ATprotect( & constant40);
ATprotect( & constant41);
ATprotect( & constant42);
ATprotect( & constant43);
ATprotect( & constant44);
ATprotect( & constant45);
ATprotect( & constant46);
ATprotect( & constant47);
ATprotect( & constant48);
ATprotect( & constant49);
ATprotect( & constant50);
ATprotect( & constant51);
ATprotect( & constant52);
ATprotect( & constant53);
ATprotect( & constant54);
ATprotect( & constant55);
ATprotect( & constant56);
ATprotect( & constant57);
ATprotect( & constant58);
ATprotect( & constant59);
}
ATerm lf_AUX_ParseTrees8_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[23];
PROF( prof_lf_AUX_ParseTrees8_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
return ( * ef3)( ( constant0? constant0: ( constant0= ( * ef4)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef5sym)) {
return ( * ef3)( ( constant1? constant1: ( constant1= ( * ef6)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef7sym)) {
return ( * ef3)( ( constant2? constant2: ( constant2= ( * ef8)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef9sym)) {
return ( * ef3)( ( constant3? constant3: ( constant3= ( * ef10)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef11sym)) {
return ( * ef3)( ( constant4? constant4: ( constant4= ( * ef12)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef13sym)) {
return ( * ef3)( ( constant5? constant5: ( constant5= ( * ef14)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef15sym)) {
return ( * ef3)( ( constant6? constant6: ( constant6= ( * ef16)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef17sym)) {
return ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees8_1( ( constant7? constant7: ( constant7= ( * ef1)( ( * ef5)( )))) , arg1) , ( * ef3)( ( constant8? constant8: ( constant8= ( * ef19)( ))) , arg1)) , ( * ef3)( ( constant9? constant9: ( constant9= ( * ef20)( ))) , arg1)) , ( * ef3)( ( constant10? constant10: ( constant10= ( * ef21)( ))) , arg1)) , ( * ef3)( ( constant11? constant11: ( constant11= ( * ef22)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef23sym)) {
return ( * ef18)( ( * ef3)( ( constant12? constant12: ( constant12= ( * ef24)( ))) , arg1) , ( * ef3)( ( constant13? constant13: ( constant13= ( * ef25)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef26sym)) {
return ( * ef3)( ( constant14? constant14: ( constant14= ( * ef27)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef28sym)) {
return ( * ef3)( ( constant15? constant15: ( constant15= ( * ef29)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef30sym)) {
return ( * ef3)( ( constant16? constant16: ( constant16= ( * ef31)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef32sym)) {
return ( * ef18)( ( * ef18)( ( * ef3)( ( constant17? constant17: ( constant17= ( * ef33)( ))) , arg1) , ( * ef3)( ( constant18? constant18: ( constant18= ( * ef34)( ))) , arg1)) , ( * ef3)( ( constant19? constant19: ( constant19= ( * ef35)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef36sym)) {
return ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef3)( ( constant20? constant20: ( constant20= ( * ef37)( ))) , arg1) , ( * ef3)( ( constant21? constant21: ( constant21= ( * ef38)( ))) , arg1)) , ( * ef3)( ( constant22? constant22: ( constant22= ( * ef39)( ))) , arg1)) , ( * ef3)( ( constant23? constant23: ( constant23= ( * ef40)( ))) , arg1)) , ( * ef3)( ( constant24? constant24: ( constant24= ( * ef41)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef42sym)) {
return ( * ef18)( ( * ef3)( ( constant25? constant25: ( constant25= ( * ef43)( ))) , arg1) , ( * ef3)( ( constant26? constant26: ( constant26= ( * ef44)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef45sym)) {
return ( * ef18)( lf_AUX_ParseTrees8_1( ( constant7? constant7: ( constant7= ( * ef1)( ( * ef5)( )))) , arg1) , ( * ef3)( ( constant27? constant27: ( constant27= ( * ef46)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef47sym)) {
return ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees8_1( ( constant7? constant7: ( constant7= ( * ef1)( ( * ef5)( )))) , arg1) , lf_AUX_ParseTrees8_1( ( constant28? constant28: ( constant28= ( * ef1)( ( * ef7)( )))) , arg1)) , lf_AUX_ParseTrees8_1( ( constant29? constant29: ( constant29= ( * ef1)( ( * ef11)( )))) , arg1)) , lf_AUX_ParseTrees8_1( ( constant30? constant30: ( constant30= ( * ef1)( ( * ef15)( )))) , arg1)) , ( * ef3)( ( constant31? constant31: ( constant31= ( * ef48)( ))) , arg1)) , ( * ef3)( ( constant32? constant32: ( constant32= ( * ef49)( ))) , arg1)) , ( * ef3)( ( constant33? constant33: ( constant33= ( * ef50)( ))) , arg1)) , ( * ef3)( ( constant34? constant34: ( constant34= ( * ef51)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef52sym)) {
return ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees8_1( ( constant35? constant35: ( constant35= ( * ef53)( ( * ef54)( lf2( (ATerm) ATmakeList( 6 , char_table[ 34] , char_table[ 108] , char_table[ 101] , char_table[ 102] , char_table[ 116] , char_table[ 34])))))) , arg1) , lf_AUX_ParseTrees8_1( ( constant36? constant36: ( constant36= ( * ef53)( ( * ef54)( lf2( (ATerm) ATmakeList( 7 , char_table[ 34] , char_table[ 114] , char_table[ 105] , char_table[ 103] , char_table[ 104] , char_table[ 116] , char_table[ 34])))))) , arg1)) , lf_AUX_ParseTrees8_1( ( constant37? constant37: ( constant37= ( * ef53)( ( * ef54)( lf2( (ATerm) ATmakeList( 11 , char_table[ 34] , char_table[ 110] , char_table[ 111] , char_table[ 110] , char_table[ 45] , char_table[ 97] , char_table[ 115] , char_table[ 115] , char_table[ 111] , char_table[ 99] , char_table[ 34])))))) , arg1)) , lf_AUX_ParseTrees8_1( ( constant38? constant38: ( constant38= ( * ef53)( ( * ef54)( lf2( (ATerm) ATmakeList( 7 , char_table[ 34] , char_table[ 97] , char_table[ 115] , char_table[ 115] , char_table[ 111] , char_table[ 99] , char_table[ 34])))))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef55sym)) {
return ( * ef3)( ( constant39? constant39: ( constant39= ( * ef56)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef57sym)) {
return ( * ef18)( ( * ef18)( lf_AUX_ParseTrees8_1( ( constant40? constant40: ( constant40= ( * ef1)( ( * ef55)( )))) , arg1) , ( * ef3)( ( constant41? constant41: ( constant41= ( * ef58)( ))) , arg1)) , ( * ef3)( ( constant42? constant42: ( constant42= ( * ef59)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef60sym)) {
return ( * ef18)( ( * ef18)( ( * ef18)( lf_AUX_ParseTrees8_1( ( constant43? constant43: ( constant43= ( * ef1)( ( * ef57)( )))) , arg1) , ( * ef3)( ( constant44? constant44: ( constant44= ( * ef61)( ))) , arg1)) , ( * ef3)( ( constant45? constant45: ( constant45= ( * ef62)( ))) , arg1)) , ( * ef3)( ( constant46? constant46: ( constant46= ( * ef63)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef64sym)) {
return ( * ef18)( ( * ef3)( ( constant47? constant47: ( constant47= ( * ef65)( ))) , arg1) , ( * ef3)( ( constant48? constant48: ( constant48= ( * ef66)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef67sym)) {
return ( * ef3)( ( constant49? constant49: ( constant49= ( * ef68)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef69sym)) {
return ( * ef18)( ( * ef18)( ( * ef3)( ( constant50? constant50: ( constant50= ( * ef70)( ))) , arg1) , ( * ef3)( ( constant51? constant51: ( constant51= ( * ef71)( ))) , arg1)) , ( * ef3)( ( constant52? constant52: ( constant52= ( * ef72)( ))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef73sym)) {
return ( * ef18)( ( * ef18)( lf_AUX_ParseTrees8_1( ( constant53? constant53: ( constant53= ( * ef1)( ( * ef17)( )))) , arg1) , lf_AUX_ParseTrees8_1( ( constant54? constant54: ( constant54= ( * ef1)( ( * ef2)( )))) , arg1)) , lf_AUX_ParseTrees8_1( ( constant55? constant55: ( constant55= ( * ef1)( ( * ef13)( )))) , arg1));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef74sym)) {
return ( * ef3)( ( constant56? constant56: ( constant56= ( * ef75)( ))) , arg1);
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef76sym)) {
if( check_sym( arg1 , ef77sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef78sym)) {
{
ATerm atmp100= arg_0( atmp10);
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef80sym)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef81sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
{
ATerm atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
ATerm atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef77sym)) {
{
ATerm atmp11100= arg_0( atmp1110);
if( term_equal( atmp00 , atmp11100)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef81sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef6sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef82sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
if( term_equal( atmp00 , atmp11000)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
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
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef78sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( term_equal( atmp00 , atmp100)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
}
}
if( check_sym( arg0 , ef84sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef81sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
{
ATerm atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
ATerm atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
ATerm atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef49sym)) {
{
ATerm atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
ATerm atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef81sym)) {
{
ATerm atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef12sym)) {
{
ATerm atmp1110101= arg_1( atmp111010);
if( check_sym( atmp1110101 , ef82sym)) {
{
ATerm atmp11101010= arg_0( atmp1110101);
if( check_sym( atmp11101010 , ef77sym)) {
{
ATerm atmp111010100= arg_0( atmp11101010);
if( check_sym( atmp111010100 , ef78sym)) {
{
ATerm atmp1110101000= arg_0( atmp111010100);
if( check_sym( atmp1110101000 , ef98sym)) {
{
ATerm atmp11101010000= arg_0( atmp1110101000);
{
ATerm atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
ATerm atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
ATerm atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
ATerm atmp111011000= arg_0( atmp11101100);
{
ATerm atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef82sym)) {
{
ATerm atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef77sym)) {
{
ATerm atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef78sym)) {
{
ATerm atmp1110111000= arg_0( atmp111011100);
if( check_sym( atmp1110111000 , ef54sym)) {
{
ATerm atmp11101110000= arg_0( atmp1110111000);
if( check_sym( atmp11101110000 , lf2sym)) {
{
ATerm atmp111011100000= arg_0( atmp11101110000);
if( not_empty_list( atmp111011100000)) {
if( term_equal( list_head( atmp111011100000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp111011100000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 42))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( is_single_element( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( term_equal( atmp000 , atmp11101010000)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef85sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef87sym)) {
{
ATerm atmp100= arg_0( atmp10);
return lf_AUX_ParseTrees8_1( ( * ef88)( atmp00) , arg1);
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
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef81sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
{
ATerm atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
ATerm atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
ATerm atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef49sym)) {
{
ATerm atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
ATerm atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef81sym)) {
{
ATerm atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef12sym)) {
{
ATerm atmp1110101= arg_1( atmp111010);
if( check_sym( atmp1110101 , ef82sym)) {
{
ATerm atmp11101010= arg_0( atmp1110101);
if( check_sym( atmp11101010 , ef77sym)) {
{
ATerm atmp111010100= arg_0( atmp11101010);
if( check_sym( atmp111010100 , ef78sym)) {
{
ATerm atmp1110101000= arg_0( atmp111010100);
if( check_sym( atmp1110101000 , ef98sym)) {
{
ATerm atmp11101010000= arg_0( atmp1110101000);
{
ATerm atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
ATerm atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
ATerm atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
ATerm atmp111011000= arg_0( atmp11101100);
{
ATerm atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef82sym)) {
{
ATerm atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef77sym)) {
{
ATerm atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef78sym)) {
{
ATerm atmp1110111000= arg_0( atmp111011100);
if( check_sym( atmp1110111000 , ef54sym)) {
{
ATerm atmp11101110000= arg_0( atmp1110111000);
if( check_sym( atmp11101110000 , lf2sym)) {
{
ATerm atmp111011100000= arg_0( atmp11101110000);
if( not_empty_list( atmp111011100000)) {
if( term_equal( list_head( atmp111011100000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp111011100000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 43))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( is_single_element( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( term_equal( atmp000 , atmp11101010000)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef85sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
return ( constant58? constant58: ( constant58= ( * ef89)( )));
}
{
ATerm atmp10= arg_0( arg1);
if( term_equal( ( * ef92)( atmp10) , ( constant59? constant59: ( constant59= ( * ef86)( ))))) {
return lf_AUX_ParseTrees8_1( atmp00 , ( * ef91)( atmp10));
}
tmp[ 0]= ( * ef92)( atmp10);
if( check_sym( tmp[ 0] , ef87sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef93sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
if( check_sym( tmp[ 2] , ef81sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
tmp[ 5]= arg_1( tmp[ 2]);
if( term_equal( tmp[ 4] , ( constant0? constant0: ( constant0= ( * ef4)( ))))) {
if( check_sym( tmp[ 5] , ef82sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , ef77sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , ef78sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
return ( * ef90)( lf_AUX_ParseTrees8_1( atmp00 , ( * ef91)( atmp10)) , lf_AUX_ParseTrees8_1( ( * ef84)( atmp00) , ( * ef85)( ( * ef87)( tmp[ 3]))));
}
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef94sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
ATerm atmp000= arg_0( atmp00);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef53sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( arg1 , ef81sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
{
ATerm atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
ATerm atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
ATerm atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef48sym)) {
{
ATerm atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
ATerm atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef77sym)) {
{
ATerm atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef78sym)) {
{
ATerm atmp11101000= arg_0( atmp1110100);
if( check_sym( atmp11101000 , ef54sym)) {
{
ATerm atmp111010000= arg_0( atmp11101000);
if( check_sym( atmp111010000 , lf2sym)) {
{
ATerm atmp1110100000= arg_0( atmp111010000);
{
ATerm atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
ATerm atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
ATerm atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
ATerm atmp111011000= arg_0( atmp11101100);
{
ATerm atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef93sym)) {
{
ATerm atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef81sym)) {
{
ATerm atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef12sym)) {
{
ATerm atmp111011101= arg_1( atmp11101110);
if( check_sym( atmp111011101 , ef82sym)) {
{
ATerm atmp1110111010= arg_0( atmp111011101);
if( check_sym( atmp1110111010 , ef77sym)) {
{
ATerm atmp11101110100= arg_0( atmp1110111010);
if( check_sym( atmp11101110100 , ef78sym)) {
{
ATerm atmp111011101000= arg_0( atmp11101110100);
if( check_sym( atmp111011101000 , ef98sym)) {
{
ATerm atmp1110111010000= arg_0( atmp111011101000);
{
ATerm atmp11101111= arg_1( atmp1110111);
if( check_sym( atmp11101111 , ef93sym)) {
{
ATerm atmp111011110= arg_0( atmp11101111);
if( check_sym( atmp111011110 , ef77sym)) {
{
ATerm atmp1110111100= arg_0( atmp111011110);
if( check_sym( atmp1110111100 , ef78sym)) {
{
ATerm atmp11101111000= arg_0( atmp1110111100);
{
ATerm atmp111011111= arg_1( atmp11101111);
if( check_sym( atmp111011111 , ef93sym)) {
{
ATerm atmp1110111110= arg_0( atmp111011111);
if( check_sym( atmp1110111110 , ef77sym)) {
{
ATerm atmp11101111100= arg_0( atmp1110111110);
if( check_sym( atmp11101111100 , ef78sym)) {
{
ATerm atmp111011111000= arg_0( atmp11101111100);
{
ATerm atmp1110111111= arg_1( atmp111011111);
if( check_sym( atmp1110111111 , ef93sym)) {
{
ATerm atmp11101111110= arg_0( atmp1110111111);
if( check_sym( atmp11101111110 , ef77sym)) {
{
ATerm atmp111011111100= arg_0( atmp11101111110);
if( check_sym( atmp111011111100 , ef78sym)) {
{
ATerm atmp1110111111000= arg_0( atmp111011111100);
{
ATerm atmp11101111111= arg_1( atmp1110111111);
if( check_sym( atmp11101111111 , ef93sym)) {
{
ATerm atmp111011111110= arg_0( atmp11101111111);
if( check_sym( atmp111011111110 , ef77sym)) {
{
ATerm atmp1110111111100= arg_0( atmp111011111110);
if( check_sym( atmp1110111111100 , ef78sym)) {
{
ATerm atmp11101111111000= arg_0( atmp1110111111100);
if( check_sym( atmp11101111111000 , ef54sym)) {
{
ATerm atmp111011111110000= arg_0( atmp11101111111000);
if( check_sym( atmp111011111110000 , lf2sym)) {
{
ATerm atmp1110111111100000= arg_0( atmp111011111110000);
{
ATerm atmp111011111111= arg_1( atmp11101111111);
if( check_sym( atmp111011111111 , ef93sym)) {
{
ATerm atmp1110111111110= arg_0( atmp111011111111);
if( check_sym( atmp1110111111110 , ef77sym)) {
{
ATerm atmp11101111111100= arg_0( atmp1110111111110);
if( check_sym( atmp11101111111100 , ef78sym)) {
{
ATerm atmp111011111111000= arg_0( atmp11101111111100);
{
ATerm atmp1110111111111= arg_1( atmp111011111111);
if( check_sym( atmp1110111111111 , ef82sym)) {
{
ATerm atmp11101111111110= arg_0( atmp1110111111111);
if( check_sym( atmp11101111111110 , ef77sym)) {
{
ATerm atmp111011111111100= arg_0( atmp11101111111110);
if( check_sym( atmp111011111111100 , ef78sym)) {
{
ATerm atmp1110111111111000= arg_0( atmp111011111111100);
if( check_sym( atmp1110111111111000 , ef54sym)) {
{
ATerm atmp11101111111110000= arg_0( atmp1110111111111000);
if( check_sym( atmp11101111111110000 , lf2sym)) {
{
ATerm atmp111011111111100000= arg_0( atmp11101111111110000);
if( not_empty_list( atmp1110100000)) {
if( term_equal( list_head( atmp1110100000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp1110100000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( is_single_element( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( not_empty_list( atmp1110111111100000)) {
if( term_equal( list_head( atmp1110111111100000) , make_char( 34))) {
tmp[ 2]= list_tail( atmp1110111111100000);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 125))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( is_single_element( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 34))) {
if( not_empty_list( atmp111011111111100000)) {
if( term_equal( list_head( atmp111011111111100000) , make_char( 34))) {
tmp[ 4]= list_tail( atmp111011111111100000);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 42))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( is_single_element( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 34))) {
if( term_equal( atmp000 , atmp1110111010000)) {
if( term_equal( atmp010 , atmp111011111000)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( arg1 , ef85sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef87sym)) {
{
ATerm atmp100= arg_0( atmp10);
return lf_AUX_ParseTrees8_1( ( * ef95)( atmp00 , atmp01) , arg1);
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
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef1sym)) {
{
ATerm atmp000= arg_0( atmp00);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef53sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( arg1 , ef81sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef97sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef93sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef77sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef78sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
{
ATerm atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef82sym)) {
{
ATerm atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , ef81sym)) {
{
ATerm atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , ef48sym)) {
{
ATerm atmp11101= arg_1( atmp1110);
if( check_sym( atmp11101 , ef93sym)) {
{
ATerm atmp111010= arg_0( atmp11101);
if( check_sym( atmp111010 , ef77sym)) {
{
ATerm atmp1110100= arg_0( atmp111010);
if( check_sym( atmp1110100 , ef78sym)) {
{
ATerm atmp11101000= arg_0( atmp1110100);
if( check_sym( atmp11101000 , ef54sym)) {
{
ATerm atmp111010000= arg_0( atmp11101000);
if( check_sym( atmp111010000 , lf2sym)) {
{
ATerm atmp1110100000= arg_0( atmp111010000);
{
ATerm atmp111011= arg_1( atmp11101);
if( check_sym( atmp111011 , ef93sym)) {
{
ATerm atmp1110110= arg_0( atmp111011);
if( check_sym( atmp1110110 , ef77sym)) {
{
ATerm atmp11101100= arg_0( atmp1110110);
if( check_sym( atmp11101100 , ef78sym)) {
{
ATerm atmp111011000= arg_0( atmp11101100);
{
ATerm atmp1110111= arg_1( atmp111011);
if( check_sym( atmp1110111 , ef93sym)) {
{
ATerm atmp11101110= arg_0( atmp1110111);
if( check_sym( atmp11101110 , ef81sym)) {
{
ATerm atmp111011100= arg_0( atmp11101110);
if( check_sym( atmp111011100 , ef12sym)) {
{
ATerm atmp111011101= arg_1( atmp11101110);
if( check_sym( atmp111011101 , ef82sym)) {
{
ATerm atmp1110111010= arg_0( atmp111011101);
if( check_sym( atmp1110111010 , ef77sym)) {
{
ATerm atmp11101110100= arg_0( atmp1110111010);
if( check_sym( atmp11101110100 , ef78sym)) {
{
ATerm atmp111011101000= arg_0( atmp11101110100);
if( check_sym( atmp111011101000 , ef98sym)) {
{
ATerm atmp1110111010000= arg_0( atmp111011101000);
{
ATerm atmp11101111= arg_1( atmp1110111);
if( check_sym( atmp11101111 , ef93sym)) {
{
ATerm atmp111011110= arg_0( atmp11101111);
if( check_sym( atmp111011110 , ef77sym)) {
{
ATerm atmp1110111100= arg_0( atmp111011110);
if( check_sym( atmp1110111100 , ef78sym)) {
{
ATerm atmp11101111000= arg_0( atmp1110111100);
{
ATerm atmp111011111= arg_1( atmp11101111);
if( check_sym( atmp111011111 , ef93sym)) {
{
ATerm atmp1110111110= arg_0( atmp111011111);
if( check_sym( atmp1110111110 , ef77sym)) {
{
ATerm atmp11101111100= arg_0( atmp1110111110);
if( check_sym( atmp11101111100 , ef78sym)) {
{
ATerm atmp111011111000= arg_0( atmp11101111100);
{
ATerm atmp1110111111= arg_1( atmp111011111);
if( check_sym( atmp1110111111 , ef93sym)) {
{
ATerm atmp11101111110= arg_0( atmp1110111111);
if( check_sym( atmp11101111110 , ef77sym)) {
{
ATerm atmp111011111100= arg_0( atmp11101111110);
if( check_sym( atmp111011111100 , ef78sym)) {
{
ATerm atmp1110111111000= arg_0( atmp111011111100);
{
ATerm atmp11101111111= arg_1( atmp1110111111);
if( check_sym( atmp11101111111 , ef93sym)) {
{
ATerm atmp111011111110= arg_0( atmp11101111111);
if( check_sym( atmp111011111110 , ef77sym)) {
{
ATerm atmp1110111111100= arg_0( atmp111011111110);
if( check_sym( atmp1110111111100 , ef78sym)) {
{
ATerm atmp11101111111000= arg_0( atmp1110111111100);
if( check_sym( atmp11101111111000 , ef54sym)) {
{
ATerm atmp111011111110000= arg_0( atmp11101111111000);
if( check_sym( atmp111011111110000 , lf2sym)) {
{
ATerm atmp1110111111100000= arg_0( atmp111011111110000);
{
ATerm atmp111011111111= arg_1( atmp11101111111);
if( check_sym( atmp111011111111 , ef93sym)) {
{
ATerm atmp1110111111110= arg_0( atmp111011111111);
if( check_sym( atmp1110111111110 , ef77sym)) {
{
ATerm atmp11101111111100= arg_0( atmp1110111111110);
if( check_sym( atmp11101111111100 , ef78sym)) {
{
ATerm atmp111011111111000= arg_0( atmp11101111111100);
{
ATerm atmp1110111111111= arg_1( atmp111011111111);
if( check_sym( atmp1110111111111 , ef82sym)) {
{
ATerm atmp11101111111110= arg_0( atmp1110111111111);
if( check_sym( atmp11101111111110 , ef77sym)) {
{
ATerm atmp111011111111100= arg_0( atmp11101111111110);
if( check_sym( atmp111011111111100 , ef78sym)) {
{
ATerm atmp1110111111111000= arg_0( atmp111011111111100);
if( check_sym( atmp1110111111111000 , ef54sym)) {
{
ATerm atmp11101111111110000= arg_0( atmp1110111111111000);
if( check_sym( atmp11101111111110000 , lf2sym)) {
{
ATerm atmp111011111111100000= arg_0( atmp11101111111110000);
if( not_empty_list( atmp1110100000)) {
if( term_equal( list_head( atmp1110100000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp1110100000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( is_single_element( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
if( not_empty_list( atmp1110111111100000)) {
if( term_equal( list_head( atmp1110111111100000) , make_char( 34))) {
tmp[ 2]= list_tail( atmp1110111111100000);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 125))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( is_single_element( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 34))) {
if( not_empty_list( atmp111011111111100000)) {
if( term_equal( list_head( atmp111011111111100000) , make_char( 34))) {
tmp[ 4]= list_tail( atmp111011111111100000);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 43))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( is_single_element( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 34))) {
if( term_equal( atmp000 , atmp1110111010000)) {
if( term_equal( atmp010 , atmp111011111000)) {
return ( constant57? constant57: ( constant57= ( * ef79)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef53sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( arg1 , ef85sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef87sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef82sym)) {
{
ATerm atmp1000= arg_0( atmp100);
return lf_AUX_ParseTrees8_1( atmp00 , atmp1000);
}
}
}
}
{
ATerm atmp10= arg_0( arg1);
tmp[ 0]= ( * ef96)( atmp10);
if( check_sym( tmp[ 0] , ef87sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef93sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
if( check_sym( tmp[ 2] , ef81sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
tmp[ 5]= arg_1( tmp[ 2]);
if( term_equal( tmp[ 4] , ( constant0? constant0: ( constant0= ( * ef4)( ))))) {
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
if( term_equal( tmp[ 11] , ( constant5? constant5: ( constant5= ( * ef14)( ))))) {
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
if( term_equal( tmp[ 18] , ( constant0? constant0: ( constant0= ( * ef4)( ))))) {
if( check_sym( tmp[ 19] , ef82sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , ef77sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 21] , ef78sym)) {
tmp[ 22]= arg_0( tmp[ 21]);
if( term_equal( atmp010 , tmp[ 15])) {
return ( * ef90)( lf_AUX_ParseTrees8_1( atmp00 , ( * ef91)( atmp10)) , lf_AUX_ParseTrees8_1( ( * ef94)( atmp00 , ( * ef53)( atmp010)) , ( * ef85)( ( * ef87)( tmp[ 17]))));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp01= arg_1( arg0);
if( check_sym( arg1 , ef85sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef86sym)) {
return ( constant58? constant58: ( constant58= ( * ef89)( )));
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
ATerm atmp10= arg_0( arg1);
{
ATerm atmp11= arg_1( arg1);
return lf_AUX_ParseTrees8_1( arg0 , atmp11);
}
}
}
return ( constant58? constant58: ( constant58= ( * ef89)( )));
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

