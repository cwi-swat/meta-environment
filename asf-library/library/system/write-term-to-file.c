PT_Tree write_term_to_file(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree tree_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  char *filestr = NULL;

  filestr = PT_yieldTree(file_arg);

  if (filestr != NULL && strlen(filestr) > 2) {
    filestr[strlen(filestr) -1 ] = '\0';
    ATwriteToNamedTextFile(PT_TreeToTerm(tree_arg), filestr+1);
  }

  return tree_arg;
}

