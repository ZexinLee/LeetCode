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
    int count = 0;
    Solution()
    {
        this->count = 0;
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root)
        {
            if(root->val >= L && root->val <= R)
                this->count += root->val;
        }
        else
        {
            return 0;
        }
        rangeSumBST(root->left, L, R);
        rangeSumBST(root->right, L, R);
        return this->count;
    }
};
