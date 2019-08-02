# Algorithm

Basic use of heap

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.

Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Last Stone Weight.

# Time Spent

10 min 17 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        int templarge, tempsmall;
        while(stones.size() >= 2) {
            pop_heap(stones.begin(), stones.end());
            templarge = stones[stones.size() - 1];
            stones.pop_back();
            pop_heap(stones.begin(), stones.end());
            tempsmall = stones[stones.size() - 1];
            stones.pop_back();
            stones.push_back(templarge - tempsmall);
            push_heap(stones.begin(), stones.end());
        }
        return stones[0];
    }
};
```

The code of AC solution

# Time Complexity

O(nlogn)

# Note & Tips

1. `heap` in STL is not a certain vector, but to maintain an interval in order.