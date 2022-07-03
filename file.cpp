#include "file.h"

/**
 *   @param parent 文件父目录
 *   @param filename 文件名
 *   @return 返回文件长度
 */
long long get_file_length(const SString parent, const SString filename)
{
    SString parent_file_name = {NULL, 0};
    get_integrated_filename(&parent_file_name, parent, filename);
    long long file_length = get_file_length(parent_file_name);
    clear_string(&parent_file_name);
    return file_length;
}

/**
 *   @param filename 文件完整路径
 *   @return 返回文件长度
 */
long long get_file_length(const SString filename)
{
    FILE *fp = NULL;
    long long length = 0;

    if ((fp = fopen(filename.values, "rb")) == NULL)
    {
        return -1;
    }
    else
    {
        fseeko64(fp, 0, SEEK_END);
        length = ftello64(fp);
        fseeko64(fp, 0, SEEK_SET);
    }
    fclose(fp);
    return length;
}
/**
 *   获得文件名数组
 *   @param parent 父目录的完整路径
 *   @param count 目录中文件的个数，传入指针
 *   @return 返回文件名数组
 *
 */
SString *get_files(const SString parent, int *count)
{

    int i = 0;
    DIR *dir = NULL;
    struct dirent *entry;

    if ((dir = opendir(parent.values)) == NULL)
    {
        return NULL;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        SString f_name = {NULL, 0};
        create_string(&f_name, entry->d_name);
        if ((!(strcmp(".", f_name.values) == 0 || strcmp("..", f_name.values) == 0)) && isFile(parent, f_name) == 1)
        {
            i++;
        }
        clear_string(&f_name);
    }
    *count = i; //获得了当前目录下我想要的文件的总个数
    seekdir(dir, 0);

    SString *file_list = (SString *)malloc(sizeof(SString) * i);
    int index = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        SString f_name = {NULL, 0};
        create_string(&f_name, entry->d_name);
        if ((!(strcmp(".", f_name.values) == 0 || strcmp("..", f_name.values) == 0)) && isFile(parent, f_name) == 1)
        {
            create_string(&file_list[index], f_name);
            index++;
        }
        clear_string(&f_name);
    }
    closedir(dir);
    return file_list;
}

/**
 *   判断一个路径是文件夹还是文件
 *   @param parent 父目录的完整路径
 *   @param filename 文件名或目录名
 *   @return 如果是文件返回TRUE(1), 如果是目录返回FALSE(0)
 *
 */
int isFile(const SString parent, const SString filename)
{
    SString parent_file_name = {NULL, 0};
    get_integrated_filename(&parent_file_name, parent, filename);

    return isFile(parent_file_name);
}

/**
 *   判断一个路径是文件夹还是文件
 *   @param filename 文件或目录的完整路径
 *   @return 如果是文件返回TRUE(1), 如果是目录返回FALSE(0)
 *
 */
int isFile(const SString filename)
{
    DIR *dir = NULL;
    if ((dir = opendir(filename.values)) == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 *  根据跟定的父路径和文件名生成完整路径名
 *  @param dest 完整路径存储数组
 *  @param path 父路径
 *  @param filename 文件名
 *  @return 如果是成功返回TRUE(1), 如果是失败返回FALSE(0)
 *
 */
int get_integrated_filename(SString *dest, const SString path, const SString filename)
{
    SString space = {NULL, 0}, backslash = {NULL, 0}, tempPath = {NULL, 0};
    create_string(&space, " ");
    create_string(&backslash, "\\");
    create_string(&tempPath, path);
    if (ends(tempPath, space) || ends(tempPath, backslash))
    {
        delete_string(&tempPath, tempPath.length - 1, 1);
    }

    if (isFile(tempPath))
    {
        clear_string(&space);
        clear_string(&backslash);
        clear_string(&tempPath);
        return 0;
    }
    concat_string(dest, tempPath, backslash);

    SString temp = {NULL, 0};
    create_string(&temp, *dest);

    concat_string(dest, temp, filename);

    clear_string(&temp);
    clear_string(&space);
    clear_string(&backslash);
    clear_string(&tempPath);

    return 1;
}
