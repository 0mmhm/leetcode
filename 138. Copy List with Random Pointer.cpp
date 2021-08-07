/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        Node *newList = NULL, *prev = NULL, *curr = head;
        vector <int> v;
        Node* arr[1009];
        int i = 0;
        
        while(curr != NULL) {
            Node* node = new Node(i);
            v.push_back(curr->val);
            curr->val = i;
            arr[i] = node;
            
            if(newList == NULL){
                newList = node;
            }
            else{
                prev->next = node;
            }
            prev = node;
            curr = curr->next;
            i++;
        }
        
        curr = head;
        Node* nlCurr = newList;
        while(curr!=NULL) {
            Node* random = curr->random;
            if(random != NULL) nlCurr->random = arr[random->val];
            else nlCurr->random = NULL;
            
            curr = curr->next;
            nlCurr = nlCurr->next;
        }
        
        nlCurr = newList;
        i = 0;
        while(nlCurr != NULL) {
            nlCurr->val = v[i];
            nlCurr = nlCurr->next;
            i++;
        }
        
        return newList;
    }
};