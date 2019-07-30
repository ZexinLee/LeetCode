
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x)  val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public
    bool isSameTree(TreeNode p, TreeNode q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL  q == NULL)
            return false;
        if(p-val == q-val)
            return isSameTree(p-left, q-left) && isSameTree(p-right, q-right);
        else
            return false;
    }
    
    bool isSubtree(TreeNode s, TreeNode t) {
        if(isSameTree(s, t))
            return true;
        else if(s != NULL)
            return isSubtree(s-left, t)  isSubtree(s-right, t);
        else
            return false;
    }
};


