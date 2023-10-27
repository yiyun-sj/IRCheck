#ifndef CFD
#define CFD

// feature paths
struct cfd_pf {
  struct cfd_pf *next;
  char id[];
};

// inclusion dependency
struct cfd_inc_dep {
  int LHS;
  int RHS;
};

enum cfd_grammar_type {CONCEPT, RESTRICTION, NEGATION, CONJUNCTION, EQUALITY, PFD, PFD_KEY};

struct cfd_concepts {
  cfd_grammar_type type;
  char concept[];
};

struct cfd_restriction {
  cfd_grammar_type type;
  void * child;
  cfd_pf path;
};

struct cfd_negation {
  cfd_grammar_type type;
  char concept[];
};

struct cfd_conjunction {
  cfd_grammar_type type;
  void * lhs;
  void * rhs;
};

struct cfd_equality {
  cfd_grammar_type type;
  void * lhs;
  void * rhs;
};

struct cfd_pfd {
  cfd_grammar_type type;
  void * concept;
  void * lhs;
  void * rhs;
};

struct cfd_pfd_key {
  cfd_grammar_type type;
  void * concept;
  void * lhs;
  void * rhs;
};

// consolidate overall struct later
struct cfd_grammar {
  
};



#endif
