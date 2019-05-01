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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tempnodenum;
        vector<int> propernodenum;
        vector<TreeNode*> tempnode;
        vector<TreeNode*> propernode;
        if(root == NULL)
            return ans;
        tempnodenum.push_back(root->val);
        tempnode.push_back(root);
        ans.push_back(tempnodenum);
        while(tempnodenum.size() != 0)
        {
            propernodenum.clear();
            propernode.clear();
            for(int i = 0; i < tempnodenum.size(); i++)
            {
                if(tempnode[i]->left != NULL)
                {
                    propernodenum.push_back(tempnode[i]->left->val);
                    propernode.push_back(tempnode[i]->left);
                }
                if(tempnode[i]->right != NULL)
                {
                    propernodenum.push_back(tempnode[i]->right->val);
                    propernode.push_back(tempnode[i]->right);
                }
            }
            if(propernodenum.size() != 0)
                ans.push_back(propernodenum);
            tempnode = propernode;
            tempnodenum = propernodenum;
        }
        return ans;
    }
};
