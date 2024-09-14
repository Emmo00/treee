#ifndef UTILS_H
#define UTILS_H

#include <ftw.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// struct to store file data
typedef struct file_info_s
{
    int level; // directory depth
    char *filename;
    bool parent;
} file_info_t;

void print_filename(const char *path, int levels);
void print_dirname(const char *path, int levels);
int callback(const char *path, const struct stat *, int filetype);
int draw_tree(char *path);
file_info_t *get_file_info(const char *path);
void free_file_info(file_info_t *fileinfo);

void throw(char *message);

#define PADDING_LENGTH 6
#define PADDING_STRING "│     "

#endif // UTILS_H
