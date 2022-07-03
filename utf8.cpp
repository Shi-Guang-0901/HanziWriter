#include "utf8.h"

uchar *createStr(FILE *fp)
{
    long length = fileLength(fp);
    unsigned char *str = (unsigned char*)malloc(length);
    memset(str,0,length);
    fread(str,length,1,fp);

    return str;
}

/**
    文件长度
*/
long fileLength(FILE *fp)
{
    long fileLength=0;
    if(fp==NULL)
        return -1;
    else
    {
        fseek(fp,0,SEEK_END);
        fileLength=ftell(fp);
        fseek(fp,0,SEEK_SET);
    }
    return fileLength;
}
int letterTotal(uchar *str,int length)
{
    int total=0;
    int i=0;
    while(i<length)
    {
        if(typeByUTF8(*(str++))!=0)
        {
            total++;
        }
        i++;
    }
    return total;
}

int typeByUTF8(const unsigned char ch)
{
    if ((ch & 0xfc) == 0xfc)
    {
        return 6;
    }
    else if ((ch & 0xf8) == 0xf8)
    {
        return 5;
    }
    else if ((ch & 0xf0) == 0xf0)
    {
        return 4;
    }
    else if ((ch & 0xe0) == 0xe0)
    {
        return 3;
    }
    else if ((ch & 0xc0) == 0xc0)
    {
        return 2;
    }
    else if ((ch & 0x80) == 0x00)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
