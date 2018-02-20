#include "integer.ih"

TInteger *Integer_new(int integer) {
  TInteger *obj = Treat.new(&Integer.type, integer);
  obj->integer = integer;

  return obj;
}

