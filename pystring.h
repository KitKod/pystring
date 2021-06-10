#ifndef PYSTRING_PYSTRING_H
#define PYSTRING_PYSTRING_H

struct pystring {
    const char *cstring;
    unsigned long size;

    long (*find)(const struct pystring *self, const char *sub_str);
    long (*rfind)(const struct pystring *self, const char *sub_str);
    struct pystring* (*insert)(const struct pystring *self, unsigned long index, const char *sub_str);
    struct pystring* (*remove)(const struct pystring *self, unsigned long start_index, unsigned long end_index);
    struct pystring* (*replace)(const struct pystring *self, const char *old, const char *new, unsigned int count);
};

typedef struct pystring pystring;

pystring* pyscreate(char *str);

#endif //PYSTRING_PYSTRING_H
