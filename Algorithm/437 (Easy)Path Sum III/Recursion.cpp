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
    vector<int> vals;
    int res = 0;
public:
    void preOrder(TreeNode* root, int sum){
        if(!root) return;
        vals.push_back(root->val);
        if(root->left) preOrder(root->left, sum);
        if(root->right) preOrder(root->right, sum);
        //Process
        int suffix = 0;
        for(int i = vals.size() - 1; i >= 0; i--){
            suffix += vals[i];
            if(suffix == sum) res += 1;
        }
        vals.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        preOrder(root, sum);
        return res;
    }
};
