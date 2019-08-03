# Algorithm

Briefly describe the algorithm steps of the question.

# Better Solution

```c++
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> t;
        for(int i = 0; i < arr.size(); i++){
            t.push_back(arr[i]);
            if(arr[i] == 0) t.push_back(0);
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = t[i];
        }
    }
};
```

(The best run time solution in the leetcode)

Runtime: 16 ms, faster than 98.07% of C++ online submissions for Duplicate Zeros.

Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.

# Performance

Runtime: 20 ms, faster than 74.43% of C++ online submissions for Duplicate Zeros.

Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.

# Time Spent

7 min  49 seconds

# Times of Wrong Answer

1

# Solution

```c++
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        int temp = 0;
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back(arr[temp]);
            if(i == arr.size() - 1) {
                break;
            }
            if(arr[temp] == 0) {
                ans.push_back(0);
                i++;
            }
            temp++;
            if(i == arr.size()) {
                break;
            }
        }
        arr = ans;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Corner case needs to be taken into consideration
2. Do not use a new vector to cover an old vector if they are exactly the same length, this will cause `copy construction` which adds memory operation.