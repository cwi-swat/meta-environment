/*
   $Id$
*/         

#ifndef _ASFIX2_H
#define _ASFIX2_H

#include <aterm2.h>
#include <deprecated.h>
#include <MEPT.h>

void   PT_initAsFix2Api(void);

ATbool isLexicalListProd(PT_Production prod);
ATbool isCharClassListProd(PT_Production prod);
ATbool isListProd(PT_Production prod);
ATbool isSepListProd(PT_Production prod);

#endif /* _ASFIX2_H */ 
