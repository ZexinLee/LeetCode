# Algorithm

String and math

Using prefix vector to store the number of letters, to reduce time complexity. How many letters details of A substring can be calculated by subtracting from to prefix vector.  

# Better Solution

```c++
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // prefix vector
        vector<vector<int>> vec;
        
        // current sum
        vector<int> tmp(26, 0);
        vec.push_back(tmp);
        
        // fill prefix vector
        for(int i=0; i<s.size(); i++){
            tmp[s[i]-'a']++;
            vec.push_back(tmp);
        }
        
        vector<bool> ans;
        for(auto const& q: queries){
            int lo = q[0], hi = q[1], k = q[2];
            vector<int> cnt = vec[hi+1];
            
            // odd = elements to be matched
            int odds = 0, sum = 0;
            
            // compute letter count from prefix array
            for(int i=0; i<26; i++){
                cnt[i]-=vec[lo][i];
                sum += cnt[i];
                odds += (cnt[i]%2);
            }
            
            // if total sum of elements is odd, decrement odds--
            // we can change odds/2 elements to match other odds/2 elements so odds/2<=k or rewriting it as odds<=2*k(considering odds can be odd ^_^)
            ans.push_back((odds-=(sum%2))<= k*2?true:false);
            
        }
        return ans;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 208 ms, faster than 91.33% of C++ online submissions for Can Make Palindrome from Substring.

Memory Usage: 99.9 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.

# Time Spent

Not Done

# Times of Wrong Answer

5

# Solution

```c++
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        int a[26];
        for(auto q : queries) {
            int count = 0;
            // int i = q[0], j = q[1];
            // while(i < j) {
            //     if(s[i++] != s[j--]) {
            //         count++;
            //     }
            // }
            for(int i = 0; i <= 25; i++) {
                a[i] = 0;
            }
            for(int i = q[0]; i <= q[1]; i++) {
                a[s[i] - 'a']++;
            }
            for(int i = 0; i <= 25; i++) {
                if(a[i] % 2 != 0) {
                    count++;
                }
            }
            if((q[1] - q[0]) / 2 * 2 == (q[1] - q[0])) {
                count--;
            }
            if(count <= q[2] * 2) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
            
        return ans;
    }
};
```

TLE

# Time Complexity

Best answer: O(n) beats 91%

My answer: O(n^2) TLE

# Note & Tips

1. Not done because of TLE, 29/30 passing.
2. Use cache to accelerate and enhance time complexity to O(n).
3. Use vector instead of hashmap to accelerate.