PT_Tree warning(ATerm builtin, PT_Tree input)
{
  ATwarning("%s", PT_yieldTree(input));

  return input;
}
