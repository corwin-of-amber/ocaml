#include <caml/mlvalues.h>
#include <caml/alloc.h>


__attribute__ ((used))
CAMLprim value re_string_match(value re, value str, value pos)
{
    return Atom(0);
    /*
    value res;
    res = caml_alloc(2, 0);

    Field(res, 0) = Val_int(-1);
    Field(res, 1) = Val_int(-1);

    return res;
    */
}

__attribute__ ((used))
CAMLprim value re_partial_match(value re, value str, value pos)
{
    return Atom(0);
}


__attribute__ ((used))
CAMLprim value re_search_forward(value re, value str, value startpos)
{
    return Atom(0);
}


__attribute__ ((used))
CAMLprim value re_search_backward(value re, value str, value startpos)
{
    return Atom(0);
}


__attribute__ ((used))
CAMLprim value re_replacement_text(value repl, value groups, value orig)
{
    return Atom(0);
}
    
