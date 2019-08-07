# Algorithm

Either use extra space or use extra time

# Better Solution

```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int originalRows = nums.size();
        if(originalRows == 0) return nums;
        
        int originalColumns = nums.front().size();
        if(originalRows*originalColumns != r*c) return nums;
        
        vector<vector<int>> result;
        vector<int> currentVector;
        int currentColumn = 0;
        
        for(auto &row : nums) {
            for(auto& number : row){
                currentVector.push_back(number);
                currentColumn++;
                if(currentColumn == c){
                    currentColumn = 0;
                    result.push_back(currentVector);
                    currentVector.clear();
                }
                
            }
        }
        return result;
    }
};
```

To directly use quotation, but not recommend to do this since it may cause `Memory Leak`.

(The best run time solution in the leetcode)

# Performance

Runtime: 40 ms, faster than 20.63% of C++ online submissions for Reshape the Matrix.

Memory Usage: 13.3 MB, less than 6.82% of C++ online submissions for Reshape the Matrix.

# Time Spent

4 min 37 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<int> store;
        vector<vector<int>> ans;
        if(nums.size() == 0 || nums[0].size() * nums.size() != r * c) {
            return nums;
        }
        for(vector<int> temp : nums) {
            for(int i : temp) {
                store.push_back(i);
            }
        }
        int pos = 0;
        for(int i = 0; i < r; i++) {
            vector<int> temp(c, 0);
            for(int j = 0; j < c; j++) {
                temp[j] = store[pos++];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(mn), m is the number of rows, n is the number of columns.

# Note & Tips

1. Sometimes extra space should be used, and sometimes should not.