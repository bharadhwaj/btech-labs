/* Data type for links in the chain of symbols.      */
struct symrec {
  char *name;  /* name of symbol                     */
  char type[32];
  int scope_depth;
  int depth_id;
  int intval;
  float floatval;
  char charval;
  struct symrec *next;    /* link field              */
};

typedef struct symrec symrec;

/* The symbol table: a chain of `struct symrec'.     */
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();
