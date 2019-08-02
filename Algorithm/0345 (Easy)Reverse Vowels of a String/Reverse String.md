# Algorithm

Get all index of vowels and reverse

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 8 ms, faster than 93.50% of C++ online submissions for Reverse Vowels of a String.

Memory Usage: 10.6 MB, less than 21.71% of C++ online submissions for Reverse Vowels of a String.

# Time Spent

7 min 38 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> toreverse;
        char c;
        for(int i = 0; i < s.length(); i++) {
            c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                toreverse.push_back(i);
            }
        }
        for(int i = 0; i < toreverse.size()/2; i++) {
            c = s[toreverse[i]];
            s[toreverse[i]] = s[toreverse[toreverse.size() - 1 - i]];
            s[toreverse[toreverse.size() - 1 - i]] = c;
        }
        return s;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Simple reverse