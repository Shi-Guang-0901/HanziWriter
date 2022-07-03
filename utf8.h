#ifndef UTF8_H_INCLUDED
#define UTF8_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

uchar *createStr(FILE *fp);
long fileLength(FILE *fp);
int letterTotal(uchar *str,int length);
int typeByUTF8(const unsigned char ch);

#endif // UTF8_H_INCLUDED
