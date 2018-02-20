#ifndef TREAT_TRAITS_INSPECT_H_
#define TREAT_TRAITS_INSPECT_H_

#include "../../trait/trait.h"

struct _TreatTraitsInspectStruct {
  TraitType trait;
  void (*inspect)(TraitObject *);
};
extern struct _TreatTraitsInspectStruct Inspect;

typedef struct {
  void (*inspect)(TraitObject *);
} InspectTraitImplementation;

#endif //TREAT_TRAITS_INSPECT_H_
