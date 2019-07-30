/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inordertraverse(TreeNode* root, vector<int> &ans) {
        if(root == NULL)
            return;
        inordertraverse(root->left, ans);
        ans.push_back(root->val);
        inordertraverse(root->right, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> anslist;
        inordertraverse(root, anslist);
        return anslist[k-1];    
    }
};
