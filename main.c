#include <stdlib.h>
#include "cfd.h"

#define DEFAULT_ARR_SZ 8

int main() {
  cfd_inc_deps inc_deps = {
    .deps = malloc(DEFAULT_ARR_SZ * sizeof(cfd_inc_dep)),
    .size = 0,
    .capacity = DEFAULT_ARR_SZ
  };
}