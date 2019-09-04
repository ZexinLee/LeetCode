# Algorithm

Two-pointer

Go from right-up first and use two-pointer algorithm

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 64 ms, faster than 83.79% of C++ online submissions for Search a 2D Matrix II.

Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.

# Time Spent

1 min 38 second

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int posx = matrix.size() - 1;
        int posy = 0;
        if(matrix.size() == 0) {
            return false;
        }
        while(posx >= 0 && posy < matrix[0].size()) {
            if(matrix[posx][posy] < target) {
                posy++;
            }
            else if(matrix[posx][posy] > target) {
                posx--;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
```

The code of AC solution

# Time Complexity

O(m+n), m is the row number, n is the column number

# Note & Tips

1. Use two pointer instead of Brute-force naive scan. (optimize O(mn) to O(m+n))
2. Use binary search. (Optimize O(m+n) to O(logm + logn))