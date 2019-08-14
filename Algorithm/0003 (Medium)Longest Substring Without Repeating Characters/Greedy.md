# Algorithm

Greedy algorithm

To keep longest substring length and content during traversal origin string. -> Also, the method can be called `"Sliding Windows"`.

# Better Solution

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=s.size();
        if(length==0){
            return 0;
        }
        int sublength=1;// Calculate the length of string with no-repeating character
        int value[100];
        int left=0;
        int right=1;
        int Max=1;// Get the max length of string
        bool isprime=true;
        int j=0;
        for(int i=1;i<length;i++){
            right=i;
            isprime=true;
            for(j=left;j<right;j++){
                if(s[j]==s[right]){
                    isprime=false;
                    break;
                }
            }
            if(isprime){
                sublength=right-left+1;
                Max=max(Max,sublength);
            }
            else{
                left=j+1;
            }
        }
        return Max;
    }
        
        
};
```

Use sliding windows check and no need to use map/hashmap, time complexity O(n).

(The best run time solution in the leetcode)

# Performance

Runtime: 48 ms, faster than 21.22% of C++ online submissions for Longest Substring Without Repeating Characters.

Memory Usage: 15.9 MB, less than 16.42% of C++ online submissions for Longest Substring Without Repeating Characters.

# Time Spent

~

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> hashset;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            if (hashset.find(s[j])==hashset.end()){
                hashset.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else {
                hashset.erase(s[i++]);
            }
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

If using map, O(nlogk). n is the length of input string, k is 26.

If using hashmap, O(n).

# Note & Tips

1. Although hashmap is O(1) but it has similar performance to ordered_map with O(logn), in this question, its no need to use hashmap/map to build an dictionary since true/false relation can be easily checked by greedy algorithm.