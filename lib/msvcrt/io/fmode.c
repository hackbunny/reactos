/* Copyright (C) 1994 DJ Delorie, see COPYING.DJ for details */
#include <msvcrti.h>


#undef _fmode
unsigned int _fmode = O_TEXT;

unsigned int *__p__fmode(void)
{
   return &_fmode;
}
