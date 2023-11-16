#pragma once

#ifndef INCLUSION
#define INCLUSION

/* check if input is a valid cfd */
#include "cfd.h"
#include "stdbool.h"
#include "graph.h"

// inclusion dependency
typedef struct cfd_inc_dep {
  cfd_node *lhs;
  cfd_node *rhs;
} cfd_inc_dep;

/* add an inclusion dependency to the terminology T*/
void cfd_inclusion_tell(cfd_inc_dep inc_dep);
/* determine logical consequence, if all As are D1s then all As are D2s*/
bool cfd_inclusion_ask(cfd_concept a, cfd_concept d1, cfd_concept d2);
/* clear terminology T*/
void cfd_inclusion_reset();

/* Helper Functions for ASK */
/* SUBSUMES
 *   (S U {c1 < d1} |= c2 < d2) 
 *      <=iff=> 
 *   subsumes(d2, exp(G:({n},{},n), S U {c1 < d1}), S U {c1 < d1}, c2, true)
 */
bool subsumes(cfd_node d2, desc_graph* g, void* constraints, cfd_node c2, bool t);
void exp(desc_graph g, void* constraints);

/* Helper Functions for SUBSUMES/EXP */

/* find: Returns the node at the end of the path Pf from a node n in G, potentially creating
 * any missing nodes and edges to ensure such a path exists */
cfd_node* g_find(int n_idx, cfd_pf pf, desc_graph* g); // could return an int for node idx instead

/* agrees: Returns true if there is a node n0 ∈ G such that n0 is reachable from both n1 and n2
 * by the same prefix of Pf */
bool agrees(int n1, cfd_pf pf, int n2, desc_graph g);

/* accepts: Returns true if Id occurs in the PF label of any node on the Pf path starting from
 * node n1 in G */
bool accepts(int n1, cfd_pf pf, desc_graph g);

#endif
