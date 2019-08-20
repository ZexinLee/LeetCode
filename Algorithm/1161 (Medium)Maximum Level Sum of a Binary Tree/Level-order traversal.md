# Algorithm

Level-order Traversal of binary tree

# Better Solution

```c++

```

(The best run time solution in the leetcode)

# Performance

Runtime: 232 ms, faster than 51.55% of C++ online submissions for Maximum Level Sum of a Binary Tree.

Memory Usage: 76.6 MB, less than 100.00% of C++ online submissions for Maximum Level Sum of a Binary Tree.

# Time Spent

30 min 0 seconds

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
    int maxLevelSum(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        queue<TreeNode*> tempq;
        q.push(root);
        if(root == NULL) {
            return 0;
        }
        while(!tempq.empty() || !q.empty()) {
            int sum = 0;
            while(!q.empty()) {
                if(q.front() != NULL) {
                    sum += q.front()->val;
                    if(q.front()->left != NULL) {
                        tempq.push(q.front()->left);
                    }
                    if(q.front()->right != NULL) {
                        tempq.push(q.front()->right);
                    }
                }
                q.pop();
            }
            ans.push_back(sum);
            q = tempq;
            tempq = queue<TreeNode*>();
        }
        
        return getmax(ans);
    }
    
    int getmax(vector<int> ans) {
        int max = INT_MIN;
        int level = 0;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] > max) {
                max = ans[i];
                level = i;
            }
        }
        return level + 1;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Use queue.