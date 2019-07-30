class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> ans;
        for(int i = 0; i < nums.size();i++)
        {
            if(hash[nums[i]] != 0)
            {
                ans.push_back(hash[nums[i]] - 1);
                ans.push_back(i);
                break;
            }
            else
            {
                hash[target - nums[i]] = i + 1;
            }
        }
        return ans;
    }
};