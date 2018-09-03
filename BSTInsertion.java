 /* Node is defined as :
 class Node 
    int data;
    Node left;
    Node right;
    
    */

	public static Node insert(Node root,int data) {
        
        Node ptr = root;
        
        if(root == null)
            return new Node(data);
        
        while(true){
            
            if(ptr.data > data){
                if(ptr.left == null){
                    ptr.left    = new Node(data);
                    return root;
                }
                else
                    ptr         = ptr.left;
            }
            else{
                if(ptr.right == null){
                    ptr.right   = new Node(data);
                    return root;
                }
                else
                    ptr         = ptr.right;
            }
                
        }

    }
