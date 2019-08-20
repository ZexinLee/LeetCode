# Algorithm

Hashmap

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 72 ms, faster than 83.41% of C++ online submissions for Find Words That Can Be Formed by Characters.

Memory Usage: 22.8 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.

# Time Spent

5 min 30 seconds

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m;
        for(int i = 0; i <= 25; i++) {
            m['a' + i] = 0;
        }
        for(char c : chars) {
            m[c]++;
        }
        int ans = 0;
        for(string s : words) {
            vector<int> temp(26,0);
            for(char c : s) {
                if(c >= 'a' && c <= 'z') {
                    temp[c - 'a']++;
                }
            }
            for(int i = 0; i <= 25; i++) {
                if(temp[i] > m['a' + i]) {
                    goto flag;
                }
            }
            ans += s.length();
            continue;
            flag: continue;
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

TODO

# Note & Tips

1. Simple use of hashmap.