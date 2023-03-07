#include "my_demangle.h"
//TODO: When this is comented, demagle compilation works. Have to review why
//#include "config.h"
#include <string.h>
#include <stdlib.h>
#if defined(HAVE_DEMANGLE_H)
#define HAVE_DECL_BASENAME 1
#include <demangle.h>
#elif defined(HAVE_LIBIBERTY_DEMANGLE_H)
#include <libiberty/demangle.h>
#endif

#if defined(HAVE_DEMANGLE_H) || defined(HAVE_LIBIBERTY_DEMANGLE_H)
char * my_demangle(const char * name) {
    return cplus_demangle(name, DMGL_AUTO);
}
#else
char * my_demangle(const char * name) {
  char *ret;
  if (!name)
    return NULL;
  ret = (char *)malloc(strlen(name)+1);
  if (!ret)
    return NULL;
  strcpy(ret, name);
  return ret;
}
#endif
