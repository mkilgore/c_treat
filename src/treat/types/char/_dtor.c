#include "char.ih"

void *Char_dtor(TraitObject *_self) {
  TChar *self = container_of(_self, TChar, object);
  // no-op
  return self;
}
