#include <caml/mlvalues.h>

#ifdef CAMLprim
#undef CAMLprim
#endif

#define CAMLprim __attribute__((used))
#define STUB { __wasi_trace("systhreads stub"); return Atom(0); }

CAMLprim value caml_thread_initialize(value unit)            STUB
CAMLprim value caml_thread_cleanup(value unit)               STUB
CAMLprim value caml_thread_new(value clos)                   STUB
CAMLprim value caml_thread_self(value unit)                  STUB
CAMLprim value caml_thread_id(value th)                      STUB
CAMLprim value caml_thread_uncaught_exception(value exn)     STUB
CAMLprim value caml_thread_exit(value unit)                  STUB
CAMLprim value caml_thread_yield(value unit)                 STUB
CAMLprim value caml_thread_join(value th)                    STUB
CAMLprim value caml_mutex_new(value unit)                    STUB
CAMLprim value caml_mutex_lock(value wrapper)                STUB
CAMLprim value caml_mutex_unlock(value wrapper)              STUB
CAMLprim value caml_mutex_try_lock(value wrapper)            STUB
CAMLprim value caml_condition_new(value unit)                STUB
CAMLprim value caml_condition_wait(value wcond, value wmut)  STUB
CAMLprim value caml_condition_signal(value wrapper)          STUB
CAMLprim value caml_condition_broadcast(value wrapper)       STUB

CAMLprim value caml_thread_sigmask(value cmd, value sigs)    STUB
CAMLprim value caml_wait_signal(value sigs)                  STUB

