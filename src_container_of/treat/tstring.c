
#include "container_of.h"
#include <stdio.h>
#include "inspect.h"
#include "tstring.h"

/* This is a hack, because I'm a bit lazy.
 * This function is defined over in the code for the other trait stuff */
size_t next_pow_of_two(size_t);

static struct tstring *tstring_ops_concat_charptr(struct tstring *left, const char *right)
{
  size_t right_len = strlen(right);
  size_t new_len = left->len + right_len;

  if(left->capacity < new_len + 1) {
    left->capacity = next_pow_of_two(new_len + 1);
    left->str = realloc(left->str, left->capacity);
  }
  memcpy(left->str + left->len, right, right_len + 1);
  left->len = new_len;
  return left;
}

static struct tstring *tstring_ops_concat(struct tstring *left, const struct tstring *right)
{
  size_t new_len = left->len + right->len;

  if(left->capacity < new_len + 1) {
    left->capacity = next_pow_of_two(new_len + 1);
    left->str = realloc(left->str, left->capacity);
  }
  memcpy(left->str + left->len, right->str, right->len + 1);
  left->len = new_len;
  return left;
}

static void tstring_inspect(struct inspect_impl *impl)
{
    struct tstring *tstring = container_of(impl, struct tstring, inspect);
    printf("TString: { str: \"%s\" }\n", tstring->str);
}

static void tstring_clear(struct treat_object *tobj)
{
    struct tstring *tstring = container_of(tobj, struct tstring, tobj);
    free(tstring->str);
}

const struct treat_ops tstring_treat_ops = {
    .clear = tstring_clear,
};

const struct inspect_ops tstring_inspect_ops = {
    .inspect = tstring_inspect,
};

const struct tstring_ops tstring_default_ops = {
    .concat = tstring_ops_concat,
    .concat_charptr = tstring_ops_concat_charptr,
};

