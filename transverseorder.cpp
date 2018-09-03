
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/


class Stack{
    public:
        Node *var;
    Stack(){
        var = NULL;
    }
};

void levelOrder(Node * root) {

    std:: queue<Node*> st;
    st.push(root);
    
    while(st.size()!=0){
        
        Node *tmp = st.front();
        st.pop();
        
        if(tmp->left != NULL)
            st.push(tmp->left);
        if(tmp->right != NULL)
            st.push(tmp->right);
        
        std::cout << tmp->data << " ";
    }
}
