#ifndef CONTAINER_OF_TREAT_INSPECT_H
#define CONTAINER_OF_TREAT_INSPECT_H

struct inspect_impl;

struct inspect_ops {
    void (*inspect) (struct inspect_impl *);
};

struct inspect_impl {
    const struct inspect_ops *ops;
};

static inline void inspect(struct inspect_impl *impl)
{
    (impl->ops->inspect) (impl);
}

#endif
