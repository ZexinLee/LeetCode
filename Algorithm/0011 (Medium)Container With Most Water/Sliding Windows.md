# Algorithm

Sliding windows, i.e., Two-pointer 

# Better Solution

```c++
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);        
        std::cin.tie(nullptr);        
        std::cout.tie(nullptr);
    }
 
    int maxArea(vector<int>& height) {
        int lens = height.size();
        int i=0, j = lens-1;
        int res =0;
        while(i<j){
            res = max(res, (j-i) * min(height[i], height[j]));
            height[i] < height[j] ? i++ : j--;
        }
        return res;
    }
};
```

4 ms answer, turning off ios::sync and using Ternary operator

(The best run time solution in the leetcode)

# Performance

Runtime: 20 ms, faster than 66.45% of C++ online submissions for Container With Most Water.

Memory Usage: 9.9 MB, less than 50.52% of C++ online submissions for Container With Most Water.

# Time Spent

~

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0, l = 0, r = height.size() - 1;
        while(l < r) {
            maxA = max(maxA, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxA;
    }
};
```

The code of AC solution

# Time Complexity

O(n^2) if using brute-force

O(n) if using two-pointer

# Note & Tips

1. Using `ios::sync` to turn off I/O sync.