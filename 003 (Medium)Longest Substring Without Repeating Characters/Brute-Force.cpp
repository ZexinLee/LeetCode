class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) 
            for (int j = i; j <= n; j++)
                if (allUnique(s, i ,j)) ans = max(ans, j - i);
        return ans;
    }
    
    bool allUnique(string s, int start, int end) {
        set<char> hashset;
        set<char>::iterator it;
        for (int i = start; i < end; i++) {
            char ch = s[i];
            it = hashset.find(ch);
            if(it!=hashset.end()) return false;
            hashset.insert(ch);
        }
        return true;
    }
};