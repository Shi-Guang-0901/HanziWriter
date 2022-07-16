#include "tools.h"

void clear_line(int y,int cols)
{
    mygotoxy(0, y);
    for (int i = 0; i < cols; i++)
    {
        printf(" ");
    }
    mygotoxy(0, y);
}


void clear_screen(int rows,int lines)
{
    clear_screen(0,0,rows,lines);
}

void clear_screen(int x, int y,int rows,int lines)
{
    for(int i = x; i< rows; i++)
    {
        for(int j = y; j< lines; j++)
        {
            mygotoxy( i,j);
            printf(" ");
        }
    }
    mygotoxy(x,y);
}

void progress_bar(long long completed, long long all, int width, int x, int y)
{
    mygotoxy(x, y);
    int total = (int)((completed * 1.0 / all) * width);
    for (int i = 0; i <= width; i++)
    {
        printf("-");
    }
    mygotoxy(x, y);
    for (int i = 0; i <= total - 1; i++)
    {
        printf("-");
    }
    printf(">");
    clear_line(3, width);
    printf("already completed %.2lf%%", (completed * 1.0 / all) * 100);
}

int getCodepage()
{
    system("chcp>codepage.dat");
    FILE *fp = NULL;

    if ((fp = fopen("codepage.dat", "r")) == NULL)
    {
        exit(-1);
    }

    SString S, Q;
    char buf[32];
    fgets(buf, 32, fp);
    create_string(&S, buf);
    delete_string(&S, "\n");

    int ind = index(S, ": ");
    int len = strlen(": ");
    create_string(&Q, S.values, ind + len, S.length - ind - len);

    int codepage = atoi(Q.values);

    fclose(fp);
    system("del codepage.dat");

    return codepage;
}

void mygotoxy(int x, int y)
{
    #ifdef _WIN32
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
#elif __linux__
    printf("%c[%d;%df",0x1B,y,x);    
#endif
}

void color(int x)
{
    switch (x)
    {
        case 1:
            printf("\e[31;49m");
            break;                      // 红色
        case 2:
            printf("\e[32;49m");
            break;                      // 绿色
        case 3:
            printf("\e[33;49m");
            break;                      // 黄色
        case 4:
            printf("\e[34;49m");
            break;                      // 蓝色
        case 5:
            printf("\e[35;49m");
            break;                      // 紫色
        case 6:
            printf("\e[36;49m");
            break;                      // 青色
        case 0:
            printf("\e[0;0m");
            break;
            // 默认
    }
}

void hide_Curser()
{
#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = 0; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
#elif __linux__
    printf("\033[?25l");
#endif
}
