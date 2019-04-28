class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        long long pos = 1;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            ans += ((s[i] - 'A' + 1) * pos);
            pos *= 26;
        }
        return ans;
    }
};
