	/*
    class Node 
    	int data;
    	Node left;
    	Node right;
	*/

    public static void Walk(Node ptr, int v1, Stack<Node> st){
        
        st.push(ptr);
        
        if(ptr == null)
            return;
            
        if(ptr.data == v1)
            return;
        
        Walk(ptr.left, v1, st);
        st.pop();
        Walk(ptr.right,v1, st);
        st.pop();
}

	public static Node lca(Node root, int v1, int v2) {
        
        Node ptr = root;
        
        while(true){
            
            if(ptr.data > v1 && ptr.data > v2)
                ptr = ptr.left;
            
            else if(ptr.data < v1 && ptr.data < v2)
                ptr = ptr.right;
            
            else
                return ptr;
            
        }
        
    }
