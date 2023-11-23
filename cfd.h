#pragma once

#ifndef CFD
#define CFD

// feature paths
typedef struct cfd_pf {
  bool is_cpt;
  union {
    struct cfd_pf *next;
    struct cfd_concept *cpt;
  };
} cfd_pf;

enum cfd_grammar_type {
  CONCEPT,
  RESTRICTION,
  NEGATION,
  CONJUNCTION,
  EQUALITY,
  PFD,
  PFD_KEY
};

// the root tagged struct (virtual)
typedef struct cfd_node {
  enum cfd_grammar_type type;
} cfd_node;

typedef struct cfd_concept {
  enum cfd_grammar_type type = CONCEPT;

  unsigned size;
  char *id;
} cfd_concept;

typedef struct cfd_restriction {
  enum cfd_grammar_type type = RESTRICTION;

  cfd_pf *path;
  cfd_concept *c;
} cfd_restriction;

typedef struct cfd_negation {
  enum cfd_grammar_type type = NEGATION;

  cfd_concept *c;
} cfd_negation;

typedef struct cfd_conjunction {
  enum cfd_grammar_type type = CONJUNCTION;

  cfd_node *lhs;
  cfd_node *rhs;
} cfd_conjunction;

typedef struct cfd_equality {
  enum cfd_grammar_type type = EQUALITY;

  cfd_pf *lhs;
  cfd_pf *rhs;
} cfd_equality;

typedef struct cfd_pfd {
  enum cfd_grammar_type type = PFD;

  cfd_node *concept;
  cfd_pf *rhs;
  unsigned lhs_size;
  cfd_pf **lhs;
} cfd_pfd;

typedef struct cfd_pfd_key {
  enum cfd_grammar_type type = PFD_KEY;

  cfd_node *concept;
  cfd_node *rhs;
  unsigned lhs_size;
  cfd_pf **lhs;
} cfd_pfd_key;

#endif // CFD
