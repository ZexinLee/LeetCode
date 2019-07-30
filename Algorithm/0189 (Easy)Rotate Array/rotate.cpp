class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() > 1) {
                if(k > nums.size())
                    k -= nums.size();
                int n = nums.size()-k;
                std::rotate(nums.begin(),nums.begin()+n,nums.end());

             }
    }
};
