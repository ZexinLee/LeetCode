/*
	copy from https://leetcode.com/problems/two-sum/discuss/231767/C%2B%2B-or-O(n)-complexity-or-4ms-faster-than-99.94-or-Memory%3A-1.5-MB
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        std::map<int,int> seen;
        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(nums[i]) != seen.end()) {
                results.push_back(seen.find(nums[i])->second);
                results.push_back(i);
                return results;
            } else {
                seen[target-nums[i]] = i;
            }
        }
        return results;
    }
};