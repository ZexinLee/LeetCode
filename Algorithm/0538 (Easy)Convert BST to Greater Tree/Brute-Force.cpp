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
    void traverse_get(TreeNode* root, vector<int> &addlist) {
        TreeNode* tempNode = root;
        if(tempNode == NULL)
            return;
        addlist.push_back(tempNode->val);
        traverse_get(root->left, addlist);
        traverse_get(root->right, addlist);
    }
    
    void traverse_add(TreeNode* root, vector<int> &addlist) {
        TreeNode* tempNode = root;
        if(tempNode == NULL)
            return;
        int pos = -1;
        for(int i = 0; i < addlist.size(); i++)
            if(addlist[i] > root->val) {
                pos = i;
                break;
            }
        if(pos != -1)
            for(int i = pos; i < addlist.size(); i++)
                tempNode->val += addlist[i];
        traverse_add(root->left, addlist);
        traverse_add(root->right, addlist);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector<int> addlist;
        traverse_get(root, addlist);
        sort(addlist.begin(), addlist.end());
        traverse_add(root, addlist);
        return root;
    }
};
