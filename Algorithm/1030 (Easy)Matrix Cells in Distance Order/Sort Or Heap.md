# Algorithm

Use anonymous comparing function instead of default one in `sort()`

Also, use `make_heap()` can solve this question

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 108 ms, faster than 78.34% of C++ online submissions for Matrix Cells in Distance Order.

Memory Usage: 17.3 MB, less than 82.50% of C++ online submissions for Matrix Cells in Distance Order.

# Time Spent

From the beginning of the question to the time of the first AC.

# Times of Wrong Answer

16 min 57 seconds

# Solution

```c++
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.push_back({i, j, abs(i - r0) + abs(j - c0)});

        // Use Anonymous comparing function to override sort comparing function
        sort(ans.begin(), ans.end(), [](vector<int>& c1, vector<int>& c2) {
            return c1[2] < c2[2];
        });

        // Delete distance in the answer list
        for (vector<int>& d: ans) 
            d.pop_back();

        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(nlogn)

# Note & Tips

1. Use buffer to store high-cost value (in this question: abs(x - x0) + abs(y - y0)) can reduce the time cost.
2. Use heap in C++ can also solve this question in the same time complexity as the solution of sort().