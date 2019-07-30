class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0;
        unordered_multiset<int> mst;
        for (int i: nums) {
            sum += i;
            cnt += mst.count(sum - k) + (sum == k);
            mst.insert(sum);
        }
        return cnt;
    }
};
