/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        int i, j;
        stack<Node*> st;
        bool mark[109];
        bool made[109];
        Node* madeNode[109];
        
        for(i=0 ; i<109 ; i++) mark[i] = made[i] = false;

        Node *newNode, *head = NULL;
        Node *oldNode, *mNode, *foundNode, *p;
        
        mNode = new Node(node->val);
        st.push(node);
        st.push(mNode);
        mark[node->val] = true;
        made[node->val] = true;
        madeNode[node->val] = mNode;
        
        while(!st.empty()) {
            newNode = st.top(); st.pop();
            oldNode = st.top(); st.pop();
            
            int listLen = oldNode->neighbors.size(); 
            
            for(i=0 ; i<listLen ; i++) {
                p = oldNode->neighbors[i];
                foundNode = made[p->val] ? madeNode[p->val] : new Node(p->val);
                made[p->val] = true;
                madeNode[p->val] = foundNode;
                
                newNode->neighbors.push_back(foundNode);
                
                if(!mark[p->val]) {
                    st.push(p);
                    st.push(foundNode);
                    mark[p->val] = true;
                }
            }
            
            if(head == NULL)
                head = newNode;
        }
        
        return head;
    }
};