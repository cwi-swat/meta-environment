package metastudio.components;

import java.io.IOException;
import java.net.UnknownHostException;

import aterm.ATerm;
import aterm.ATermFactory;

public class TideControl extends tide.TideControl implements Runnable {
	public TideControl(ATermFactory factory, String[] args) throws IOException {
		super(factory, args);
	}

	protected void connectTideControl(String[] args) {
			try {
				getBridge().init(args);
				getBridge().setLockObject(this);
				getBridge().connect("tide-control", null, -1);
			} catch (UnknownHostException e) {
				// TODO Auto-generated catch block
			} catch (IOException e) {
				// TODO Auto-generated catch block
			}
			
	}

	public void run() {
		getBridge().run();
	}

	public void recTerminate(ATerm arg) {
		stopChildThreads();
	}

}
