# Algorithm

BFS

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
    int d1 = INT_MAX, d2 = INT_MAX;
    bool ans = true;
    
    void helper(TreeNode *root, int x, int y, int depth) {
        if (!ans)
            return;
        if (!root)
            return;
        if (depth > d1 || depth > d2)
            return;
        if (root->val == x) {
            d1 = depth;
            return;
        }
        if (root->val == y) {
            d2 = depth;
            return;
        }
        if (root->left && root->right) {
            if ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)) {
                ans = false;
                return;
            }
        }
        helper(root->left, x, y, depth+1);
        helper(root->right, x, y, depth+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root, x, y, 0);
        return ans ? (d1 == d2 && d1 != INT_MAX) : false;
    }
};
```

0 ms solution

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 75.04% of C++ online submissions for Cousins in Binary Tree.

Memory Usage: 12.4 MB, less than 6.67% of C++ online submissions for Cousins in Binary Tree.

# Time Spent

7 min 33 seconds

# Times of Wrong Answer

0

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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> ans1;
        vector<int> ans2;
        ans1 = findfatheranddepth(root, x);
        ans2 = findfatheranddepth(root, y);
        if(ans1[0] == ans2[0] && ans1[1] != ans2[1]) {
            return true;
        } else {
            return false;
        }
    }
    
    vector<int> findfatheranddepth(TreeNode*root, int input) {
        vector<int> ans;
        if(root == NULL) {
            return vector<int>(2,0);
        } else if(root->val == input) {
            return vector<int>(2,0);
        } else {
            queue<TreeNode*> q;
            queue<TreeNode*> tempq;
            int count = 0;
            q.push(root);
            while(true) {
                while(!q.empty()) {
                    TreeNode* temp = q.front();
                    if(temp->left != NULL) {
                        if(temp->left->val != input) {
                            tempq.push(temp->left);
                        } else {
                            ans.push_back(count + 1);
                            ans.push_back(temp->val);
                            goto flag;
                        }
                    }
                    if(temp->right != NULL) {
                        if(temp->right->val != input) {
                            tempq.push(temp->right);
                        } else {
                            ans.push_back(count + 1);
                            ans.push_back(temp->val);
                            goto flag;
                        }
                    }
                    q.pop();
                }
                q = tempq;
                tempq = queue<TreeNode*>();
                count++;
            }
            flag:return ans;
        }       
    } 
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Simple BFS.