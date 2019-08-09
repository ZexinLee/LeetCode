# Algorithm

1. Brute Force
   - Time complexity : O(n^2). For each element, we try to find its complement by looping through the rest of array which takes O(n) time. Therefore, the time complexity is O(n^2).
   - Space complexity : O(1). 

2. Two-pass Hash Table
   - Time complexity : O(n). We traverse the list containing n elements exactly twice. Since the hash table reduces the look up time to O(1), the time complexity is O(n).
   - Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores exactly n elements. 
3. One-pass Hash Table
   - Time complexity : O(n). We traverse the list containing n elements only once. Each look up in the table costs only O(1) time.
   - Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores at most n elements.

# Better Solution

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Usual optimizations
        // Set I/O synchronization off
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        // Use One-pass Hash Table
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.count(target - nums[i]) )
                return {hash[target - nums[i]], i};
            hash.insert({nums[i], i});
        }
        return {};
    }
};
```

(The best run time solution in the leetcode)

# Performance

For better solution

Runtime: 4 ms, faster than 99.73% of C++ online submissions for Two Sum.

Memory Usage: 10 MB, less than 56.68% of C++ online submissions for Two Sum.

# Time Spent

~

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Simple Brute Force
        std::vector<int> ret(2, -1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
        return ret;
    }
};
```

The code of AC solution

# Time Complexity

See in the Algorithm part

# Note & Tips

1. Use hash table can accelerate the search procession if seldom happens hash conflict.