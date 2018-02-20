#include "treat.ih"

void Treat_destroy(TraitObject *obj) {
  if(obj && obj->type && obj->type->dtor)
    obj = obj->type->dtor(obj);
  free(obj);
}
