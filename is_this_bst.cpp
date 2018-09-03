/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

int *vec = NULL;
int size = 0;

void aux(Node* ptr){
    
    int h = height(ptr);
    
    for (int i=1; i<=h; i++)
        walkTree(ptr, i);
}

void walkTree(Node* ptr, int level){
    
    if (ptr == NULL){
        vec         = (int*)realloc(vec,(++size)*sizeof(int));
        vec[size-1] = -1;
        return;
    }
    if (level == 1){
        vec         = (int*)realloc(vec,(++size)*sizeof(int));
        vec[size-1] = ptr->data;
    }
    else if (level > 1){
        walkTree(ptr->left, level-1);
        walkTree(ptr->right, level-1);
    }
}
  

int height(Node* ptr){
    if (ptr==NULL)
        return 0;
    else{
        /* compute the height of each subtree */
        int lheight = height(ptr->left);
        int rheight = height(ptr->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

bool checkBST(Node* root) {
        
    aux(root);
    
    //for(int i = 0;i<size;i++)
        //printf("%d ", vec[i]);
    
    //printf("size %d", size);
    for(int i = size-1; i > 0 ; i--){
        
        int j = i;
        int a = vec[i];
        
        //printf("i: %d %d\n", i, vec[i]);
        
        if (a != -1){
            
            do{
                if(j%2 == 0){
                    
                    j = j/2 - 1;
                    j = (j >= 0? j : 0);
                    //printf("R %d %d\n", j, vec[j]);
                    if(vec[j] >= a )
                        return false;

                }else{
                    
                    j = j/2;
                    //printf("L %d %d\n", j, vec[j]);
                    if(vec[j] <= a)
                        return false;
                }
            }while(j>0);
        }
    }
    
    return true;
        
}
