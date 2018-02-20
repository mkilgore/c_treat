#include "../char.ih"
#include "../../../traits/inspect/inspect.h"

#include <stdio.h>

void Char_TraitImpls_Inspect_inspect(TraitObject *obj_ptr) {
  TChar *obj = container_of(obj_ptr, TChar, object);
  printf("TChar: {character: %c}\n", obj->character);
}

InspectTraitImplementation Char_TraitImpls_Inspect = {
  .inspect = &Char_TraitImpls_Inspect_inspect
};
