# Algorithm

Recursion & Bit operation

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 58.32% of C++ online submissions for Number Complement.

Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Number Complement.

# Time Spent

5 min 1 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    int findComplement(const int& num) {
        return num ^ INT_MAX >> shift(num);
    }
    
    //returns how many should be shifted before xor
    int shift(int num) {
        int count = 0;
        while (num != 0) {
            count++;
            num >>= 1;
        }
        return 31 - count;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Use Recursion.