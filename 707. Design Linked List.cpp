class MyLinkedList {
public:
    /** Initialize your data structure here. */
    
    struct ListNode {
        int val;
        ListNode* next;
        
        ListNode(int value) {
            val = value;
            next = NULL;
        }
    };
    
    ListNode *head, *tail;
    
    MyLinkedList() {
        head = tail = NULL;
    }
    
    void makeHead(int val){
        ListNode *newHead = new ListNode(val);
        head = tail = newHead;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        ListNode* curr = head;
        
        // bool isTailFound = true;
        // if(tail == NULL) isTailFound = false;
        
        while(curr != NULL){
            if( i == index) return curr->val;
            curr = curr->next;
            i++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        if(head == NULL){
            makeHead(val);
            return;
        }
        
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head == NULL){
            makeHead(val);
            return;
        }
        
        ListNode* node = new ListNode(val);
        tail->next = node;
        tail = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(head == NULL){
            makeHead(val);
            return;
        }
        
        if(index == 0){
            addAtHead(val);
            return;
        }
        
        int i = 0;
        ListNode *curr = head;
        while(curr != NULL){
            if(i + 1 == index && curr->next != NULL) {
                ListNode *node = new ListNode(val);
                node->next = curr->next;
                curr->next = node;
                return;
            }
            curr = curr->next;
            i++;
        }
        addAtTail(val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(head == NULL) return;
        
        int i = 0;
        ListNode *curr = head;
        
        if(index == 0) head = head->next;
        while(curr != NULL) {
            if(i+1 == index && curr->next != NULL) {
                if(curr->next->next != NULL){
                    curr->next = curr->next->next;
                }
                else{
                    curr->next = NULL;
                    tail = curr;
                }
            }
            curr = curr->next;
            i++;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */