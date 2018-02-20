#include "integer.ih"

void *Integer_ctor(TraitObject *_self, va_list *args) {
  TInteger *self = container_of(_self, TInteger, object);
  int integer = va_arg(*args, int);
  self->integer = integer;
  return self;
}
