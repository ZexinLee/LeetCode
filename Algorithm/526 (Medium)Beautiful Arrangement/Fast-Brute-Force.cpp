class Solution {
public:
    int count;
    Solution() {
        this->count = 0;
    }
    int countArrangement(int N) {
        vector<int> nums(N, 0);
        for(int i = 1; i <= N; i++)
            nums[i - 1] = i;
        permute(nums, 0);
        return this->count;
    }
    
    void permute(vector<int> &nums, int l) {
        if (l == nums.size()) {
            this->count++;
        }
        for (int i = l; i < nums.size(); i++) {
            swap(nums, i, l);
            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
                permute(nums, l + 1);
            swap(nums, i, l);
        }
    }
    void swap(vector<int> &nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    

};
