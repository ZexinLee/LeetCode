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
    int min;
    Solution() {
        this->min = 99999;
    }
    
    void traverse(TreeNode* root, int tempdep) {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            this->min = (this->min > tempdep) ? tempdep : (this->min);
        traverse(root->left, tempdep + 1);
        traverse(root->right, tempdep + 1);
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        traverse(root, 1);
        return this->min;
    }
};
