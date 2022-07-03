#ifndef TOOLS_H_INCLUDE
#define TOOLS_H_INCLUDE

#include <windows.h>
#include "sstring.h"

void progress_bar(long long completed, long long all, int x, int y);

void clear_line(int y,int cols);
void clear_screen(int x,int y);

void gotoxy(int x, int y);

int getCodepage();

#endif
