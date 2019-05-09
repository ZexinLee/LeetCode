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
    void dfsPreorderTraversal(Node* node, vector<int>& preorderTraversedNodes) {
        preorderTraversedNodes.push_back(node->val);

        for (const auto& child: node->children) {
            this->dfsPreorderTraversal(child, preorderTraversedNodes);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> preorderTraversedNodes;
        if (root == nullptr)    return preorderTraversedNodes;

        this->dfsPreorderTraversal(root, preorderTraversedNodes);

        return preorderTraversedNodes;
    }
};
