#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "treat/treat.h"

#include "treat/types/char/char.h"
#include "treat/types/string/string.h"
#include "treat/types/integer/integer.h"
#include "treat/with.macro"

int notmain(void);

int main(void) {
  Treat.init();

  T_with(TString * my_str, String.new("foo bar baz")) {
    Inspect.inspect(&my_str->object);
    String.concat_charptr(my_str, " qux");
    T_with(TString *other_str, String.new(" la la la")) {
      String.concat(my_str, other_str);
    }
    Inspect.inspect(&my_str->object);
  };

  T_with(TChar * baz, Char.new('b')) {
    Inspect.inspect(&baz->object);
    Inspect.inspect(&baz->object);

    TChar *foo = Char.new('a');
    TInteger *bar = Integer.new(1234);
    Inspect.inspect(&foo->object);
    Inspect.inspect(&bar->object);
    Char.destroy(foo);
    Integer.destroy(bar);

  };


  /* Call example2 */
  notmain();
}
