#include "Library.h"
#include <ctype.h>

/*{{{  CO_LexStrCon CO_makeLexStrCon(const char* str) */

static CO_LexStrCon CO_makeLexStrCon(const char* str)
{
  int len = strlen(str);
  int i;
  CO_LexStrCharChars list = CO_makeLexStrCharCharsEmpty();

  for (i = len - 1; i >= 0; i--) {
    CO_LexStrChar ch;

    switch(str[i]) {
      case '\n':
	ch = CO_makeLexStrCharNewline();
	break;
      case '\t':
	ch = CO_makeLexStrCharTab();
	break;
      case '"':
	ch = CO_makeLexStrCharQuote();
	break;
      case '\\':
	ch = CO_makeLexStrCharBackslash();
	break;
      default:
	if (isprint((int) str[i])) {
	  ch = CO_makeLexStrCharNormal(str[i]);
	}
	else {
	  int value = str[i];
	  int a, b, c;

	  c = value % 10;
	  value /= 10;
	  b = value % 10;
	  value /= 10;
	  a = value;

	  ch = CO_makeLexStrCharDecimal(a,b,c);
	}
    }

    list = CO_makeLexStrCharCharsMany(ch, list);
  }


  return CO_makeLexStrConDefault(list);
}

/*}}}  */
CO_StrCon CO_makeStrCon(const char* str)
{
  return CO_makeStrConLexToCf(CO_makeLexStrCon(str));
}

