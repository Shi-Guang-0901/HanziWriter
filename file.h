#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <dirent.h>
#include "sstring.h"

long long get_file_length(const SString filename);

long long get_file_length(const SString parent, const SString filename);

SString *get_files(const SString parent, int *count);

int isFile(const SString parent, const SString filename);

int isFile(const SString filename);

int get_integrated_filename(SString *dest, SString path, const SString filename);

#endif // COMMON_H_INCLUDED
