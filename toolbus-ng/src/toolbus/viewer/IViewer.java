package toolbus.viewer;

import toolbus.process.ProcessInstance;

public interface IViewer{
	void updateState(int state);
	void update(ProcessInstance processInstance);
	void processInstanceAdded(ProcessInstance processInstance);
	void processInstanceTerminated(ProcessInstance processInstance);
	void breakPointHit(int processId);
	void start();
	void stop();
}
