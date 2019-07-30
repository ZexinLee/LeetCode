class NumArray {
private:
    vector<int> num;
public:
    NumArray(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++)
            this->num.push_back(nums[i]);
    }

    void update(int i, int val) {
        this->num[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for(int pos = i; pos <= j; pos++)
            sum += this->num[pos];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
