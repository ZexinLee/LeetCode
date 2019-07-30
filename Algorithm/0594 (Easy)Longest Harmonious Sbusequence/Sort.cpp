class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev_count = 1, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int count = 1;
            if (i > 0 && nums[i] - nums[i - 1] == 1) {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    count++;
                    i++;
                }
                res = max(res, count + prev_count);
                prev_count = count;
            } else {
                while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    count++;
                    i++;
                }
                prev_count = count;
            }
        }
        return res;
    }
};
