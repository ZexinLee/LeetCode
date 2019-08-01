class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long i = nums.size();
        long long sum = 0;
        for(int i : nums)
            sum += i;
        return i * (i + 1) / 2 - sum;
    }
};
