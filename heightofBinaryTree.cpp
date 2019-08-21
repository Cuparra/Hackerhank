
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

int getHeight(Node *leaf, int height){
    
    if(leaf == NULL)
        return height;
    
    int rightHeight     = getHeight(leaf->right,height + 1);
    int leftHeight      = getHeight(leaf->left, height + 1);
    
    if(rightHeight > leftHeight)
        return rightHeight;
    else
        return leftHeight;
}

int height(Node *root) {    
    return getHeight(root,-1);        
}
