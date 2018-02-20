#include "trait.ih"

#include <stdio.h>

void Trait_add_impl(TraitType *trait, const Type *type, void *impl){
  printf("Adding implementation of %s to %s\n", trait->name, type->name);
  HashMap_insert(&trait->implementations, type, impl);
}
