#include "tools.h"

void clear_line(int y,int cols)
{
    gotoxy(0, y);
    for (int i = 0; i < cols; i++)
    {
        printf(" ");
    }
    gotoxy(0, y);
}

void clear_screen(int x,int y)
{
    for(int i = 0; i< x; i++)
    {
        for(int j = 0; j< y; j++)
        {
            gotoxy( i,j);
            printf(" ");
        }
    }
    gotoxy(0,0);
}

void progress_bar(long long completed, long long all, int weight,int x, int y)
{
    gotoxy(x, y);
    int total = (int)((completed * 1.0 / all) * weight);
    for (int i = 0; i <= weight; i++)
    {
        printf("-");
    }
    gotoxy(x, y);
    for (int i = 0; i <= total - 1; i++)
    {
        printf("-");
    }
    printf(">");
    clear_line(3,weight);
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

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}