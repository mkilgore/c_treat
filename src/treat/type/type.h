#ifndef TREAT_TYPE_H_
#define TREAT_TYPE_H_

#include <sys/types.h>
#include <stdarg.h>

#include "../hash_map/hash_map.h"

typedef struct _trait_object_base TraitObject;

/*
Any Treat Type struct needs to have a 'Type type' field
as first field in its struct, so it can be pointer-cast to this Type struct.
 */
typedef struct {
  size_t size;
  char const *name;
  void *(*ctor)(TraitObject *self, va_list *arguments);
  void *(*dtor)(TraitObject *self);
} Type;

struct _trait_object_base {
  const Type *type;
};

typedef struct {
  HashMap *implementations;
  char const *name;
} TraitType;

#endif //TREAT_TYPE_H_
