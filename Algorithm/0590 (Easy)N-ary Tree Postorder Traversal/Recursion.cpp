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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        getpostorder(root, ans);
        return ans;
    }
    
    void getpostorder(Node* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        auto it = root->children.begin();
        while(it != root->children.end()) {
            getpostorder(*(it++), ans);
        }
        ans.push_back(root->val);
    }
};