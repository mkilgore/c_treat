#include "char.ih"

void *Char_ctor(TraitObject *_self, va_list *args) {
  TChar *self = container_of(_self, TChar, object);
  char character = va_arg(*args, int);
  self->character = character;
  return self;
}
