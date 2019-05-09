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
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root)
        {
            preorder(root->left, ans);
            ans.push_back(root->val);
            preorder(root->right, ans);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    
    bool isValidBST(TreeNode* root) {
        vector<int> ans = preorderTraversal(root);
        int temp;
        if(ans.size() <= 1)
            return true;
        for(int i = 0; i < ans.size(); i++)
        {
            if(i == 0)
            {
                temp = ans[i];
                continue;
            }
            if(ans[i] > temp)
                temp = ans[i];
            else
                return false;
        }
        return true;
    }
};
