# Algorithm

Simple use of multi-level stack

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 4 ms, faster than 67.45% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.

Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.

# Time Spent

12 min 59 second

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    string reverseParentheses(string s) {
        vector<stack<char>> pro;
        int pos = -1;
        string ans = "";
        for(char c : s) {
            if(pos == -1 && c != '(' && c != ')') {
                ans += c;
            } else if(c == '(') {
                pos++;
                if(pro.size() <= pos) {
                    stack<char> s;
                    pro.push_back(s);
                }
            } else if(c == ')') {
                if(pos > 0) {
                    while(!pro[pos].empty()) {
                        pro[pos - 1].push(pro[pos].top());
                        pro[pos].pop();
                    }
                } else {
                    while(!pro[0].empty()) {
                        ans += pro[0].top();
                        pro[0].pop();
                    }
                }
                pos--;
            } else {
                pro[pos].push(c);
            }
        }
        
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Use embedded vector/stack to solve this problem.