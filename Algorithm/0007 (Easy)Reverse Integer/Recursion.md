# Algorithm

Recursion

# Better Solution

```c++

```

(The best run time solution in the leetcode)

# Performance

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.

Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Reverse Integer.

# Time Spent

~

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    long long rst = 0;
    void raw_reverse(int x) {
        if(x==0)
            return;
        else
            rst *= 10;
        rst += x % 10;
        x /= 10;
        raw_reverse(x);
    }
    
    int reverse(int x) {
        raw_reverse(x);
        return (rst > INT_MAX || rst < INT_MIN) ? 0 : rst;
    }
};
```

The code of AC solution

# Time Complexity

O(n!)

# Note & Tips

1. This one is simple.