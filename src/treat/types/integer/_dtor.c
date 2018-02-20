#include "integer.ih"

void *Integer_dtor(TraitObject *_self) {
  TInteger *self = container_of(_self, TInteger, object);
  // no-op
  return &self->object;
}
