# Algorithm

Simple use of Stack

# Better Solution

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        
        int temp = x;
        long rNum = 0;
        while (temp > 0) {
            int n = temp % 10;
            temp /= 10;
            rNum = rNum * 10 + n;
        }
    return rNum == x ? true : false;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 48 ms, faster than 5.35% of C++ online submissions for Palindrome Number.

Memory Usage: 21.3 MB, less than 5.45% of C++ online submissions for Palindrome Number.

# Time Spent

4 min 4 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        } else if(x == 0) {
            return true;
        }
        bool result = true;
        vector<int> store;
        stack<int> st;
        while(x > 0) {
            store.push_back(x % 10);
            st.push(x % 10);
            x /= 10;
        }
        vector<int>::iterator it = store.begin();
        while(!st.empty()) {
            if(st.top() != *it) {
                result = false;
                break;
            }
            st.pop();
            it++;
        }
        
        
        return result;
    }
}; 
```

The code of AC solution

# Time Complexity

O(n)

# Note & Tips

1. Don't need construct `stack` object but only to simulate.