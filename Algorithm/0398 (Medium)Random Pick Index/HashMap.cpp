class Solution {
public:
    map<int, vector<int>> m;
    
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = vector<int>(1, i);
            }
            else {
                m[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        int si = m[target].size();
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, si - 1);
        return m[target][dist6(rng)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */