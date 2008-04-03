#ifndef _TIFS_C
#define _TIFS_C

#include <aterm2.h>

ATermList read_tifs_from_named_file(const char *file, const char *tool);

ATermList extract_rec_from_tifs(ATermList tifs);
ATermList extract_tool_from_tifs(ATermList tifs, const char *tool);
const char* extract_toolname(ATermList tifs);

void write_tifs_to_named_file(ATermList tifs, const char *file);

ATermList generalize_tifs(ATermList tifs);
ATermList unify_tifs(ATermList tifs);

#endif /* _TIFS_C */
