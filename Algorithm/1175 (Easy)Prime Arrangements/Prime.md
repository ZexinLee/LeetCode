# Algorithm

Math

ans = pert(prime numbers) * pert(other numbers) mod 10e9

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Prime Arrangements.

Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Prime Arrangements.

# Time Spent

24 min 26 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
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
    
    int numPrimeArrangements(int n) {
        int primenum = countprime(n);
        cout << primenum;
        long long ans = mul(fac(primenum),fac(n - primenum));
        return (int)(ans % 1000000007);
    }
    
    int fac(int n) {
        int temp = n;
        long long ans = 1;
        for(int i = n; i >= 1; i--){
            ans *= i;
            ans %= 1000000007;
        }
        return (int)ans;
    }
    
    int countprime(int n) {
        int count = 0;
        vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        for(int i : prime) {
            if(n < i) {
                break;
            }
            count++;
        }
        return count;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Since in this question the data range is  1 <= n <= 100, I list all prime under 100.
2. two long long number multiplication may cause overflow, and the template of long long multiplying has added to template directory.

