# Algorithm

Hash table, array

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 12 ms, faster than 90.05% of C++ online submissions for Valid Sudoku.

Memory Usage: 9.9 MB, less than 56.41% of C++ online submissions for Valid Sudoku.

# Time Spent

37 min 20 seconds

# Times of Wrong Answer

2

# Solution

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        // column check
        // block check
        for(int i = 0; i < 9; i++) {
            vector<int> temp(9,0);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] - '1' >= 0) {
                    temp[board[i][j] - '1']++;
                }
            }
            for(int j = 0; j < 9; j++) {
                if(temp[j] > 1) {
                    return false;
                }
            }
        }
        
        for(int i = 0; i < 9; i++) {
            vector<int> temp(9,0);
            for(int j = 0; j < 9; j++) {
                if(board[j][i] - '1' >= 0) {
                    temp[board[j][i] - '1']++;       
                }
            }
            for(int j = 0; j < 9; j++) {
                if(temp[j] > 1) {
                    return false;
                }
            }
        }
        
        for(int m = 0; m < 9; m+=3) {
            for(int n = 0; n < 9; n+=3) {
                vector<int> temp(9,0);
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(board[i + m][j + n] - '1' >= 0) {
                            temp[board[i + m][j + n] - '1']++;
                        }
                    }
                }
                for(int i = 0; i < 9; i++) {
                    if(temp[i] > 1) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
```

The code of AC solution

# Time Complexity

O(n^2), n=9

# Note & Tips

1. I have made 2 mistakes in solving this question: 
   1. not understanding the question correctly: I did not make block check but angle check at first.
   2. use wrong branch check: I use `>` first which makes losing all 0.