package nl.cwi.term;

import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * This is a parser for signatures. The signature will be converted to a
 * hierarchy of uniquely idenifiable nodes.
 * 
 * @author Arnold Lankamp
 */
public class SignatureParser{

	/**
	 * Default constructor. Private to prevent needless instantiation.
	 */
	private SignatureParser(){
		super();
	}

	/**
	 * Transforms the given signature into a hierarchy of nodes.
	 * 
	 * @param signature
	 *            The signature that needs to be parsed.
	 * @return The Constructed node tree.
	 */
	public static Node parse(String signature){
		Node rootNode = new Node(null, null);
		Node node = rootNode;

		StringTokenizer sigTokenizer = new StringTokenizer(signature, "(,)<>", true);
		while(sigTokenizer.hasMoreTokens()){
			String token = sigTokenizer.nextToken().intern();
			if(token == ")"){
				node = node.getParent();
			}else if(token == "(" || token == "," || token == "<" || token == ">"){
				// Do nothing
			}else{
				node = new Node(token, node);
			}
		}

		return rootNode.getChildren()[0];
	}

	/**
	 * Represents a node in a signature.
	 * 
	 * @author Arnold Lankamp
	 */
	public static class Node{
		private String type = null;
		private Node parent = null;
		private int index = -1;

		private List nodeList = null;

		/**
		 * Constructor.
		 * 
		 * @param type
		 *            The type of this node.
		 * @param parent
		 *            The parent of this node (may be null).
		 */
		public Node(String type, Node parent){
			super();

			this.type = type;

			index = 0;

			if(parent != null){
				this.parent = parent;
				parent.add(this);
			}

			nodeList = new ArrayList();
		}

		/**
		 * Returns the type of this node.
		 * 
		 * @return The type of this node.
		 */
		public String getType(){
			return type;
		}

		/**
		 * Returns the parent of this node.
		 * 
		 * @return The parent of this node.
		 */
		public Node getParent(){
			return parent;
		}

		/**
		 * Returns an array containing all the children of this node.
		 * 
		 * @return An array containing all the children of this node.
		 */
		public Node[] getChildren(){
			Object[] objs = nodeList.toArray();
			Node[] nodes = new Node[objs.length];
			System.arraycopy(objs, 0, nodes, 0, nodes.length);

			return nodes;
		}

		/**
		 * Sets the index of this node.
		 * 
		 * @param index
		 *            The index of this node.
		 */
		private void setIndex(int index){
			this.index = index;
		}

		/**
		 * Returns the index of this node.
		 * 
		 * @return The index of this node.
		 */
		private int getIndex(){
			return index;
		}

		/**
		 * Returns the unique identification of this node (based on the position
		 * in the tree).
		 * 
		 * @return The unique identification of this node.
		 */
		public String getID(){
			StringBuilder idBuilder = new StringBuilder();

			if(parent != null){
				idBuilder.append(parent.getIndex());
				idBuilder.append(".");
			}
			idBuilder.append(getIndex());

			return idBuilder.toString();
		}

		/**
		 * Adds a child to this node.
		 * 
		 * @param node
		 *            The child that needs to be associated with this node.
		 */
		private void add(Node node){
			nodeList.add(node);
			node.setIndex(nodeList.size() - 1);
		}
	}
}
