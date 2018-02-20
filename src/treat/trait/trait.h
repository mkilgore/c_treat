#ifndef TREAT_TRAIT_H_
#define TREAT_TRAIT_H_

#include "../type/type.h"

// Module Interface:
struct _TreatTraitModule {
  void (*add_impl)(TraitType *trait, const Type *type, void *impl);
  void *(*impl_for)(const TraitType *trait, const Type *type);
};
extern struct _TreatTraitModule const Trait;

#endif //TREAT_TRAIT_H_
