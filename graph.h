#pragma once

#ifndef GRAPH
#define GRAPH

typedef struct graph_node {
  char* ds; // concept descriptions
  char* pf; // attribute descriptions
  char* fired; // subsumptions constraints that alr fired
};

typedef struct graph_edge {
  int from; // node idx
  char* label; // either primitive attribute name or Id
  int to; // node idx
};


typedef struct desc_graph {
  graph_node* nodes;
  graph_edge* edges;
  int dst_node; // distinguished node
} desc_graph;

#endif
