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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        getlevelOrder(root, ans);
        return ans;
    }
    
    void getlevelOrder(Node* root, vector<vector<int>>& ans) {  
        queue<Node*> q;
        queue<Node*> tempq;
        if(root == NULL) {
            return;
        }
        q.push(root);
        do {         
            vector<int> anslist;
            tempq = queue<Node*>();
            while(!q.empty()) {
                anslist.push_back(q.front()->val);
                for(Node* node : q.front()->children) {
                    tempq.push(node);
                }
                q.pop();
            }
            ans.push_back(anslist);  
            q = tempq;
        } while(!tempq.empty());
    }
};