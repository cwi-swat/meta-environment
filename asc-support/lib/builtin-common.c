#include "Library.h"
#include <ctype.h>

/*{{{  CO_StrCon CO_makeStrCon(const char* str) */

CO_StrCon CO_makeStrCon(const char* str)
{
  int len = strlen(str);
  int i;
  CO_LexStrCharLine list = CO_makeLexStrCharLineEmpty();

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
	if ((int) isprint((int) str[i])) {
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

	  ch = CO_makeLexStrCharOctal(a,b,c);
	}
    }

    list = CO_makeLexStrCharLineMany(ch, list);
  }


  return CO_makeStrConLexToCf(CO_makeLexStrConDefault(list));
}

/*}}}  */

