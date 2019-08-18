# Algorithm

DFS, pre-order traversal of binary tree

# Better Solution

```c++
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
    vector<int>v1;
    vector<int>v2;
    void preorderv1(TreeNode* root)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            v1.push_back(root->val);
        }
        preorderv1(root->left);
        preorderv1(root->right);
    }
     void preorderv2(TreeNode* root)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            v2.push_back(root->val);
        }
        preorderv2(root->left);
        preorderv2(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        preorderv1( root1);
        preorderv2(root2);
        for(int i:v1)cout<<i<<" ";
        cout<<endl;
        for(int i:v2)cout<<i<<" ";
        if(v1==v2)return true;
        else return false;
        
        
    }
};
```

0 ms solution

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 79.80% of C++ online submissions for Leaf-Similar Trees.

Memory Usage: 14.1 MB, less than 77.78% of C++ online submissions for Leaf-Similar Trees.

# Time Spent

3 min 46 seconds

# Times of Wrong Answer

~

# Solution

```c++
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        getleaf(root1, ans1);
        getleaf(root2, ans2);
        if(ans1.size() != ans2.size()) {
            return false;
        }
        for(int i = 0; i < ans1.size(); i++) {
            if(ans1[i] != ans2[i]) {
                return false;
            }
        }
        return true;
    }
    
    void getleaf(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->val);
        }
        getleaf(root->left,ans);
        getleaf(root->right,ans);
    }
};
```

The code of AC solution

# Time Complexity

O(T1+T2), where T1, T2 are the lengths of the given trees.

# Note & Tips

1. An Easy question