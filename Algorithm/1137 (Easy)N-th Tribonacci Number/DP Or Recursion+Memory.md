# Algorithm

![Algorithm picture](https://github.com/ZexinLee/LeetCode/blob/master/Algorithm/1137%20(Easy)N-th%20Tribonacci%20Number/Algorithm%20for%201137.png)

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.

Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for N-th Tribonacci Number.

# Time Spent

15 min 0 seconds

# Times of Wrong Answer

1 （Time Limit Exceeded）

# Solution

```c++
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 1;
        }
        
        int tmp, x = 0, y = 1, z = 1;
        for(int i = 3; i <= n; i++) {
            tmp = x + y + z;
            x = y;
            y = z;
            z = tmp;
        }
        return z;
        
    }
};
```

The code of AC solution

# Time Complexity

Briefly analysis of the time complexity

# Note & Tips

1. Use DP instead of recursion since simple recursion will fail in TLE in this question.
2. Recursion + Memory can also AC in this question.
