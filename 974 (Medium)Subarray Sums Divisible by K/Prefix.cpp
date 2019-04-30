class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int N = A.size();
        int P[N+1] = {0};
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        int count[K] = {0};
        for(int i = 0; i <= N; i++)
            count[(P[i] % K + K) % K]++;

        int ans = 0;
        for (int i = 0; i < K; i++)
            ans += count[i] * (count[i] - 1) / 2;
        return ans;
    }
};
