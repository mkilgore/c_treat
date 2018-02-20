#include "inspect.ih"

void Inspect_inspect(TraitObject *obj) {
  void *_res = Trait.impl_for(&Inspect.trait, obj->type);
  InspectTraitImplementation *res = _res;
  /* void (*res)(void *) = _res; */
  res->inspect(obj);
}
