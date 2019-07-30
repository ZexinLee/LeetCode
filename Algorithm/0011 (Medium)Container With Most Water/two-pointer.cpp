class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0, l = 0, r = height.size() - 1;
        while(l < r) {
            maxA = max(maxA, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxA;
    }
};