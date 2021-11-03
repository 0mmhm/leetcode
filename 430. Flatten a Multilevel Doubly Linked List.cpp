/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* letsFlatten(Node *n) {
        Node *curr = n, *nextN, *lastN, *retNode;
        while(curr != NULL) {
            lastN = curr;
            if(curr->child) {
                nextN = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                
                retNode = letsFlatten(curr->child);
                curr->child = NULL;
                retNode->next = nextN;
                if(nextN)
                    nextN->prev = retNode;
            }
            else 
                curr = curr->next;
        }
        
        return lastN;
    }
    
    Node* flatten(Node* head) {
        Node *curr = head;
        
        Node* _ = letsFlatten(curr);
        
        return head;
    }
};