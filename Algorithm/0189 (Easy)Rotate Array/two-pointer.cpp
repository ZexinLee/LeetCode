class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() > 1)
        {
            int n = nums.size();
            int m = k % n;
            for(int i = 0; i < n - m; i++)
                nums.push_back(nums[i]);
            nums.erase(nums.begin(), nums.begin() + n - m);
        }
    }
};
