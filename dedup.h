#ifndef DEDUP
#define DEDUP

#include <string>

struct dedup_as {};
struct dedup_equal {};
struct dedup_from {};
struct dedup_select {};
struct dedup_elim {};

struct Interpretation {};

void dedup_query_to_concept();
void dedup_eval(std::string query, Interpretation interp);

#endif

/*
NOTES (slide deck):

TOPIC: eliminate operations that remove duplicates

STRATEGY: query rewriting (?)
* Capture schema in CFD
  ? convert create table w/ constraints to CFD?
* rewrite to remove distinct in a (range restricted) query (replace w/ elim)
  * then rewrite again to remove elim as well (?)
* Query evaluation with EVAL(Q, I) ?

INDEX:
* CFD & DLF: feature based description logic families
  * has a polynomial-time decidable algorithm
  * Pf: feature paths; either Id or F_1, \cdot, F_n


*/
