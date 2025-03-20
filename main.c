#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "validation.h"
#include "xor_encryption.h"

int main(void)
{
    FILE *urandom = fopen("/dev/urandom", "r");
    FILE *unencrypted_file;

    size_t path_len = 256;
    char path_to_file[path_len];


    printf( "Enter name of the file: ");
    fgets(path_to_file , sizeof(path_to_file),  stdin);
    path_len = strlen(path_to_file);

    if (path_to_file[path_len - 1] == '\n')
    {
        path_to_file[path_len - 1] = '\0';
    }
    while (!is_valid_filename(path_to_file, path_len))
    {
        printf( "Invalid format - {%s}, enter again: ", path_to_file);
        fgets(path_to_file , sizeof(path_to_file),  stdin);
        path_len = strlen(path_to_file);
        if (path_to_file[path_len - 1] == '\n')
        {
            path_to_file[path_len - 1] = '\0';
        }
        path_len = strlen(path_to_file);
    }

    unencrypted_file = fopen(path_to_file, "r+");
    while (unencrypted_file == NULL)
    {
        printf("Filename: %s\n", path_to_file);
        printf("File - {%s} not found, enter again: ", path_to_file);
        fgets(path_to_file , sizeof(path_to_file),  stdin);
        path_len = strlen(path_to_file);
        unencrypted_file = fopen(path_to_file, "r+");
    }
    encrypt_with_xor(unencrypted_file);

    printf("Filename: %s\n", path_to_file);
    return 0;
}
