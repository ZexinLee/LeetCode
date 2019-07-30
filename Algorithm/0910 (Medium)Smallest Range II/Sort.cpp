class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int N = A.size();
        int ret = A[N-1] - A[0];
        for(int i = 0; i < N - 1; i++)
            if(A[i] != A[i+1]) ret = min(ret, max(A[i]+K, A[N-1]-K) - min(A[i+1]-K, A[0]+K));
        return ret;
    }
};
