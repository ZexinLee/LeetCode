class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int k = 0;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j < k + 1; j++) {
                if(j == 0 || j == k) {
                    temp.push_back(1);
                }
                else if(i > 0) {
                    temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }
            ans.push_back(temp);
            k++;
        }
        return ans;
    }
};