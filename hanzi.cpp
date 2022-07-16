//
// Created by 姚康 on 2022/7/16.
//

#include "hanzi.h"

void zi(int a[24][24],SString symbol)
{
    int max=a[0][0];
    int delay = 2000 / max;
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
        usleep(delay*1000);
    }
}
