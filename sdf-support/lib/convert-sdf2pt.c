#include "SDFME-utils.h"
#include <MEPT-utils.h>
#include <string.h>

PT_Symbol SDFsymbol2PtSymbol(SDF_Symbol sdfSymbol)
{
  char cbuf[1024];

  if (SDF_isSymbolSort(sdfSymbol)) {
    char *sortName = PT_yieldTree(
                       PT_makeTreeFromTerm(
                         SDF_makeTermFromSort(
                           SDF_getSymbolSort(sdfSymbol))));
    return PT_makeSymbolSort(sortName);
  }
  if (SDF_isSymbolLit(sdfSymbol)) {
    char *literal = PT_yieldTree(
                      PT_makeTreeFromTerm(
                        SDF_makeTermFromLiteral(
                          SDF_getSymbolLiteral(sdfSymbol))));
    strncpy(cbuf, literal+1, strlen(literal)-2);
    cbuf[strlen(literal)-2] = '\0';
    return PT_makeSymbolLit(cbuf);
  }
  if (SDF_isSymbolEmpty(sdfSymbol)) {
    return PT_makeSymbolEmpty();
  }
/* Seq */
  if (SDF_isSymbolOpt(sdfSymbol)) {
    PT_Symbol argSymbol = SDFsymbol2PtSymbol(SDF_getSymbolSymbol(sdfSymbol));

    return PT_makeSymbolOpt(argSymbol);
  }
  if (SDF_isSymbolAlt(sdfSymbol)) {
    PT_Symbol leftSymbol = SDFsymbol2PtSymbol(SDF_getSymbolLeft(sdfSymbol));
    PT_Symbol rightSymbol = SDFsymbol2PtSymbol(SDF_getSymbolRight(sdfSymbol));

    return PT_makeSymbolAlt(leftSymbol, rightSymbol);
  }
  if (SDF_isSymbolPair(sdfSymbol)) {
    PT_Symbol leftSymbol = SDFsymbol2PtSymbol(SDF_getSymbolLeft(sdfSymbol));
    PT_Symbol rightSymbol = SDFsymbol2PtSymbol(SDF_getSymbolRight(sdfSymbol));

    return PT_makeSymbolPair(leftSymbol, rightSymbol);
  }
  if (SDF_isSymbolIter(sdfSymbol)) {
    PT_Symbol argSymbol = SDFsymbol2PtSymbol(SDF_getSymbolSymbol(sdfSymbol));

    return PT_makeSymbolIterPlus(argSymbol);
  }
  if (SDF_isSymbolIterStar(sdfSymbol)) {
    PT_Symbol argSymbol = SDFsymbol2PtSymbol(SDF_getSymbolSymbol(sdfSymbol));

    return PT_makeSymbolIterStar(argSymbol);
  }
  if (SDF_isSymbolIterSep(sdfSymbol)) {
    PT_Symbol argSymbol = SDFsymbol2PtSymbol(SDF_getSymbolSymbol(sdfSymbol));
    PT_Symbol separator = SDFsymbol2PtSymbol(SDF_getSymbolSep(sdfSymbol));

    return PT_makeSymbolIterPlusSep(argSymbol, separator);
  }
  if (SDF_isSymbolIterStarSep(sdfSymbol)) {
    PT_Symbol argSymbol = SDFsymbol2PtSymbol(SDF_getSymbolSymbol(sdfSymbol));
    PT_Symbol separator = SDFsymbol2PtSymbol(SDF_getSymbolSep(sdfSymbol));

    return PT_makeSymbolIterStarSep(argSymbol, separator);
  }
ATwarning("Symbol %t not yet supported!\n", sdfSymbol);
  return NULL;
}
