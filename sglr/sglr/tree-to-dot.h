/*
  file: tree-to-dot.h
*/

void tree_to_dotfile(char *, term *, bool);
void stack_to_dotfile(stack *);
void stacks_to_dotfile(stacks *);
void link_to_dot(FILE *, stack *, st_link *);
void links_to_dot(FILE *, stack *);
