#include <stdio.h>
#include <ftw.h>
#include "../include/utils.h"

int draw_tree(char *path)
{
    ftw(path, callback, 100);

    return 0;
}

int callback(const char *path, const struct stat *, int filetype)
{
    file_info_t *fileinfo = get_file_info(path);
    switch (filetype)
    {
    case FTW_F:
        print_filename(fileinfo->filename, fileinfo->level);
        break;
    case FTW_D:
        print_dirname(fileinfo->filename, fileinfo->level);
        break;
    default:
        print_filename(fileinfo->filename, fileinfo->level);
        break;
    }

    free_file_info(fileinfo);
    return 0;
}

file_info_t *get_file_info(const char *path)
{
    static bool first = true;
    static int parent_level = 0;
    char *_path = strcpy(malloc(strlen(path) + 1), path);
    if (!_path)
    {
        throw("Buy more RAM!!!");
    }
    file_info_t *fileinfo = (file_info_t *)malloc(sizeof(file_info_t));

    if (!fileinfo)
    {
        throw("Buy more RAM!!!");
    }

    if (first)
    {
        first = false;
        fileinfo->parent = true;
    }
    else
    {
        fileinfo->parent = false;
    }
    fileinfo->level = 0;
    fileinfo->filename = _path;

    char *token;

    token = strtok(_path, "/\\");

    while (token != NULL)
    {
        char *buff;

        buff = malloc(strlen(token) + 1);
        if (!buff)
        {
            throw("Buy more RAM!!!");
        }

        if (fileinfo->filename && strcmp(fileinfo->filename, _path) != 0)
            free(fileinfo->filename);
        fileinfo->filename = strcpy(buff, token);
        fileinfo->level += 1;
        token = strtok(NULL, "/\\");
    }
    fileinfo->level -= 1;

    if (fileinfo->parent)
    {
        parent_level = fileinfo->level;
    }
    fileinfo->level -= parent_level;

    return fileinfo;
}

void free_file_info(file_info_t *fileinfo)
{
    free(fileinfo->filename);
    free(fileinfo);
}

void print_filename(const char *filename, int level)
{
    int padding_total_length = (level - 1) * PADDING_LENGTH;
    char *padding = malloc(padding_total_length + 1);

    for (int i = 0; i < padding_total_length; i += PADDING_LENGTH)
    {
        strcpy(padding + i, PADDING_STRING);
    }

    padding[padding_total_length] = '\0';

    printf("%s%s%s\n", padding, "└── ", filename);

    free(padding);
    return;
}

void print_dirname(const char *filename, int level)
{
    if (level <= 0)
    {
        printf("%s/\n", filename);
        return;
    }
    int padding_total_length = (level - 1) * PADDING_LENGTH;
    char *padding = malloc(padding_total_length + 1);

    for (int i = 0; i < padding_total_length; i += PADDING_LENGTH)
    {
        strcpy(padding + i, PADDING_STRING);
    }

    padding[padding_total_length] = '\0';

    printf("%s%s%s/\n", padding, "├── ", filename);

    free(padding);
    return;
}