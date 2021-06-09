#include "pystring.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long find(const pystring *self, const char *sub_str)
{
    const char *orig_str = self->cstring;
    char *found_string = strstr(orig_str, sub_str);

    if (found_string == NULL) {
        return -1;
    }

    return found_string - orig_str;
}

long rfind(const pystring *self, const char *sub_str)
{
    long max_index = -1;
    unsigned long sub_len = strlen(sub_str);
    const char *find_in = self->cstring;

    for (;;) {
        find_in = strstr(find_in, sub_str);
        if (find_in == NULL) {
            break;
        }
        max_index = find_in - self->cstring;
        find_in += sub_len;
    }

    return max_index;
}

pystring* pys_create(char *str)
{
    pystring *new_string = malloc(sizeof(pystring));
    new_string->cstring = str;
    new_string->size = strlen(str);
    new_string->find = find;
    new_string->rfind = rfind;

    return new_string;
}
