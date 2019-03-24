class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int temp = 0;
        for(int i = 0;i < nums.size();i++){
            sum = (temp + nums[i] > sum) ? (temp + nums[i]) : sum;
            temp = (temp + nums[i] > 0) ? (temp + nums[i]) : 0;
        }
        return sum;
    }
};