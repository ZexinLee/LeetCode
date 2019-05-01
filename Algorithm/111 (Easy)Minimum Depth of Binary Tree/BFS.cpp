class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 0;
        queue<pair<int, TreeNode> > que;
        que.push({1, *root});
        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            if(!tmp.second.left && !tmp.second.right)
                return tmp.first;
            if(tmp.second.left)
                que.push({tmp.first + 1, *tmp.second.left});
            if(tmp.second.right)
                que.push({tmp.first + 1, *tmp.second.right});
        }
        return 0;
    }
};
