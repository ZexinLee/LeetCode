    const long long MOD = 1000000007L;

    long long mul(long long a, long long b) {
        long long ans = 0, step = a % MOD;
        while (b) {
            if (b & 1L) ans += step;
            if (ans >= MOD) ans %= MOD;
            step <<= 1L;
            if (step >= MOD) step %= MOD;
            b >>= 1L;
        }
        return ans % MOD;
    }