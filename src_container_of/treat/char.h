#ifndef CONTAINER_OF_TREAT_CHAR_H
#define CONTAINER_OF_TREAT_CHAR_H

#include "treat.h"
#include "inspect.h"

struct char_obj {
    char c;
    struct treat_object tobj;
    struct inspect_impl inspect;
};

extern const struct treat_ops   char_treat_ops;
extern const struct inspect_ops char_obj_inspect_ops;

#define CHAR_OBJ_INIT() \
    { \
        .tobj.ops = &char_treat_ops, \
        .inspect.ops = &char_obj_inspect_ops, \
    }

static inline void char_obj_init(struct char_obj *obj)
{
    *obj = (struct char_obj)CHAR_OBJ_INIT();
}

#endif
