class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minnum = INT_MAX, maxnum = INT_MIN;
        for(auto &v : A)
        {
            minnum = min(minnum, v);
            maxnum = max(maxnum, v);
        }
        return (maxnum - minnum > 2*K) ? (maxnum - minnum - 2 * K) : 0;
    }
};
