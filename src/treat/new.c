#include "treat.ih"

void *Treat_new(const Type *type, ...) {
  TraitObject *obj = safe_calloc(1, type->size);
  /* assert(obj); */

  obj->type = type;
  if(type->ctor) {
    va_list args;
    va_start(args, type);
    obj = type->ctor(obj, &args);
    va_end(args);
  }
  return obj;
}
