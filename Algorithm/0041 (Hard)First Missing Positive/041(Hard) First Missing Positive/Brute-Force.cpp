class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> temp(nums.size(),false);
        for(int i : nums) {
            if(i <= temp.size() && i > 0)
                temp[i - 1] = true;
        }
        for(int i = 0; i < temp.size(); i++) {
            if(!temp[i])
                return i+1;
        }
        return temp.size() + 1;
    }
};
