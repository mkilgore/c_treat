#include "../integer.ih"
#include "../../../traits/inspect/inspect.h"

#include <stdio.h>

void Integer_TraitImpls_Inspect_inspect(TraitObject *obj_ptr) {
  TInteger *obj = container_of(obj_ptr, TInteger, object);
  printf("TInteger: {integer: %d}\n", obj->integer);
}

InspectTraitImplementation Integer_TraitImpls_Inspect = {
  .inspect = &Integer_TraitImpls_Inspect_inspect
};
