//
// Created by debian on 3/19/25.
//

#include "xor_encryption.h"
struct Data { int id; double value; };
FILE* encrypt_with_xor(FILE* file)
{
    //testing with custom data
    struct Data d;
    char text[300];
    char *c = text;
    printf("%s", "Enter text: ");
    scanf("%s", text);
    while (*c)
    {
        *c ^= 'd';
        ++c;
    }
    printf("%s", text);
    return file;
}
