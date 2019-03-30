class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for (auto n: nums)
            map[n]++;
        
        for (auto p: map) {
            if (p.second == 1)
                return p.first;
        }
        return 0;
    }
};