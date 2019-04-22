class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        // 从右往左的中序遍历，传递遍历过的节点的和
        inOrderDFS(root,0);
        return root;
    }
    
    // 用变量名解释正式过程
    // int inOrderDFS(TreeNode* root, const int &parentSum){
    //     if(!root) return 0;
    //     int origin_val = root->val;
    //     int rightSum = inOrderDFS(root->right,parentSum);
    //     root->val += parentSum + rightSum;
    //     int leftSum = inOrderDFS(root->left,parentSum + rightSum+origin_val);
    //     return origin_val+rightSum+leftSum;
    // }
    
    
    int inOrderDFS(TreeNode* root, const int &parentSum){
        if(!root) return 0;
        root->val += parentSum + inOrderDFS(root->right,parentSum);
        return root->val - parentSum + inOrderDFS(root->left,root->val);
    }
};
