#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "sstring.h"
#include "utf8.h"
#include "file.h"
#include "info.h"
#include "tools.h"
#include "hanzi.h"

#ifdef _WIN32
#include <windows.h>
#endif

extern SString open_faild;
extern SString open_exception;
extern SString symbol;



void hide_Curser();


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

        zi(shapeOfHanzi,symbol);
        clear_screen(48,24);


        clear_string(&filenameOfShape);
        clear_string(&hzi);
        fclose(shape);
    }
    return 0;
}

