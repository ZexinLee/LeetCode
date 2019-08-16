# Algorithm

Math and string operation

# Better Solution

```c++
namespace {
    unordered_map<char, int> symbolToValue
    {
        {'O', 0},
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
}

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        s.push_back('0');  // sentinel

        int number = 0;
        for (size_t index = 0; index < s.size() - 1; ++index) {
            const char c {s[index]}, nextc{s[index + 1]};
            // detect it a substraction
            if (symbolToValue[c] < symbolToValue[nextc] &&
                (c == 'I' || c == 'X' || c == 'C')) {
                number -= symbolToValue[c];
            } else {
                number += symbolToValue[c];
            }
        }
        return number;
    }
};
```

0 ms answer

(The best run time solution in the leetcode)

# Performance

Runtime: 28 ms, faster than 13.98% of C++ online submissions for Roman to Integer.

Memory Usage: 10.5 MB, less than 27.45% of C++ online submissions for Roman to Integer.

# Time Spent

~

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> vals;
        int ans = 0;
        vals['M'] = 1000;
        vals['D'] = 500;
        vals['C'] = 100;
        vals['L'] = 50;
        vals['X'] = 10;
        vals['V'] = 5;
        vals['I'] = 1;
        
        for(int i = 0; i < s.length() - 1; i++)
        {
            if(vals[s[i]] < vals[s[i+1]])
            {
                ans -= vals[s[i]];
            }
            else
            {
                ans += vals[s[i]];
            }
        }
        ans += vals[s[s.length() - 1]];
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

~

# Note & Tips

1. use `+=` is low efficient.
2. In this question, deal with the map(could use `unordered_map` instead since no order needed) without call `string` API can accelerate.