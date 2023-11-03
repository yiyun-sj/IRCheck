#pragma once

#ifndef INCLUSION
#define INCLUSION

/* check if input is a valid cfd */
#include "cfd.h"
#include "stdbool.h"

/* add an inclusion dependency to the terminology T*/
void cfd_inclusion_tell(cfd_inc_dep inc_dep);
/* determine logical consequence, if all As are D1s then all As are D2s*/
bool cfd_inclusion_ask(cfd_concept a, cfd_concept d1, cfd_concept d2);
/* clear terminology T*/
void cfd_inclusion_reset();

#endif
