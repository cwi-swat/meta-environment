package toolbus.environment;

class SharedList {
	Binding binding;
	SharedList tail;
	public SharedList(Binding b, SharedList s){
		binding = b;
		tail = s;
	}
	public Binding getFirst(){
		return binding;
	}
	public boolean hasNext(){
		return 
		tail != null;
	}

public class SharedListBindings implements Bindings {
	private SharedList bindings = null;

		public SharedListBindings() {
		}

		private void setBindings(SharedList b) {
			bindings = b;
		}

		public Bindings clone() {
			ListBindings b = new ListBindings();
			b.setBindings((bindings);
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


	public Binding get(String key) {
		// TODO Auto-generated method stub
		return null;
	}

	public void put(String key, Binding binding) {
		// TODO Auto-generated method stub

	}

	public void remove(String key) {
		// TODO Auto-generated method stub

	}

}
