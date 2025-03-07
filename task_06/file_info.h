#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <sys/stat.h>

int print_info(const char *path);
void print_type(struct stat *file_stat);
void print_permissions(struct stat *file_stat);

#endif // FILE_INFO_H

