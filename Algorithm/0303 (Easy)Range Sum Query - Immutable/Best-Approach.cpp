class NumArray {
private:
    vector<long long> sum;
    
public:
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
                this->sum.push_back(nums[i]);
            else
                this->sum.push_back(this->sum[i - 1] + nums[i]);
        }   
    }
    
    int sumRange(int i, int j) {
        int ans; 
        if(i > 0)
            ans = this->sum[j] - this->sum[i - 1];
        else
            ans = this->sum[j];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
