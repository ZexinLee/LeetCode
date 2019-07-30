/*
	copy from https://leetcode.com/problems/reverse-pairs/solution/
/*

class Solution {
public:
void update(vector<int>& BIT, int index, int val)
{
    while (index > 0) {
        BIT[index] += val;
        index -= index & (-index);
    }
}

int query(vector<int>& BIT, int index)
{
    int sum = 0;
    while (index < BIT.size()) {
        sum += BIT[index];
        index += index & (-index);
    }
    return sum;
}
int reversePairs(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nums_copy(nums);

    sort(nums_copy.begin(), nums_copy.end());

    vector<int> BITS(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
        update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
    }
    return count;
}
};