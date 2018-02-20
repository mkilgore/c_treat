#include "char.ih"

TChar *Char_new(char character) {
  TChar *obj = Treat.new(&Char.type, character);
  obj->character = character;

  return obj;
}
