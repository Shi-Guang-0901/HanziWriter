#ifndef TOOLS_H_INCLUDE
#define TOOLS_H_INCLUDE
#ifdef _WIN32
#include <windows.h>
#elif __linux__

#endif

#include "sstring.h"


/**
 * 进度条
 * @param completed 已完成的
 * @param all  一共需要完成的
 * @param width 进度条的宽度
 * @param x 位置-横坐标
 * @param y 位置-纵坐标
 */
void progress_bar(long long completed, long long all, int width, int x, int y);

/**
 * 清除屏幕上第y行cols列的内容
 * @param y
 * @param cols
 */
void clear_line(int y,int cols);

/**
 * 从屏幕左上角清除rows列lines行内容
 * @param rows
 * @param lines
 */
void clear_screen(int rows,int lines);

/**
 * 从(x,y)开始清除rows列lines行内容
 * @param x
 * @param y
 * @param rows
 * @param lines
 */
void clear_screen(int x, int y,int rows,int lines);


void mygotoxy(int x, int y);

/**
 * 显示控制台的编码，当前仅Windows可用
 * @return
 */
int getCodepage();

/**
 * 控制输出字符的颜色
 * @param x
 * 1 红色
 * 2 绿色
 * 3 黄色
 * 4 蓝色
 * 5 紫色
 * 6 青色
 * 0 默认
 */
void color(int x);

/**
 * 隐藏光标，虽然可能失效
 */
void hide_Curser();

#endif
