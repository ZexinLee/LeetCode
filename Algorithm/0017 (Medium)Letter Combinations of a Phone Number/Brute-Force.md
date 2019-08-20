# Algorithm

Brute-force, simple mapping

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 59.44% of C++ online submissions for Letter Combinations of a Phone Number.

Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.

# Time Spent

~

# Times of Wrong Answer

1

# Solution

```c++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len[] = {3, 3, 3, 3, 3, 4, 3, 4};
        vector<vector<char> > value = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        int pos[digits.length()];
        int count[digits.length()];
        for(int i = 0; i < digits.length(); i++) {
            pos[i] = digits[i] - '2';
            count[i] = 0;
        }
        
        string temp;
        while(count[digits.length() - 1] < len[pos[digits.length() - 1]]) {
            temp = "";
            for(int i = 0; i < digits.length(); i++)
                temp += value[pos[i]][count[i]];
            ans.push_back(temp);

            count[0]++;
            for(int i = 0; i < digits.length(); i++) {
                if(count[i] >= len[pos[i]] && i != digits.length() - 1) {
                    count[i] = 0;
                    count[i + 1]++;
                }
            }
        }
        
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(k^n), k is the max mapping of each digits, n is max number of digits

# Note & Tips

1. Be careful of runtime error.