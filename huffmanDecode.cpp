/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


char findData(node *ptr, const string &s, int &i){
    
    while(true){
        
        if(s[i] == '0'){       
            if(ptr->left == NULL)
                return ptr->data;
            ptr = ptr->left;
            
        }else{
            if(ptr->right == NULL)
                return ptr->data;
            ptr = ptr->right;
        }

        ++i;
    }
}

void decode_huff(node *root, string s) {
    
    int cursor = 0;
    std::string decode;
    
    int len     = s.size();
    
    while(cursor != len){
        decode.push_back(findData(root, s, cursor));
    }
    
    std::cout << decode;
}
