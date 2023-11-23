#pragma once

#ifndef GRAPH
#define GRAPH

#include "cfd.h"

typedef struct graph_node {
  cfd_node* ds; // concept descriptions
  cfd_pf* pf; // attribute descriptions
  cfd_inc_dep* fired; // subsumptions constraints that alr fired
};

typedef struct graph_edge {
  int from; // node idx
  cfd_pf* label; // either primitive attribute name or Id
  int to; // node idx
};


typedef struct desc_graph {
  unsigned nodes_sz;
  graph_node* nodes;
  unsigned edges_sz;
  graph_edge* edges;
  int dst_node = 0; // distinguished node
} desc_graph;

#endif
