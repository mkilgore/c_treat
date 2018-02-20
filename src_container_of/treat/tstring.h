#ifndef CONTAINER_OF_TREAT_TSTRING_H
#define CONTAINER_OF_TREAT_TSTRING_H

#include <stdlib.h>
#include <string.h>
#include "treat.h"
#include "inspect.h"

struct tstring;

struct tstring_ops {
    struct tstring *(*concat_charptr) (struct tstring *left, const char *right);
    struct tstring *(*concat) (struct tstring *left, const struct tstring *right);
};

struct tstring {
    char *str;
    size_t len;
    size_t capacity;
    struct treat_object tobj;
    struct inspect_impl inspect;
    const struct tstring_ops *ops;
};

extern const struct treat_ops   tstring_treat_ops;
extern const struct inspect_ops tstring_inspect_ops;
extern const struct tstring_ops tstring_default_ops;

#define TSTRING_INIT() \
    { \
        .tobj.ops = &tstring_treat_ops, \
        .inspect.ops = &tstring_inspect_ops, \
        .ops = &tstring_default_ops, \
    }

static inline void tstring_init(struct tstring *obj)
{
    *obj = (struct tstring)TSTRING_INIT();
}

static inline void tstring_init_cstr(struct tstring *obj, const char *cstr)
{
    *obj = (struct tstring)TSTRING_INIT();
    obj->str = strdup(cstr);
    obj->len = strlen(obj->str);
    obj->capacity = obj->len;
}

static inline struct tstring *tstring_concat_charptr(struct tstring *left, const char *right)
{
    return (left->ops->concat_charptr) (left, right);
}

static inline struct tstring *tstring_concat(struct tstring *left, const struct tstring *right)
{
    return (left->ops->concat) (left, right);
}

#endif
