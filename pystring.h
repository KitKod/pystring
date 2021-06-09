#ifndef PYSTRING_PYSTRING_H
#define PYSTRING_PYSTRING_H

struct pystring {
    const char *cstring;
    unsigned long size;

    long (*find)(const struct pystring *self, const char *sub_str);
    long (*rfind)(const struct pystring *self, const char *sub_str);
};

typedef struct pystring pystring;

pystring* pys_create(char *str);

#endif //PYSTRING_PYSTRING_H
