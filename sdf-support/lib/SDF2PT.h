#ifndef SDF2PT_H
#define SDF2PT_H

#include <MEPT.h>
#include <SDFME.h>

PT_Production SDFProductionToPtProduction(SDF_Production sdfProduction);
PT_Symbol SDFSymbolToPtSymbol(SDF_Symbol symbol);
PT_Symbol SDFCharClassToPtSymbol(SDF_CharClass sdfCharClass);

#endif
