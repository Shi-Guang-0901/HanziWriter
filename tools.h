#ifndef TOOLS_H_INCLUDE
#define TOOLS_H_INCLUDE
#ifdef _WIN32
#include <windows.h>
#elif __linux__

#endif

#include "sstring.h"

void progress_bar(long long completed, long long all, int x, int y);

void clear_line(int y,int cols);
void clear_screen(int x,int y);

void mygotoxy(int x, int y);

int getCodepage();

#endif
