class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> test = heights;
        sort(test.begin(), test.end());
        int ans = 0;
        for(int i = 0; i < test.size(); i++) {
            if(test[i] != heights[i])
                ans++;
        }
        return ans;
    }
};