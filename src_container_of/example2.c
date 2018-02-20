
#include "treat/treat.h"
#include "treat/char.h"
#include "treat/tstring.h"

int notmain(void)
{
    struct tstring tstr;

    tstring_init_cstr(&tstr, "This is a test!");
    inspect(&tstr.inspect);

    tstring_concat_charptr(&tstr, " And this is concat!");
    inspect(&tstr.inspect);

    treat_object_clear(&tstr.tobj);

    return 0;
}

