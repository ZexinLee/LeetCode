# Algorithm

Very simple count

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 90.74% of C++ online submissions for Maximum Number of Balloons.

Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Maximum Number of Balloons.

# Time Spent

4 min 52 second

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            m['a' + i] = 0;
        }
        for(char c : text) {
            m[c]++;
        }
        ans = m['b'];
        ans = min(ans, m['a']);
        ans = min(ans, m['l'] / 2);
        ans = min(ans, m['o'] / 2);
        ans = min(ans, m['n']);
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Easy