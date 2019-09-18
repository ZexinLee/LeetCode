# Algorithm

Simple use of hash table.

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 348 ms, faster than 31.24% of C++ online submissions for Distribute Candies.

Memory Usage: 50.9 MB, less than 33.33% of C++ online submissions for Distribute Candies.

# Time Spent

35 min

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
   int distributeCandies(vector<int>& candies) {
        
        unordered_set<int> mp;
        for(int i : candies) mp.insert(i);
        
        return min(candies.size()/2, mp.size());
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Use hash table can easily solve this problem.