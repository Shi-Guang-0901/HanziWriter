#include "info.h"

SString open_faild;
SString open_exception;
SString symbol;


void init_string()
{
    create_string(&open_faild,"显示字样文件打开失败");
    create_string(&open_exception,"显示字样文件内容异常");
    create_string(&symbol,"■");
}

void convert_string()
{
    convert(&open_faild,open_faild,"UTF-8","GBK");
    convert(&open_exception,open_exception,"UTF-8","GBK");
    convert(&symbol,symbol,"UTF-8","GBK");
}

void clear_cache()
{
    clear_string(&open_faild);
    clear_string(&open_exception);
    clear_string(&symbol);
}
