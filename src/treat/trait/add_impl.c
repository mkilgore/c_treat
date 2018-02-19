#include "trait.ih"

#include <stdio.h>

void Trait_add_impl(void *_trait, void *_type, void *impl){
  Type *type = _type;
  TraitType *trait = _trait;
  printf("Adding implementation of %s to %s\n", trait->name, type->name);
  HashMap_insert(&trait->implementations, type, impl);
}
