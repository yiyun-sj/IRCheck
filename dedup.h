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
