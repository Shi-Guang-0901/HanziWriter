#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "sstring.h"
#include "utf8.h"
#include "file.h"
#include "info.h"
#include "tools.h"

#ifdef _WIN32
#include <windows.h>
#endif

extern SString open_faild;
extern SString open_exception;
extern SString symbol;


void color(int x);
void zi(int ma[24][24]);
void hide_Curser();

typedef int HANZI[24][24];
typedef char Hanzi[4];

int main()
{
#ifdef _WIN32
    system("mode con cols=48 lines=24");
    hide_Curser();
    srand((unsigned)time(NULL));
#elif __linux__
    system("clear");
#endif
    init_string();
    /*int code = getCodepage();
    if(code == 936)
    {
        convert_string();
    }*/

    SString pre;
#ifdef _WIN32
    create_string(&pre,".\\data\\");
#elif __linux__
    create_string(&pre,"./data/");
#endif
    SString data;
    create_string(&data,"hanzi.txt");
    FILE *example=NULL,*shape=NULL;
    HANZI shapeOfHanzi = {0};

    //打开显示字样文件
    if((example=fopen(data.values,"rb"))==NULL)
    {
        print_string(open_faild);
        exit(-1);
    }

    long file_length = fileLength(example);
    uchar *text = createStr(example);
    int sumOfLetter = letterTotal(text,file_length);
     
    if((file_length%3!=0)&&(file_length/3)!=sumOfLetter)
    {
        print_string(open_exception);
        exit(-10);
    }
    fclose(example);

    Hanzi *hanzis = (Hanzi*)malloc(sizeof(Hanzi)*sumOfLetter);
    int index=0,j;
    for(int i=0; i<sumOfLetter; i++)
    {

        for(j=0; j<3; j++)
        {
            hanzis[i][j]=text[index++];
        }
        hanzis[i][j]='\0';
        SString hzi= {NULL,0};
        create_string(&hzi,hanzis[i]);
        SString filenameOfShape= {NULL,0};
        concat_string(&filenameOfShape,pre,hzi);
        /*if(code == 936)
        {
            convert(&filenameOfShape,filenameOfShape,"UTF-8","GBK");
        }*/
        if((shape=fopen(filenameOfShape.values,"rb"))==NULL)
        {
            printf("\'%s\'\n",filenameOfShape.values);
            print_string(open_faild);
            exit(-1);
        }
        fread(shapeOfHanzi,sizeof(HANZI),1,shape);

        zi(shapeOfHanzi);
        clear_screen(48,24);


        clear_string(&filenameOfShape);
        clear_string(&hzi);
        fclose(shape);
    }
    return 0;
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
            break;                      // 琥珀色
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



void zi(int a[24][24])
{
    int max=a[0][0];
    int sleeptime = 2000 / max;

    int i,j;
    int n=0;
    while(n<=max)
    {
        n++;
        for(i=1; i<24; i++)
        {
            for(j=1; j<24; j++)
            {
                if(a[i][j]==n)
                {
                    mygotoxy(j*2,i);
                    printf("%s",symbol.values);
		    fflush(stdout);
                }
            }
        }
        usleep(sleeptime*1000);
    }
}

