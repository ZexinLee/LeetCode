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
    void postorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            postorder(root->left, ans);
            postorder(root->right, ans);
            ans.push_back(root->val);
        }
    }

    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
