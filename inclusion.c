#include <stdlib.h>
#include "inclusion.h"
#include "graph.h"

#define DEFAULT_ARR_SZ 8

/* add an inclusion dependency to the terminology T*/
void cfd_inclusion_tell(cfd_inc_deps* cur_deps, cfd_inc_dep new_dep) {
  if (cur_deps->capacity == cur_deps->size) {
    cur_deps->capacity *= 2;
    cur_deps->deps = realloc(cur_deps->deps, cur_deps->capacity * sizeof(cfd_inc_dep));
  }
  cur_deps->deps[cur_deps->size] = new_dep;
  cur_deps->size++;
}
/* determine logical consequence, if all As are D1s then all As are D2s*/
bool cfd_inclusion_ask(cfd_inc_deps* cur_deps, cfd_inc_dep rhs) {
  desc_graph g = {
  .nodes_sz = DEFAULT_ARR_SZ,
  .nodes = malloc(DEFAULT_ARR_SZ * sizeof(graph_node)),
  .edges_sz = DEFAULT_ARR_SZ,
  .edges = malloc(DEFAULT_ARR_SZ * sizeof(graph_edge)),
  .dst_node = 0
  };

  /* @TODO: Finish init */
  g.nodes[0].ds = NULL;
  g.nodes[0].pf = NULL;
  g.nodes[0].fired = NULL;

  exp(&g, cur_deps);
  
  return subsumes(*rhs.rhs, &g, cur_deps, *rhs.lhs, true);
}
/* clear terminology T*/
void cfd_inclusion_reset(cfd_inc_deps* cur_deps) {
  cur_deps->size = 0;
}