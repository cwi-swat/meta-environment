#ifndef __EXTERNAL_STARTUP_H
#define __EXTERNAL_STARTUP_H

typedef void (*external_startup)(const char *filename,
				 int read_from_hive_fd,
				 int write_to_hive_fd);

void startup(const char *filename, int read_from_hive_fd, int write_to_hive_fd);

#endif /* __EXTERNAL_STARTUP_H */
