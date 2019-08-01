# Algorithm

Use stack to get non-adjacent duplicates string.

After that, the output string should be reversed.

# Better Solution

```c++
class Solution {
public:
    string removeDuplicates(string S) {
        std::string res("");
        for(char &c : S){
            if(res.size() && c == res.back()){
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};
```



# Performance

Runtime: 28 ms, faster than 49.72% of C++ online submissions for Remove All Adjacent Duplicates In String.

Memory Usage: 13.2 MB, less than 100.00% of C++ online submissions for Remove All Adjacent Duplicates In String.

# Time Spent

4 min 51 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        string ans = "";
        for(char c : S) {
            if(s.empty()) {
                s.push(c);
            } else {
                if(s.top() == c) {
                    s.pop();
                } else {
                    s.push(c);
                }
            }
        }
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        char temp;
        for(int i = 0; i < ans.length()/2; i++) {
            temp = ans[i];
            ans[i] = ans[ans.length() - 1 - i];
            ans[ans.length() - 1 - i] = temp;
        }
        return ans;
    }
};
```

# Time Complexity

O(n)

# Note & Tips

1. Use `std::reverse` can accelerate.
2. To reversely insert string can be quicker.
3. Use string built-in function `back` and `size` can simulate stack and achieve best performance.