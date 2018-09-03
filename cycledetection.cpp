/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    
    Node *ptr = head;
    size_t count = 1;
    
    if(ptr == NULL)
        return false;
    
    while( ptr->next != NULL  && ++count < 101)
        ptr = ptr->next;
        
    if(count > 100)
        return true;
    else
        return false;
    
}
