class Solution {
void subsetsWithDup(vector<int>& nums, vector<vector<int>>& res, vector<int>& prefix, unordered_map<int, int>& dict, int lo) {
        if (lo == nums.size()) {
            res.push_back(prefix);
            return;
        }
        for (int i = 0; i <= dict[nums[lo]]; i++) {
            vector<int> vals(i, nums[lo]);
            int oldSize = int(prefix.size());
            prefix.insert(prefix.end(), vals.begin(), vals.end());
            subsetsWithDup(nums, res, prefix, dict, lo + dict[nums[lo]]);
            prefix.erase(prefix.begin() + oldSize, prefix.end());
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> prefix;
        unordered_map<int, int> dict;
        for (auto val: nums) {
            dict[val]++;
        }
        subsetsWithDup(nums, res, prefix, dict, 0);
        return res;
    }
};
