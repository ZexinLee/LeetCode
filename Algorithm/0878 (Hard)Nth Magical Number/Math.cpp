class Solution {
public:
    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
    
    int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1000000007;
        int L = A / gcd(A, B) * B;
        int M = L / A + L / B - 1;
        int q = N / M, r = N % M;

        long ans = (long long) q * L % MOD;
        if (r == 0)
            return (int) ans;

        int heads[2];
        heads[0] = A;
        heads[1] = B;
        
        for (int i = 0; i < r - 1; ++i) {
            if (heads[0] <= heads[1])
                heads[0] += A;
            else
                heads[1] += B;
        }

        ans += min(heads[0], heads[1]);
        return (int) (ans % MOD);
    }
};
