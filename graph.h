#pragma once

#ifndef GRAPH
#define GRAPH

#include "cfd.h"

typedef struct graph_node {
  cfd_node* ds; // concept descriptions
  cfd_pf* pf; // attribute descriptions
  char* fired; // subsumptions constraints that alr fired
};

typedef struct graph_edge {
  int from; // node idx
  cfd_pf* label; // either primitive attribute name or Id
  int to; // node idx
};


typedef struct desc_graph {
  graph_node* nodes;
  graph_edge* edges;
  int dst_node; // distinguished node
} desc_graph;

#endif
