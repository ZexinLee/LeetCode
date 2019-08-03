# Algorithm

Briefly describe the algorithm steps of the question.

# Better Solution

```c++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int N = (int)A.size(), M = (int)A[0].size();
        
        vector<vector<int>> res(M, vector<int>(N));
    
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                res[j][i] = A[i][j];
        
        return res;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 28 ms, faster than 62.73% of C++ online submissions for Transpose Matrix.

Memory Usage: 11.7 MB, less than 65.38% of C++ online submissions for Transpose Matrix.

# Time Spent

4 min 29 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ans;
        if(A.size() == 0) {
            return ans;
        }
        for(int i = 0; i < A[0].size(); i++) {
            vector<int> temp(A.size(), 0);
            ans.push_back(temp);
        }
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(mn), m is row number of the matrix, n is column number of the matrix.

# Note & Tips

1. Use initializing constructor of vector(STL) can significantly enhance the performance.