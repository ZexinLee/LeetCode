class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first = 0;
        int second = 1;
        int size = nums.size();
        vector<int> ans;
        while(true)
        {
            if(nums[first] + nums[second] == target)
                break;
            if(size > second + 1)
            {
                second++;
            }
            else
            {
                second = ++first;
                second++;
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};