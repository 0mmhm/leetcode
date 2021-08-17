class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    struct ListNode {
        int key;
        ListNode* next;
        
        ListNode(int keyVal) {
            key = keyVal;
            next = NULL;
        }
    };
    
    ListNode *head, *tail;
    
    MyHashSet() {
        head = tail = NULL;
    }
    
    void add(int key) {
        if(head == NULL) {
            ListNode *node = new ListNode(key);
            head = node;
            return;
        }
        
        ListNode *curr = head;
        bool isFound = false;
        while(curr != NULL){
            if(curr->key == key) {
                isFound = true;
            }
            
            if(curr->next == NULL) break;
            curr = curr->next;
        }
        
        if(!isFound) {
            ListNode *node = new ListNode(key);
            curr->next = node;
        }
    }
    
    void remove(int key) {
        ListNode *prev = NULL, *curr = head;
        
        if(curr != NULL && curr->key == key){
            head = head->next; return; 
        }
                
        while(curr != NULL) {
            if(curr->key == key) {
                if(prev != NULL) prev->next = curr->next;
                break;
            }
            
            prev = curr;
            curr = curr->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        ListNode *curr = head;
        while(curr != NULL) {
            if(curr->key == key) return true;
            curr = curr->next;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */