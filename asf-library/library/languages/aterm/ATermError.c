PT_Tree ATermError(ATerm builtin, PT_Tree input)
{
  PT_Tree arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  ATerror("%s\n", PT_yieldTree(arg));

  return arg;
}
