PT_Tree ATermReadFromNamedFile(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  char *filestr = PT_yieldTree(file_arg);
  filestr[strlen(filestr) - 1] = '\0';

  return PT_getParseTreeTree((PT_ParseTree) ATreadFromNamedFile(filestr+1));
}
