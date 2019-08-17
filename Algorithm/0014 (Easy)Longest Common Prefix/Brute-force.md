# Algorithm

Brute-Force

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 94.76% of C++ online submissions for Longest Common Prefix.

Memory Usage: 8.9 MB, less than 75.81% of C++ online submissions for Longest Common Prefix.

# Time Spent

~

# Times of Wrong Answer

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        if(N == 0)
            return "";
        if(N == 1)
            return strs[0];
        
        sort(strs.begin(), strs.end());
        int i = 0, j = 0;
        while(i < strs[0].length() && j < strs[N-1].length())
        {
            if(strs[0][i] != strs[N-1][j])
                break;
            i++, j++;
        }
        return strs[0].substr(0,i);
    }
};

```

The code of AC solution

# Time Complexity

TODO

# Note & Tips

1. Using Brute-Force and avoid to contact string.