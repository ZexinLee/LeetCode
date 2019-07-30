/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int max;
    Solution() {
        this->max = 0;
    }
    
    void traverse(Node* root, int tempdep) {
        if(root == NULL)
            return;
        this->max = (this->max > tempdep) ? (this->max) : tempdep;
        if((root->children).size()) {
            for(int i = 0; i < (root->children).size(); i++) {
                traverse((root->children)[i], tempdep + 1);
            }
        }
    }

