#include "libwelcome.h"
#include <stdio.h>

EXPORT void welcome(void) {
  printf("Hello!\n");
}

EXPORT int welcome(char *x) {
  if(x && *x) {
    printf("Hello %s\n", x);
    return 1;
  }
  return 0;
}