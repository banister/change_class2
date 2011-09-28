/* (c) 2011 John Mair (banisterfiend), MIT license */

#include <ruby.h>
#include "compat.h"

static VALUE
rb_change_class(VALUE self, VALUE klass)
{
  VALUE actual_class = KLASS_OF(self);;
  VALUE cl;

  if (TYPE(klass) != T_CLASS)
    rb_raise(rb_eArgError, "Must provide a class.");

  cl = actual_class;

  if (cl == rb_class_real(cl))
    KLASS_OF(self) = klass;
  else {
    while ((RBASIC(RCLASS_SUPER(cl))->flags & FL_SINGLETON) || BUILTIN_TYPE(RCLASS_SUPER(cl)) == T_ICLASS)
      cl = RCLASS_SUPER(cl);

    RCLASS_SUPER(cl) = klass;
  }

  rb_clear_cache();

  return klass;
}

void
Init_change_class()
{
  rb_define_method(rb_cObject, "change_class", rb_change_class, 1);
}
