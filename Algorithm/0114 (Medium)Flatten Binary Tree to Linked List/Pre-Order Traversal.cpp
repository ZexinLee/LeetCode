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
    void flatten(TreeNode* root) {
        vector<TreeNode*> anslist;
        getpreorder(root, anslist);
        if(anslist.size() <= 1) {
            return;
        }
        for(int i = 0; i < anslist.size() - 1; i++) {
            anslist[i]->left = NULL;
            anslist[i]->right = anslist[i+1];
        }
        anslist[anslist.size() - 1]->left = NULL;
        anslist[anslist.size() - 1]->right = NULL;
    }
    
    void getpreorder(TreeNode* root, vector<TreeNode*>& ans) {
        if(root == NULL) {
            return;
        }
        ans.push_back(root);
        getpreorder(root->left, ans);
        getpreorder(root->right, ans);
    }
};