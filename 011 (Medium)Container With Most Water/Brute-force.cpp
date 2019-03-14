class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i = 0; i < height.size(); i++)
            for(int j = i + 1; j < height.size(); j++)
                res = max(res, (min(height[i], height[j]) * (j - i)));
        return res;
    }
};