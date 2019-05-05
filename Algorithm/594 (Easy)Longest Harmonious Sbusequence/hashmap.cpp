class Solution {
public:
    int findLHS(vector<int>& nums) {
        int result = 0, temp = 0;
        unordered_map<int, int>m1;
        for (int i = 0; i < nums.size(); ++i){
            m1[nums[i]]++;
        }
        
        for (auto element:m1){
            if (m1.count(element.first + 1) == 1){
                temp = m1[element.first] + m1[element.first + 1];
                result = max(result, temp);
            }
        }
        return result;
    }
};
