#ifndef PTMEPT_UTILS_H
#define PTMEPT_UTILS_H

#include <PTMEPT.h>
#include <MEPT.h>

PTPT_ParseTree PTPT_liftParseTree(PT_ParseTree pt);
PTPT_Tree PTPT_liftTree(PT_Tree pt);
PTPT_ATerm PTPT_liftATerm(ATerm trm);

/* liftTreeCache fills a cache that lowerTreeCache can reuse */
PTPT_Tree PTPT_liftTreeCache(PT_Tree pt, ATermTable lowerCache);

PT_ParseTree PTPT_lowerParseTree(PTPT_ParseTree pt);
PT_Tree PTPT_lowerTree(PTPT_Tree pt);
ATerm PTPT_lowerATerm(PTPT_ATerm trm);

/* lowerTreeCache reuses a cache that liftTreeCache has created */
PT_Tree PTPT_lowerTreeCache(PTPT_Tree pt, ATermTable lowerCache);

PTPT_LexStrCon PTPT_makeLexStrCon(const char* str);
PTPT_NatCon PTPT_liftNatCon(int val);

#endif
