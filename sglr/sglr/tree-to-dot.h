/*
  file: tree-to-dot.h
*/

void tree_to_dotfile(char *, term *, bool);
void stacks_to_dotfile(stack *);
/* void stack_to_dotfile_end(); */
void link_to_dot(FILE *, stack *, st_link *);
void links_to_dot(FILE *, stack *);
