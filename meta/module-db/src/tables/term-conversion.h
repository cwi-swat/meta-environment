#ifndef TERM_CONVERSION_H
#define TERM_CONVERSION_H

#define makeString(s) ((ATerm) ATmakeAppl0(ATmakeAFun(s,0,ATtrue)))
#define makeKey(s) (makeString(s))
#define makeValue(value)  ((ATermList) ATmakeList1((ATerm) value))
#define getValue(list)  ((ATerm) ATgetFirst((ATermList) list))
#define getString(t) (ATgetName(ATgetAFun((ATermAppl) t)))

#endif
