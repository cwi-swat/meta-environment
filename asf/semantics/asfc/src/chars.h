#ifndef _CHARS_H
#define _CHARS_H


typedef enum { QUOTED, UNQUOTED } QuotedOption;

char* escape(const char* str, const char* escaped_chars, QuotedOption quoted);
char* rmquotes(char *str);

#endif
