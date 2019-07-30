class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size() / 2; i++)
            ans += nums[2 * i];
        return ans;
    }
};
