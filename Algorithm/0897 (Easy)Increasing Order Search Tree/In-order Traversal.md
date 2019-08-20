# Algorithm

In-order Traversal of binary tree

Rotation of binary tree

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
    void myfun(TreeNode* root, TreeNode** prev)
    {
        if (!root)
            return;
        myfun(root->right, prev);
        if (*prev)
        {
            root->right = *prev;
        }
        *prev = root;
        myfun(root->left, prev);
        root->left = NULL;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = NULL;
        myfun(root, &prev);
        return prev;
    }
};
```

16 ms answer, use rotation.

(The best run time solution in the leetcode)

# Performance

Runtime: 44 ms, faster than 29.59% of C++ online submissions for Increasing Order Search Tree.

Memory Usage: 18.8 MB, less than 50.00% of C++ online submissions for Increasing Order Search Tree.

# Time Spent

10 min 5 seconds

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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> ans;
        if(root == NULL) {
            return root;
        }
        getinorder(root, ans);
        resolve(ans);
        return ans[0];
    }
    
    void getinorder(TreeNode* root, vector<TreeNode*>& ans) {
        if(root == NULL) {
            return;
        }
        getinorder(root->left, ans);
        ans.push_back(root);
        getinorder(root->right, ans);
    }
    
    void resolve(vector<TreeNode*>& ans) {
        for(int i = 0; i < ans.size() - 1; i++) {
            ans[i]->left = NULL;
            ans[i]->right = ans[i+1];
        }
        ans[ans.size() - 1]->left = NULL;
        ans[ans.size() - 1]->right = NULL;
    }
};
```

Simple In-order Traversal

The code of AC solution

# Time Complexity

Both algorithm are O(n), but rotation can have less space complexity and reach better performance.

# Note & Tips

1. Binary tree question.