#ifndef __TEXT_CONNECTOR_H
#define __TEXT_CONNECTOR_H

#include <TextEditor.h>

typedef struct _TextEditor *TextEditor;

typedef void (*move_to_front_t)(int write_to_editor_fd);
typedef void (*clear_focus_t)(int write_to_editor_fd);
typedef void (*reread_contents_t)(int write_to_editor_fd);
typedef void (*hive_closed_t)(int write_to_editor_fd);
typedef void (*display_message_t)(int write_to_editor_fd, TE_Action);
typedef void (*set_cursor_at_location_t)(int write_to_editor_fd, TE_Action);
typedef void (*set_cursor_at_focus_t)(int write_to_editor_fd, TE_Action);
typedef void (*set_actions_t)(int write_to_editor_fd, TE_Action);
typedef void (*set_focus_t)(int write_to_editor_fd, TE_Action);
typedef void (*get_contents)(int write_to_hive_fd, TE_Action);

TextEditor initTextEditor(hive_closed_t,
			  clear_focus_t,
			  move_to_front_t,
			  reread_contents_t,
			  display_message_t,
			  set_cursor_at_location_t,
			  set_cursor_at_focus_t,
			  set_actions_t,
			  set_focus_t,
			  get_contents);

int eventloop(TextEditor editor, TE_Pipe hiveToEditor, TE_Pipe editorToHive);

void sendToHive(int write_to_hive_fd, TE_Event event);

#endif /* __TEXT_CONNECTOR_H */
