# Algorithm

Brute Force or Min array

# Better Solution

```c++
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.length();
        int count;
        vector<int> vec(len,20000);
        for(int i=0;i<len;i++)
        {
            if(S[i] == C)
                vec[i] = 0;
        }
        for(int i=0;i<len;i++)
        {
            if(vec[i] == 0)
            {
                count =1;
                for(int j = i-1;j>= 0 ;j--)
                {
                    if(vec[j] > count)
                        vec[j] = count;
                    count++;
                }
                count = 1;
                for(int j = i+1;j<len ;j++)
                {
                    if(vec[j] > count)
                        vec[j] = count;
                    count++;
                }
            }
        }
        return vec;
    }
};
```

(The best run time solution in the leetcode)

Runtime: 12 ms, faster than 57.45% of C++ online submissions for Shortest Distance to a Character.

Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Shortest Distance to a Character.

# Performance

Runtime: 12 ms, faster than 57.45% of C++ online submissions for Shortest Distance to a Character.

Memory Usage: 9 MB, less than 80.00% of C++ online submissions for Shortest Distance to a Character.

# Time Spent

6 min 52 second

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> pos;
        vector<int> ans;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == C) {
                pos.push_back(i);
            }
        }
        for(int i = 0; i < S.length(); i++) {
            int temp = INT_MAX;
            for(int j = 0; j < pos.size(); j++) {
                temp = min(abs(pos[j] - i),temp);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(n^2) for brute force and O(nlogn) for min array

# Note & Tips

1. Simple brute-force can pass all tests