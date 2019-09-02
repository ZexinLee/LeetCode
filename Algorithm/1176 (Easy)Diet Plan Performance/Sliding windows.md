# Algorithm

Sliding Windows

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 40 ms, faster than 62.90% of C++ online submissions for Diet Plan Performance.

Memory Usage: 13.1 MB, less than 100.00% of C++ online submissions for Diet Plan Performance.

# Time Spent

6 min 5 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        long long tempsum = 0;
        int point = 0;
        for(int i = 0; i < k; i++) {
            tempsum += calories[i];
        }
        if(tempsum > upper) {
                point++;
        }
        if(tempsum < lower) {
            point--;
        }
        for(int i = k; i < calories.size(); i++) {
            tempsum -= calories[i - k];
            tempsum += calories[i];
            if(tempsum > upper) {
                point++;
            }
            if(tempsum < lower) {
                point--;
            }
        }
        return point;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Use sliding windows to maintain a temporary sum.