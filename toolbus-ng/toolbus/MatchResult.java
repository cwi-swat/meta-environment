/**
 * @author paulk, Jul 20, 2002
 */
package toolbus;
import aterm.*;

public class MatchResult {
	private boolean matches;
	private MatchEnvironment left;
	private MatchEnvironment right;
	
	public MatchResult(boolean matches, MatchEnvironment left, MatchEnvironment right){
		this.matches = matches;
		this.left = left;
		this.right = right;
	}

	public MatchEnvironment getLeft( ){
		return left;
	}

	public boolean matches() {
		return matches;
	}

	public MatchEnvironment getRight() {
		return right;
	}
	
	public String toString(){
		return "MatchResult(" + matches + ", " + left + ", " + right + ")";
	}
}