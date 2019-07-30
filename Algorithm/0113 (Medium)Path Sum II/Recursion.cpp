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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        dfs(root, sum, {}, result);
        return result;
    }
    
    void dfs(TreeNode* root, int sum, vector<int> sofar, vector<vector<int>> &result){
        if (root){
            sum-=root->val;
            sofar.push_back(root->val);
            if (root->left == NULL && root->right == NULL){
               if (sum==0)
                    result.push_back(sofar);
            } else {
                dfs(root->left, sum, sofar, result);
                dfs(root->right, sum, sofar, result);
            }
        }
    }
};
