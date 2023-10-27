#ifndef INCLUSION
#define INCLUSION

/* check if input is a valid cfd */
bool is_cfd(cfd_inc_dep cfd);

/* add to LHS*/
void cfd_inclusion_tell();
/* determine logical consequence with input as RHS*/
bool cfd_inclusion_ask();
/* add to RHS*/
void cfd_inclusion_reset();

#endif
