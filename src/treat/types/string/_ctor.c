#include "string.ih"

void *String_ctor(TraitObject *_self, va_list *args) {
  TString *self = container_of(_self, TString, object);
  char const *string = va_arg(*args, char const *);

  size_t len = self->len = strlen(string);
  size_t capacity = self->capacity = next_pow_of_two(len + 1);
  self->str = safe_calloc(capacity, sizeof(char));
  memcpy(self->str, string, len + 1);

  return self;
}
