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
    bool isUnivalTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)  return true;
            stack<TreeNode*> stk;
            stk.push(root);
            while(!stk.empty()){
                TreeNode* temp = stk.top();
                stk.pop();
                if(temp->left != nullptr && temp->left->val != temp->val)  return false;
                else if(temp->left != nullptr && temp->left->val == temp->val) 
                    stk.push(temp->left);
                if(temp->right != nullptr && temp->right->val != temp->val)  return false;
                else if(temp->right != nullptr && temp->right->val == temp->val) 
                    stk.push(temp->right);
            }
            return true;
    }
};
