typedef struct _MA_CHARLIST *MA_CHARLIST;

ATbool MA_isValidCHARLIST(MA_CHARLIST arg);
ATbool MA_isCHARLISTString(MA_CHARLIST arg);
char*  MA_getCHARLISTString(MA_CHARLIST arg);
MA_CHARLIST  MA_setCHARLISTString(MA_CHARLIST arg, char *str);
ATerm  MA_CHARLISTToTerm(MA_CHARLIST arg);
MA_CHARLIST MA_CHARLISTFromTerm(ATerm trm);
MA_CHARLIST MA_makeCHARLISTString(char *str);
