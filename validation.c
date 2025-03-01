//
// Created by debian on 2/25/25.
//
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "validation.h"

bool is_valid_filename(const char *filename, const size_t file_len)
{
    if (file_len < 2) return false;
    if (!strchr(filename, '.'))
    {
        return false;
    }
    else
    {
        size_t dot_pos = -1;
        for (size_t i = 0; i < file_len; i++)
        {
            if (filename[i] == '.')
            {
                if (dot_pos != -1)
                {
                    return false;
                }
                dot_pos = i;
            }
        }
        return true;
    }
}