#include "../string.ih"
#include "../../../traits/inspect/inspect.h"

#include <stdio.h>

void String_TraitImpls_Inspect_inspect(TraitObject *obj_ptr) {
  TString *obj = container_of(obj_ptr, TString, object);
  printf("TString: {str: \"%s\"}\n", obj->str);
}

InspectTraitImplementation String_TraitImpls_Inspect = {
  .inspect = &String_TraitImpls_Inspect_inspect
};
