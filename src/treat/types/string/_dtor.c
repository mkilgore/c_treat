#include "string.ih"

#include <stdio.h>

void *String_dtor(TraitObject *_self) {
  TString *self = container_of(_self, TString, object);

  free(self->str);

  return self;
}
