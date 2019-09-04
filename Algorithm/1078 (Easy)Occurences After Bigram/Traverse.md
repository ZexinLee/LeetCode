# Algorithm

Linear Traverse

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Occurrences After Bigram.

Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Occurrences After Bigram.

# Time Spent

From the beginning of the question to the time of the first AC.

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    vector<string> split(const string& str, const string& delim) {  
        vector<string> res;  
        if("" == str) return res;   
        char * strs = new char[str.length() + 1] ;
        strcpy(strs, str.c_str());   

        char * d = new char[delim.length() + 1];  
        strcpy(d, delim.c_str());  

        char *p = strtok(strs, d);  
        while(p) {  
            string s = p;
            res.push_back(s);
            p = strtok(NULL, d);  
        }  

        return res;  
    }
    
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> prepare = split(text, " ");
        vector<string> ans;
        for(int f = 0; f < prepare.size() - 2; f++) {
            if(prepare[f] == first && prepare[f + 1] == second) {
                ans.push_back(prepare[f + 2]);
            }
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

O(cn(len-c)), c is length of chain(in this question c = 2), len is the length of text fragment.

# Note & Tips

1. Simple linear traverse can solve this question but if the query chain becomes long, it will cause time complexity comes to O(n^2), which leads to TLE.
2. In this question, the template of `split()` has been added into the template.
3. In addition, a complex version of this question can be solved by hash table.