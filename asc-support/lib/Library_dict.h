#ifndef __Library_dict_H
#define __Library_dict_H

#include <aterm2.h>

extern AFun CO_afun17;
extern AFun CO_afun3;
extern AFun CO_afun78;
extern AFun CO_afun48;
extern AFun CO_afun34;
extern AFun CO_afun59;
extern AFun CO_afun37;
extern AFun CO_afun26;
extern AFun CO_afun19;
extern AFun CO_afun63;
extern AFun CO_afun2;
extern AFun CO_afun47;
extern AFun CO_afun80;
extern AFun CO_afun42;
extern AFun CO_afun25;
extern AFun CO_afun15;
extern AFun CO_afun75;
extern AFun CO_afun18;
extern AFun CO_afun86;
extern AFun CO_afun31;
extern AFun CO_afun69;
extern AFun CO_afun43;
extern AFun CO_afun54;
extern AFun CO_afun0;
extern AFun CO_afun84;
extern AFun CO_afun38;
extern AFun CO_afun33;
extern AFun CO_afun16;
extern AFun CO_afun77;
extern AFun CO_afun10;
extern AFun CO_afun13;
extern AFun CO_afun52;
extern AFun CO_afun40;
extern AFun CO_afun14;
extern AFun CO_afun74;
extern AFun CO_afun82;
extern AFun CO_afun30;
extern AFun CO_afun60;
extern AFun CO_afun7;
extern AFun CO_afun58;
extern AFun CO_afun79;
extern AFun CO_afun57;
extern AFun CO_afun35;
extern AFun CO_afun81;
extern AFun CO_afun29;
extern AFun CO_afun6;
extern AFun CO_afun1;
extern AFun CO_afun39;
extern AFun CO_afun83;
extern AFun CO_afun61;
extern AFun CO_afun72;
extern AFun CO_afun50;
extern AFun CO_afun22;
extern AFun CO_afun44;
extern AFun CO_afun66;
extern AFun CO_afun73;
extern AFun CO_afun9;
extern AFun CO_afun51;
extern AFun CO_afun56;
extern AFun CO_afun41;
extern AFun CO_afun85;
extern AFun CO_afun12;
extern AFun CO_afun53;
extern AFun CO_afun64;
extern AFun CO_afun70;
extern AFun CO_afun20;
extern AFun CO_afun28;
extern AFun CO_afun8;
extern AFun CO_afun21;
extern AFun CO_afun32;
extern AFun CO_afun65;
extern AFun CO_afun76;
extern AFun CO_afun11;
extern AFun CO_afun62;
extern AFun CO_afun27;
extern AFun CO_afun5;
extern AFun CO_afun55;
extern AFun CO_afun4;
extern AFun CO_afun67;
extern AFun CO_afun23;
extern AFun CO_afun49;
extern AFun CO_afun45;
extern AFun CO_afun71;
extern AFun CO_afun68;
extern AFun CO_afun36;
extern AFun CO_afun24;
extern AFun CO_afun46;

extern ATerm CO_patternBooleanBracket;
extern ATerm CO_patternBooleanNot;
extern ATerm CO_patternBooleanAnd;
extern ATerm CO_patternBooleanOr;
extern ATerm CO_patternBooleanConstant;
extern ATerm CO_patternXCast;
extern ATerm CO_patternParsetreeXFailure;
extern ATerm CO_patternParsetreeXSuccess;
extern ATerm CO_patternWriteFailure;
extern ATerm CO_patternWriteSuccess;
extern ATerm CO_patternReadFailure;
extern ATerm CO_patternReadSuccess;
extern ATerm CO_patternAreaArea;
extern ATerm CO_patternLocationAreaInFile;
extern ATerm CO_patternLocationArea;
extern ATerm CO_patternLocationFile;
extern ATerm CO_patternErrorListMany;
extern ATerm CO_patternErrorListSingle;
extern ATerm CO_patternErrorListEmpty;
extern ATerm CO_patternSubjectListMany;
extern ATerm CO_patternSubjectListSingle;
extern ATerm CO_patternSubjectListEmpty;
extern ATerm CO_patternSummarySummary;
extern ATerm CO_patternErrorFatal;
extern ATerm CO_patternErrorError;
extern ATerm CO_patternErrorWarning;
extern ATerm CO_patternErrorInfo;
extern ATerm CO_patternSubjectLocalized;
extern ATerm CO_patternSubjectSubject;
extern ATerm CO_patternLexByteListMany;
extern ATerm CO_patternLexByteListSingle;
extern ATerm CO_patternLexByteListEmpty;
extern ATerm CO_patternBytesLexToCf;
extern ATerm CO_patternLexBytesBytes;
extern ATerm CO_patternByteLexToCf;
extern ATerm CO_patternLexByteByte;
extern ATerm CO_patternNatConLexToCf;
extern ATerm CO_patternLexNatConDigits;
extern ATerm CO_patternBoolConFalse;
extern ATerm CO_patternBoolConTrue;
extern ATerm CO_patternLexStrCharCharsMany;
extern ATerm CO_patternLexStrCharCharsSingle;
extern ATerm CO_patternLexStrCharCharsEmpty;
extern ATerm CO_patternStrConLexToCf;
extern ATerm CO_patternLexStrConDefault;
extern ATerm CO_patternStrCharLexToCf;
extern ATerm CO_patternLexStrCharNormal;
extern ATerm CO_patternLexStrCharDecimal;
extern ATerm CO_patternLexStrCharBackslash;
extern ATerm CO_patternLexStrCharQuote;
extern ATerm CO_patternLexStrCharTab;
extern ATerm CO_patternLexStrCharNewline;
extern ATerm CO_patternStartBoolean;
extern ATerm CO_patternStartError;
extern ATerm CO_patternStartSummary;
extern ATerm CO_patternStartBoolCon;
extern ATerm CO_patternStartStrCon;
extern ATerm CO_patternLexLayoutWhitespace;
extern ATerm CO_patternLexLayoutListMany;
extern ATerm CO_patternLexLayoutListSingle;
extern ATerm CO_patternLexLayoutListEmpty;
extern ATerm CO_patternLayoutLexToCf;
extern ATerm CO_patternOptLayoutPresent;
extern ATerm CO_patternOptLayoutAbsent;

extern void init_Library_dict();

#endif /* __Library_dict_H */
