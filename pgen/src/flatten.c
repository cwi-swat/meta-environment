/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
#include "ksdf2table.h"


/*{{{  char *unquote_str2(char *s) */

char *unquote_str2(char *s)
{
  int len = strlen(s), i, j;
  static char *rs = NULL;
  static int   rs_size = 0;

  if (len > rs_size) {
    rs = (char *)realloc(rs, len);
    if(!rs) {
      ATerror("Run out of memory!\n");
    }
    rs_size = len;
  }                 

  if(s[0] == '\"' && s[len-1] == '\"') {
    j = 0;
    for(i=1; i<=len-2; i++) {
      if((s[i] == '\\' && s[i+1] == '"') ||
         (s[i] == '\\' && s[i+1] == '\\'))
        rs[j++] = s[++i];
      else if (s[i] == '\\' && s[i+1] == 'n') {
        rs[j++] = '\n';
        i++;
      }
      else
        rs[j++] = s[i];
    }
    rs[j] = '\0';
    return rs;
  }
  return s;
}

/*}}}  */
/*{{{  ATerm SDFflattenNumber(ATerm af) */


int make_integer(char *s);

ATerm SDFflattenNumber(ATerm af) 
{
  char *str;

  if(ATmatchTerm(af, pattern_asfix_lex, &str, NULL)) {
    return ATmake("<int>", atoi(str));
  }
  else {
    return af;
  }
}

/*}}}  */                
/*{{{  ATerm SDFflattenAFun(ATerm af) */

ATerm SDFflattenAFun(ATerm af)
{
  char *str;
  ATerm lit;

  if(AFTisLiteral2AFun(af)) {
    lit = AFTgetLiteralAFun(af);
    if(ATmatchTerm(lit, pattern_asfix_lex, &str, NULL))
      return ATmake("<str>", unquote_str2(str));
    else 
      return af;
  } 
  else 
    return af;
}

/*}}}  */
/*{{{  ATerm SDFflattenATerm(ATerm at) */

ATerm SDFflattenATerm(ATerm at)
{
  ATerm afun;

  if(AFTisAFun2ATerm(at)) {
    afun = AFTgetAFunATerm(at);
    return SDFflattenAFun(afun);
  } 
  else 
    return at;
}

/*}}}  */
/*{{{  ATerm SDFflattenId(ATerm id) */

/**
 * Converts an identifier.
 **/

ATerm SDFflattenId(ATerm id)
{
  char *str;
  ATerm newid = NULL;

  if(ATmatchTerm(id,pattern_asfix_lex, &str, NULL)) {
    newid = ATmakeTerm(pattern_asfix_id,str);
  }
  return newid;
}

ATermList SDFflattenSymbols(ATerm symbols);

ATerm SDFflattenComplexId(ATerm id, ATerm symbols)
{
  char *str;
  ATerm newid = NULL; 
  ATermList newsymbols = ATempty;

  if(ATmatchTerm(id,pattern_asfix_lex, &str, NULL)) {
    newsymbols = SDFflattenSymbols(symbols);
    newid = ATmake("id(<str(<list>)>)", str, newsymbols);
  }
  return newid;
}
/*}}}  */
/*{{{  ATerm SDFflattenAttr(ATerm attr) */

/**
 * Convert one attribute.
 **/
ATerm SDFflattenAttr(ATerm attr)
{
  char *str;
  ATerm symbols, assocattr, attrlit, modid, name, newattr = NULL;

  if(AFTisAssocAttr(attr)) {
    assocattr = AFTgetAssocAttr(attr);
    if(AFTisLeftAssoc(assocattr) ||
       AFTisRightAssoc(assocattr) ||
       AFTisAssocAssoc(assocattr) ||
       AFTisNonAssocAssoc(assocattr)) {
      attrlit = AFTgetArgAssoc(assocattr);
      if(ATmatchTerm(attrlit, pattern_asfix_l, &str)) {
        newattr = ATmake("atr(<str>)",str);
      }
    }
  }
  else if(AFTisBracketAssoc(attr) ||
          AFTisConstructorAssoc(attr) ||
          AFTisMemoAssoc(attr) ||
          AFTisRejectAttr(attr) ||
          AFTisPreferAttr(attr) ||
          AFTisUneagerAttr(attr)) {
    attrlit = AFTgetArgAssoc(attr);
    if(ATmatchTerm(attrlit, pattern_asfix_l, &str)) {
      newattr = ATmake("atr(<str>)",str);
    }
  }
  else if(AFTisModuleAttr(attr)) {
    modid = AFTgetModuleAttrId(attr);
    if(AFTisSimpleModuleId(modid)) {
      name = AFTgetSimpleModuleIdName(modid);
      newattr = SDFflattenId(name);
    }
    else if(AFTisComplexModuleId(modid)) {
      name = AFTgetComplexModuleIdName(modid);
      symbols = AFTgetComplexModuleIdSymbols(modid);
      newattr = SDFflattenComplexId(name, symbols);
    }
  }
  else if(AFTisConsAttr(attr)) {
    ATerm at, newat;
    at = AFTgetConsArg(attr);
    newat = SDFflattenATerm(at);
    newattr = ATmake("cons(<term>)",newat);
  }
  else if(AFTisTraverseAttr(attr)) {
    newattr = ATmake("traverse");
  }
  else
    ATerror("expected attribute, got %t\n", attr);
  return newattr;
}

/*}}}  */
/*{{{  ATerm SDFflattenAttrs(ATerm attrs) */

/**
 * Converts the attributes.
 **/
ATerm SDFflattenAttrs(ATerm attrs)
{
  ATerm attrlist, attr, newattr, resultattr;
  ATermList attrelems, newattrlist = ATempty;

  if(AFTisEmptyAttrs(attrs))
    return ATparse("no-attrs");
  else if(AFTisAttrs(attrs)) {
    attrlist = AFTgetAttrsList(attrs);

    if(!AFTisList(attrlist))
      ATerror("not a list: %t\n", attrlist);

    attrelems = AFTgetListElements(attrlist);

    while(!ATisEmpty(attrelems)) {
      attr = ATgetFirst(attrelems);
      attrelems = ATgetNext(attrelems);
      if(!AFTisWS(attr) && !AFTisSep(attr)) {
        newattr = SDFflattenAttr(attr);
        newattrlist = ATappend(newattrlist,newattr);
      }
    }
    resultattr = ATmake("attrs(<term>)", (ATerm)newattrlist);
    return resultattr;
  }
  else
    ATerror("expected attributes, got %t\n", attrs);
    return NULL;
}

/*}}}  */
/*{{{  ATerm SDFflattenSort(ATerm sort) */

/**
 * Converts a sort.
 **/
ATerm SDFflattenSort(ATerm sort)
{
  char *str;
  ATerm newsort = NULL;

  if(ATmatchTerm(sort,pattern_asfix_lex, &str, NULL)) {
    newsort = ATmakeTerm(pattern_asfix_sort,str);
  }
  return newsort;
}

/*}}}  */
/*{{{  ATerm SDFflattenCharacter(ATerm chr) */

static char *make_char(char *s)
{
  int len = strlen(s);
  char *rs = (char *)malloc(len);

  if(s[0] == '\\') {
    if(!strncpy(rs,++s,len-1))
      ATerror("Run out of memory!\n");
    rs[len-1] = '\0';
    return rs;
  }
  return s;
}

int make_integer(char *s)
{
  int i,ic = 0, len = strlen(s);

  if(s[0] == '\\') {
    for(i = 1; i < len; i++) {
      switch(s[i]) {
        case '0': ic=10*ic; break;
        case '1': ic=10*ic+1; break;
        case '2': ic=10*ic+2; break;
        case '3': ic=10*ic+3; break;
        case '4': ic=10*ic+4; break;
        case '5': ic=10*ic+5; break;
        case '6': ic=10*ic+6; break;
        case '7': ic=10*ic+7; break;
        case '8': ic=10*ic+8; break;
        case '9': ic=10*ic+9; break;
      }
    }
  }
  return ic;
}

ATerm SDFflattenCharacter(ATerm chr)
{
  char *str;
  ATerm nchr, sort;

  if(AFTisNumChar(chr)) {
    nchr = AFTgetNumChar(chr);
    if(ATmatchTerm(nchr,pattern_asfix_lex, &str, &sort)) {
      return (ATerm)ATmakeInt(make_integer(str));
    }
  }
  return NULL;
}

/*}}}  */
/*{{{  ATerm SDFflattenCharRange(ATerm cr) */

ATerm SDFflattenCharRange(ATerm cr)
{
  ATerm chr, chr1, chr2;

  if(AFTisSingleCharacter(cr)) {
    chr = AFTgetSingleCharacter(cr);
    return SDFflattenCharacter(chr);
  }
  else if(AFTisCharacterRange(cr)) {
    chr1 = AFTgetLeftCharacter(cr);
    chr2 = AFTgetRightCharacter(cr);
    return ATmake("range(<term>,<term>)",
                  SDFflattenCharacter(chr1),
                  SDFflattenCharacter(chr2));
  }
  return NULL;
}

/*}}}  */
/*{{{  ATermList SDFflattenCharRanges(ATerm crs) */

ATermList SDFflattenCharRanges(ATerm crs)
{
  ATerm cr, lcrs, rcrs;
  ATermList newlcrs = ATempty, newrcrs = ATempty,
            newcrs = ATempty;

  if(AFTisSingleCharRange(crs)) {
    cr = AFTgetSingleCharRange(crs);
    return ATmakeList1(SDFflattenCharRange(cr));
  }
  else if(AFTisCharRangeList(crs)) {
    lcrs = AFTgetLeftCharRanges(crs);
    rcrs = AFTgetRightCharRanges(crs);
    newlcrs = SDFflattenCharRanges(lcrs);
    newrcrs = SDFflattenCharRanges(rcrs);
    newcrs = ATconcat(newlcrs,newrcrs);
    return newcrs;
  }
  else {
    return ATempty;
  }
}

/*}}}  */
/*{{{  ATerm SDFflattenCharClass(ATerm cc) */

/**
 * Converts a charclass.
 **/
ATerm SDFflattenCharClass(ATerm cc)
{
  ATerm crs, ocrs, newcc = NULL;
  ATermList newcrs = ATempty;

  if(AFTisOptCharRanges(cc)) {
    ocrs = AFTgetOptCharRanges(cc);
    if(AFTisCharRanges(ocrs)) {
      crs = AFTgetCharRanges(ocrs);
      newcrs = SDFflattenCharRanges(crs);
      newcc = ATmake("char-class([<list>])", newcrs);
    }
    else 
      newcc = ATmake("char-class([<list>])", newcrs);
  }
  return newcc;
}

/*}}}  */
/*{{{  ATerm SDFflattenLiteral(ATerm literal) */

/**
 * Converts a literal.
 **/

ATerm SDFflattenLiteral(ATerm literal)
{
  char *str;
  ATerm uqliteral, sort;
  ATerm newliteral = NULL;

  if(AFTisUQLiteralSymbol(literal)) {
    uqliteral = AFTgetUQLiteralLiteral(literal);
    if(ATmatchTerm(uqliteral,pattern_asfix_lex, &str, &sort)) {
      if(ATisEqual(sort,ATparse("sort(\"Literal\")")))
        newliteral = ATmakeTerm(pattern_asfix_lit,unquote_str2(str));
      else
        newliteral = ATmakeTerm(pattern_asfix_lit,unquote_str2(str));
    }
  }
  else if(ATmatchTerm(literal,pattern_asfix_lex, &str, &sort)) {
    if(ATisEqual(sort,ATparse("sort(\"Literal\")")))
      newliteral = ATmake("lit(<str>)",unquote_str2(str));
    else
      newliteral = ATmake("lit(<str>)",unquote_str2(str));
  }
  else
    ATerror("expected literal, got %t\n", literal);
  return newliteral;
}

/*}}}  */
/*{{{  ATerm SDFflattenSymbol(ATerm symbol) */

ATermList SDFflattenSymbols(ATerm symbols);
/**
 * Converts a list of symbols.
 **/
ATerm SDFflattenSymbol(ATerm symbol)
{
  ATerm symbol2, symbol3, sort, literal, symbols,
        newsort, newliteral, number, newnumber, newsymbol = NULL;
  ATermList newsymbols;

  if(AFTisSortSymbol(symbol)) {
    sort = AFTgetSortSymbol(symbol);
    newsymbol = SDFflattenSort(sort);
  }
  else if(AFTisLiteralSymbol(symbol)) {
    literal = AFTgetLiteralSymbol(symbol);
    newsymbol = SDFflattenLiteral(literal);
  }
  else if(AFTisStarListSymbol(symbol)) {
    sort = AFTgetStarListSort(symbol);
    newsort = SDFflattenSymbol(sort);
    newsymbol = ATmake("iter-star(<term>)",newsort);
  }
  else if(AFTisPlusListSymbol(symbol)) {
    sort = AFTgetPlusListSort(symbol);
    newsort = SDFflattenSymbol(sort);
    newsymbol = ATmake("iter(<term>)",newsort);
  }
  else if(AFTisListNumberSymbol(symbol)) {
    sort = AFTgetListNumberSort(symbol);
    number = AFTgetListNumberNumber(symbol);
    newsort = SDFflattenSymbol(sort);
    newnumber = SDFflattenNumber(number);
    newsymbol = ATmake("iter-n(<term>,<term>)", newsort, newnumber);
  }
  else if(AFTisListSepNumberSymbol(symbol)) {
    sort = AFTgetListSepNumberSort(symbol);
    literal = AFTgetListSepNumberSep(symbol);
    number = AFTgetListSepNumberNumber(symbol);
    newsort = SDFflattenSymbol(sort);
    newliteral = SDFflattenSymbol(literal);
    newnumber = SDFflattenNumber(number);
    newsymbol = ATmake("iter-sep-n(<term>,<term>,<term>)",
                       newsort, newliteral, newnumber);
  }
  else if(AFTisStarSepListSymbol(symbol)) {
    sort = AFTgetStarSepListSort(symbol);
    literal = AFTgetStarSepListSep(symbol);
    newsort = SDFflattenSymbol(sort);
    newliteral = SDFflattenSymbol(literal);
    newsymbol = ATmake("iter-star-sep(<term>,<term>)",newsort,newliteral);
  }
  else if(AFTisPlusSepListSymbol(symbol)) {
    sort = AFTgetPlusSepListSort(symbol);
    literal = AFTgetPlusSepListSep(symbol);
    newsort = SDFflattenSymbol(sort);
    newliteral = SDFflattenSymbol(literal);
    newsymbol = ATmake("iter-sep(<term>,<term>)",newsort,newliteral);
  }
  else if(AFTisBasicLEXSymbol(symbol)) {
    symbol2 = AFTgetBasicLEXSymbol(symbol);
    newsymbol = ATmake("lex(<term>)", SDFflattenSymbol(symbol2));
  }
  else if(AFTisBasicCFSymbol(symbol)) {
    symbol2 = AFTgetBasicCFSymbol(symbol);
    newsymbol = ATmake("cf(<term>)", SDFflattenSymbol(symbol2));
  }
  else if(AFTisBasicLAYOUTSymbol(symbol)) {
    newsymbol = ATparse("layout");
  }
  else if(AFTisSTARTSymbol(symbol)) {
    newsymbol = ATparse("sort(\"<START>\")");
  }
  else if(AFTisStartSymbol(symbol)) {
    newsymbol = ATparse("sort(\"<Start>\")");
  }
  else if(AFTisRegularOptSymbol(symbol)) {
    symbol2 = AFTgetRegularOptSymbol(symbol);
    newsymbol = ATmake("opt(<term>)", SDFflattenSymbol(symbol2));
  }
  else if(AFTisRegularAltSymbol(symbol)) {
    symbol2 = AFTgetRegularAltSymbol0(symbol);
    symbol3 = AFTgetRegularAltSymbol1(symbol);
    newsymbol = ATmake("alt(<term>,<term>)", 
                       SDFflattenSymbol(symbol2),
                       SDFflattenSymbol(symbol3));
  }
  else if(AFTisRegularSetSymbol(symbol)) {
    symbol2 = AFTgetRegularSetSymbol(symbol);
    newsymbol = ATmake("set(<term>)", 
                       SDFflattenSymbol(symbol2));
  }
  else if(AFTisRegularEmptySeqSymbol(symbol)) {
    newsymbol = ATmake("empty");
  }
  else if(AFTisRegularNonEmptySeqSymbol(symbol)) {
    ATerm symbollist, newsymbol3;
    ATermList symbolelems, newsymbollist = ATempty;

    symbol2 = AFTgetRegularNonEmptySeqSymbol0(symbol);
    symbollist = AFTgetRegularNonEmptySeqSymbol1(symbol);
  
    if(!AFTisList(symbollist))
      ATerror("not a list: %t\n", symbollist);

    symbolelems = AFTgetListElements(symbollist);

    while(!ATisEmpty(symbolelems)) {
      symbol3 = ATgetFirst(symbolelems);
      symbolelems = ATgetNext(symbolelems);

      if(!AFTisWS(symbol3)) {
        newsymbol3 = SDFflattenSymbol(symbol3);
        newsymbollist = ATappend(newsymbollist,newsymbol3);
      }
    }

    newsymbol = ATmake("seq([<list>])", 
                       ATinsert(newsymbollist, SDFflattenSymbol(symbol2)));
  }
  else if(AFTisRegularTupleSymbol(symbol)) {
    symbol2 = AFTgetRegularTupleSymbol0(symbol);
    symbol3 = AFTgetRegularTupleSymbol1(symbol);
    newsymbol = ATmake("pair(<term>,<term>)",
                       SDFflattenSymbol(symbol2),
                       SDFflattenSymbol(symbol3));
  }
  else if(AFTisRegularFuncSymbol(symbol)) {
    symbols = AFTgetRegularFuncSymbols(symbol);
    symbol2 = AFTgetRegularFuncSymbol(symbol);
    newsymbols = SDFflattenSymbols(symbols);
    newsymbol = ATmake("func([<list>],<term>)", 
                       newsymbols, SDFflattenSymbol(symbol2));
  }
  else if(AFTisRegularPermSymbol(symbol)) {
    symbols = AFTgetRegularPermSymbols(symbol);
    newsymbols = SDFflattenSymbols(symbols);
    newsymbol = ATmake("perm([<list>])", newsymbols);
  }
  else if(AFTisCharClassSymbol(symbol)) {
    symbol2 = AFTgetCharClassSymbol(symbol);
    newsymbol = SDFflattenCharClass(symbol2);
  }
  else if(AFTisVarSymbol(symbol)) {
    symbol2 = AFTgetVarSymbol(symbol);
    newsymbol = ATmake("varsym(<term>)", SDFflattenSymbol(symbol2));
  } 
  else if(AFTisLabeledSymbol(symbol)) {
    symbol2 = AFTgetLabeledSymbol(symbol);
    newsymbol = SDFflattenSymbol(symbol2);
  }
  else {
    ATabort("Unknown symbol %t\n", symbol);
    newsymbol = symbol;
  }

  return newsymbol;
}

/*}}} */
/*{{{  ATermList SDFflattenSymbols(ATerm symbols) */

/**
 * Converts a list of symbols.
 **/
ATermList SDFflattenSymbols(ATerm symbols)
{
  ATerm symbollist, symbol, newsymbol;
  ATermList symbolelems, newsymbollist = ATempty;

  if(!AFTisSymbols(symbols))
    ATerror("expected symbols, got %t\n", symbols);

  symbollist = AFTgetSymbolsList(symbols);

  if(!AFTisList(symbollist))
    ATerror("not a list: %t\n", symbollist);

  symbolelems = AFTgetListElements(symbollist);

  while(!ATisEmpty(symbolelems)) {
    symbol = ATgetFirst(symbolelems);
    symbolelems = ATgetNext(symbolelems);

    if(!AFTisWS(symbol)) {
      newsymbol = SDFflattenSymbol(symbol);
      newsymbollist = ATappend(newsymbollist,newsymbol);
    }
  }
  return newsymbollist;
}

/*}}}  */
/*{{{ ATerm SDFflattenProd(ATerm prod) */

/**
 * Converts the term representation of a production into the production rule
 * itself.
 **/

ATerm SDFflattenProd(ATerm prod)
{
  ATerm symbols = NULL, symbol, newsymbol = NULL, attrs, newattrs = NULL;
  ATermList newsymbollist = ATempty;

  if(AFTisProd(prod)) {
    symbols = AFTgetProdSymbols(prod);
    symbol =  AFTgetProdSymbol(prod);
    attrs = AFTgetProdAttrs(prod);

    newsymbollist = SDFflattenSymbols(symbols);
    newsymbol = SDFflattenSymbol(symbol);
    newattrs = SDFflattenAttrs(attrs);
  }
  else
    ATerror("expected prod, got %t\n", prod);

  return ATmake("prod([<list>],<term>,<term>)",
                newsymbollist, newsymbol, newattrs);
}

/*}}} */
/*{{{ ATerm SDFflattenLookAhead(ATerm la) */

/**
 * Converts the term representation of a lookahead.
 **/

ATerm SDFflattenLookAhead(ATerm la, ATbool nested)
{
  ATerm lookaheadlist, newlookahead, lookahead,
        las, charclass = NULL, newcharclass = NULL;
  ATermList lookaheadelems, newlookaheads;

  if(AFTisLookAhead(la) && !nested) {
    charclass = AFTgetLookAheadCharClass(la);

    return SDFflattenCharClass(charclass);
  }
  else if(AFTisLookAhead(la) && nested) {
    charclass = AFTgetLookAheadCharClass(la);

    newcharclass = SDFflattenCharClass(charclass);
    return ATmake("look(<term>,[<list>])", newcharclass, ATempty);
  }
  else if(AFTisComplexLookAhead(la)) {
    charclass = AFTgetComplexLookAheadCharClass(la);
    las = AFTgetComplexLookAheadLookAheads(la);

    newcharclass = SDFflattenCharClass(charclass);

    if(!AFTisLookAheads(las))
      ATerror("expected lookaheads, got %t\n", las);

    lookaheadlist = AFTgetLookAheadsList(las);

    if(!AFTisList(lookaheadlist))
      ATerror("not a list: %t\n", lookaheadlist);

    lookaheadelems = AFTgetListElements(lookaheadlist);
    newlookaheads = ATempty;
    while(!ATisEmpty(lookaheadelems)) {
      lookahead = ATgetFirst(lookaheadelems);

      if(!AFTisWS(lookahead) && !AFTisSep(lookahead)) {
         newlookahead = SDFflattenLookAhead(lookahead, ATtrue);
         newlookaheads = ATappend(newlookaheads, newlookahead);
      }
      lookaheadelems = ATgetNext(lookaheadelems);
    }
    return ATmake("look(<term>,[<list>])",
                   newcharclass, newlookaheads);
  }
  else {
    ATerror("expected lookahead, got %t\n", la);
    return NULL;
  }
}

/*}}} */
