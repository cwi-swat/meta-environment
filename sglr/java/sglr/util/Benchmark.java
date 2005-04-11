/*
 * Created on Dec 1, 2004
 *
 */
package sglr.util;

public class Benchmark {
	private long millisecs;
	
	public Benchmark() {
		millisecs = System.currentTimeMillis();
	}
	
	public Benchmark(long msecs) {
		millisecs = msecs;
	}
	
	public long getMilliSecs() {
		return millisecs;
	}
	
	public void add(Benchmark b) {
		millisecs += b.getMilliSecs();
	}
	
	public Benchmark diff(Benchmark b) {
		return new Benchmark(millisecs - b.getMilliSecs());
	}
	
	public String toString() {
		return String.valueOf(((float) millisecs)/1000.0);
	}
}
