package toolbus.environment;

import java.util.LinkedList;

/**
 * ListBindings uses a simple LinkedList to implement the Bindings interface.
 *
 */
class ListBindings implements Bindings {
	protected LinkedList<Binding> bindings;

	public ListBindings() {
		bindings = new LinkedList<Binding>();
	}

	private void setBindings(LinkedList<Binding> b) {
		bindings = b;
	}

	public Bindings clone() {
		ListBindings b = new ListBindings();
		b.setBindings((LinkedList<Binding>) bindings.clone());
		return b;
	}

	public Binding get(String key) {
		for (Binding b : bindings) {
			if (b.getName().equals(key)) {
				return b;
			}
		}
		return null;
	}

	public void put(String key, Binding b) {
		bindings.addFirst(b);
	}

	public void remove(String key) {
		for (Binding b : bindings) {
			if (b.getName().equals(key)) {
				bindings.remove(b);
				return;
			}
		}
		System.err.println("remove:" + key + " is not present\n" + this);
	}

	public String toString() {
		String res = "{", sep = "";

		for (Binding b : bindings) {
			String op = b.isFormal() ? " :-> " : " : ";
			res += sep + b.var + op + b.val;
			sep = ", ";
		}
		return res + "}";
	}
}
