PT_Tree ATermWriteToNamedTextFile(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  char *filestr = PT_yieldTree(file_arg);
  PT_Tree term_arg =  PT_getArgsArgumentAt(PT_getTreeArgs(input),6);
  filestr[strlen(filestr)] = '\0';
  
  return (PT_Tree) ATwriteToNamedTextFile((ATerm) term_arg, filestr+1);

  return term_arg;
}
