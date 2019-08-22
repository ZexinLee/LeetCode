# Algorithm

Two-pointer

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 20 ms, faster than 93.00% of C++ online submissions for Remove Duplicates from Sorted Array.

Memory Usage: 10 MB, less than 75.00% of C++ online submissions for Remove Duplicates from Sorted Array.

# Time Spent

From the beginning of the question to the time of the first AC.

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
 int removeDuplicates(vector<int>& nums) {
        if(empty(nums))
            return 0;
        int writeIndex = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[writeIndex-1]!=nums[i]){
                nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Use scanned array as buffer