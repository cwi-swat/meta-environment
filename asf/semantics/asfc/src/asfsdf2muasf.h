#ifndef _ASFSDF2MUASF_H
#define _ASFSDF2MUASF_H

#include <SDFME.h>
#include <ASFME.h>

MA_Module asfSdfToMuASF(SDF_ModuleName name, SDF_ProductionList signature, 
                        ASF_CondEquationList equations);

#endif
