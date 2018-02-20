#include "treat.ih"

#include "traits/inspect/inspect.h"
#include "types/char/char.h"
#include "types/string/string.h"
#include "types/integer/integer.h"

#include <stdarg.h>


void Treat_deinit();
void Treat_init() {
  Inspect.trait.implementations = HashMap_new(2);
  Trait.add_impl(&Inspect.trait, &Char.type, &Char_TraitImpls_Inspect);
  Trait.add_impl(&Inspect.trait, &String.type, &String_TraitImpls_Inspect);
  Trait.add_impl(&Inspect.trait, &Integer.type, &Integer_TraitImpls_Inspect);

  atexit(&Treat_deinit);
}

void Treat_deinit() {
    HashMap_destroy(Inspect.trait.implementations);
}
