#ifndef __MONITOR_H__
#define __MONITOR_H__

typedef enum mon_method {none, logger, viewer, controller} mon_method;
extern mon_method monitoring;

void set_monitoring(mon_method);
tool_id *init_monitoring(void);

atom *mk_snd_monitor(term *, atom *, proc *, proc_inst *, proc_inst *);

#endif  /*  __MONITOR_H__ */
