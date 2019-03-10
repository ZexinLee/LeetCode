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