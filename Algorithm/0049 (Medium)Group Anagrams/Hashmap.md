# Algorithm

Hash map

# Better Solution

```c++
constexpr array<int, 26> PRIMES = {
   2,  3,  5,  7, 11, 13, 17, 19, 23, 29, 31, 37,  41,
  43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
};

struct Solution {
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<uint32_t, vector<string>> M;
    
    for (auto& str : strs) {
      uint32_t p = 1;
      for (char c : str)
        p *= PRIMES[c-'a'];
      M[p].push_back(move(str));
    }
    
    vector<vector<string>> result;
    result.reserve(M.size());
    for (auto it = M.begin(); it != M.end(); ++it)
      result.push_back(move(it->second));
    return result;
  }
};

// class Solution {
// public:
//   vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     const int N = strs.size();
    
//     unordered_map<string, vector<string>> M;
    
//     for (auto& str : strs) {
//       string sorted_str = str;
//       sort(sorted_str.begin(), sorted_str.end());
//       M[sorted_str].push_back(str);
//     }
    
//     vector<vector<string>> result;
//     result.reserve(M.size());
//     for (auto it = M.begin(); it != M.end(); ++it)
//       result.push_back(move(it->second));
//     return result;
//   }
// };

static auto const magic = []{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();
```

16 ms performance

Generating prime number is OK.

(The best run time solution in the leetcode)

# Performance

Runtime: 52 ms, faster than 34.48% of C++ online submissions for Group Anagrams.

Memory Usage: 20.7 MB, less than 31.34% of C++ online submissions for Group Anagrams.

# Time Spent

14 min 23 seconds

# Times of Wrong Answer

~

# Solution

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<char, int> m;
        for(int i = 0; i <= 25; i++) {
            m['a' + i] = rand();
        }
        long long temp = 0;
        vector<vector<string>> ans;
        map<long long, vector<string>> tempans;
        for(string s : strs) {
            temp = 0;
            for(char c : s) {
                if(m.find(c) != m.end()) {
                    temp += m[c];
                }
            }
            if(tempans.find(temp) != tempans.end()) {
                tempans[temp].push_back(s);
            } else {
                tempans[temp] = vector<string>();
                tempans[temp].push_back(s);
            }
        }
        for(auto p : tempans) {
            vector<string> v;
            for(string s : p.second) {
                v.push_back(s);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
```

The code of AC solution

# Time Complexity

Briefly analysis of the time complexity

# Note & Tips

1. Generating prime number is OK in this question, no need to call `rand()` API.
2. Turn off io sync to accelerate.