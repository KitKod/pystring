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

struct pystring* insert(const pystring *self, unsigned long index, const char *sub_str)
{
    char *result_str = calloc((self->size + strlen(sub_str) + 1), sizeof(char));

    if (result_str == NULL) {
        return NULL;
    }

    strncat(result_str, self->cstring, index);
    strcat(result_str, sub_str);
    strcat(result_str, &self->cstring[index]);

    return pyscreate(result_str);
}

/* TODO: after insert and remove implementation.
pystring* replace(const struct pystring *self, const char *old, const char *new, unsigned int count)
{
    char *template = malloc(sizeof(char) * (self->size + 1));
    strcpy(template, self->cstring);

    for (;;) {



        break;
    }


    return NULL;
}
*/

pystring* pyscreate(char *str)
{
    pystring *new_string = malloc(sizeof(pystring));
    if (new_string != NULL) {
        new_string->cstring = str;
        new_string->size = strlen(str);
        new_string->find = find;
        new_string->rfind = rfind;
        new_string->insert = insert;
    }

    return new_string;
}
