
#include "container_of.h"
#include <stdio.h>
#include "char.h"

static void char_inspect(struct inspect_impl *impl)
{
    struct char_obj *obj = container_of(impl, struct char_obj, inspect);
    printf("Char: { c: '%c' }\n", obj->c);
}

static void char_clear(struct treat_object *obj)
{

}

const struct treat_ops char_treat_ops = {
    .clear = char_clear,
};

const struct inspect_ops char_obj_inspect_ops = {
    .inspect = char_inspect,
};

