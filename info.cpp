#include "info.h"

SString open_faild;
SString open_exception;
SString signal;


void init_string()
{
    create_string(&open_faild,"显示字样文件打开失败");
    create_string(&open_exception,"显示字样文件内容异常");
    create_string(&signal,"■");
}

void convert_string()
{
    convert(&open_faild,open_faild,"UTF-8","GBK");
    convert(&open_exception,open_exception,"UTF-8","GBK");
    convert(&signal,signal,"UTF-8","GBK");
}

void clear_cache()
{
    clear_string(&open_faild);
    clear_string(&open_exception);
    clear_string(&signal);
}
