#pragma once

#ifndef CFD
#define CFD

enum cfd_grammar_type {
  CONCEPT,
  RESTRICTION,
  NEGATION,
  CONJUNCTION,
  EQUALITY,
  PFD,
  PFD_KEY
};

// the root tagged struct
typedef struct cfd_node {
  enum cfd_grammar_type type;
} cfd_node;

typedef struct cfd_concept {
  enum cfd_grammar_type type;

  unsigned size;
  char *id;
} cfd_concept;

// feature paths
typedef struct cfd_pf {
  enum cfd_grammar_type type;

  struct cfd_pf *next;
  cfd_concept *concept;
} cfd_pf;

// inclusion dependency
typedef struct cfd_inc_dep {
  enum cfd_grammar_type type;

  cfd_node *lhs;
  cfd_node *rhs;
} cfd_inc_dep;

typedef struct cfd_restriction {
  enum cfd_grammar_type type;

  cfd_concept *c;
  cfd_pf *path;
} cfd_restriction;

typedef struct cfd_negation {
  enum cfd_grammar_type type;

  cfd_concept *c;
} cfd_negation;

typedef struct cfd_conjunction {
  enum cfd_grammar_type type;

  cfd_concept *lhs;
  cfd_concept *rhs;
} cfd_conjunction;

typedef struct cfd_equality {
  enum cfd_grammar_type type;

  cfd_pf *lhs;
  cfd_pf *rhs;
} cfd_equality;

typedef struct cfd_pfd {
  enum cfd_grammar_type type;

  cfd_node *concept;
  cfd_pf *rhs;
  unsigned lhs_size;
  cfd_pf *lhs;
} cfd_pfd;

typedef struct cfd_pfd_key {
  enum cfd_grammar_type type;

  cfd_node *concept;
  cfd_node *rhs;
  unsigned lhs_size;
  cfd_pf *lhs;
} cfd_pfd_key;

#endif // CFD
