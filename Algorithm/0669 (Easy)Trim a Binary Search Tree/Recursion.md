# Algorithm

Recursion

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        trimBST(&root, L, R);
        return root;
    }
    
    void trimBST(TreeNode **root, int L, int R) {
        auto x = *root;
        if (!x) return;
        if (x->val < L) {
            trimBST(&x->right, L, R);
            *root = x->right;
            return;
        }
        if (R < x->val) {
            trimBST(&x->left, L, R);
            *root = x->left;
            return;
        }
        trimBST(&x->left, L, R);
        trimBST(&x->right, L, R);
    }
};
```

(The best run time solution in the leetcode)

Use pointer of pointer to enhance the performance

# Performance

Runtime: 24 ms, faster than 41.06% of C++ online submissions for Trim a Binary Search Tree.

Memory Usage: 21.3 MB, less than 90.48% of C++ online submissions for Trim a Binary Search Tree.

# Time Spent

13 min 40 seconds

# Times of Wrong Answer

1

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) {
            return root;
        } else if(root->val > R) {
            return trimBST(root->left, L, R);
        } else if(root->val < L) {
            return trimBST(root->right, L, R);
        }
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Recursion is important, and needs more recursion related questions for training.