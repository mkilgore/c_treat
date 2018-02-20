#ifndef CONTAINER_OF_TREAT_TREAT_H
#define CONTAINER_OF_TREAT_TREAT_H

struct treat_object;

struct treat_ops {
    void (*clear) (struct treat_object *);
};

struct treat_object {
    const struct treat_ops *ops;
};

static inline void treat_object_clear(struct treat_object *tobj)
{
    (tobj->ops->clear) (tobj);
}

#endif
