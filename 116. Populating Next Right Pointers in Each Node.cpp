/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *ar[5000];
    int nodeCnt;
    
    void traverseTree(Node *node, int nID) {
        if(node) {
            ar[nID] = node;
            nodeCnt++;
            
            if(node->left) {
                traverseTree(node->left, nID*2 + 1);
            }
            
            if(node->right) {
                traverseTree(node->right, nID*2 + 2);
            }
        }
    }
    
    
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        nodeCnt = 0;
        traverseTree(root, 0);
        
        int i, k, marker[13], value;
        marker[0] = 2;
        for( i=1 ; i<13 ; i++ ) {
            value = marker[i-1] + (2<<i);
            marker[i] = value;
        }
        
        k = 0;
        root->next = NULL;
        for(i=1 ; i<nodeCnt - 1 ; i++ ) {
            if(i == marker[k]) {
                ar[i]->next = NULL;
                k++;
            }
            else {
                ar[i]->next = ar[i+1];
            }
        }
        ar[nodeCnt-1]->next = NULL;
        
        return root;
    }
};