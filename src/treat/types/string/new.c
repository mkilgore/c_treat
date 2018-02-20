#include "string.ih"

TString *String_new(char const *str) {
  TString *obj = Treat.new(&String.type, str);
  return obj;
}
