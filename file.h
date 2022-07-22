#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <dirent.h>
#include "sstring.h"

long long get_file_length(const SString filename);

long long get_file_length(const SString parent, const SString filename);

SString *get_files(const SString parent, int *count);

int isFile(const SString parent, const SString filename);

int isFile(const SString filename);


/**
 *  根据跟定的父路径和文件名生成完整路径名
 *  @param dest 完整路径存储数组
 *  @param path 父路径
 *  @param filename 文件名
 *  @return 如果是成功返回TRUE(1), 如果是失败返回FALSE(0)
 *
 */
int get_integrated_filename(SString *dest, SString path, const SString filename);

#endif // COMMON_H_INCLUDED
