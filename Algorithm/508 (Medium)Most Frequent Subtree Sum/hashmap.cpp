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
    int sum(TreeNode* root, map<int, int>& m){
        int s = 0;
        if(root)        s += root->val;
        if(root->left)  s += sum(root->left, m);
        if(root->right) s += sum(root->right, m);
        m[s]++;
        return s;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> m;
        vector<int> result;
        
        if(root)    sum(root, m);
        else        return result;
        
        int frequency = 0;
        for(auto i = m.begin(); i != m.end(); i++ )
            if(i->second > frequency)   frequency = i->second;
        
        
        for(auto i = m.begin(); i != m.end(); i++)
            if(i->second == frequency)      result.push_back(i->first);
        
        return result;
    }
};