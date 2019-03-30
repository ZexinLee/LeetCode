class Solution {
public:
    int romanToInt(string s) {
        map<char,int> vals;
        int ans = 0;
        vals['M'] = 1000;
        vals['D'] = 500;
        vals['C'] = 100;
        vals['L'] = 50;
        vals['X'] = 10;
        vals['V'] = 5;
        vals['I'] = 1;
        
        for(int i = 0; i < s.length() - 1; i++)
        {
            if(vals[s[i]] < vals[s[i+1]])
            {
                ans -= vals[s[i]];
            }
            else
            {
                ans += vals[s[i]];
            }
        }
        ans += vals[s[s.length() - 1]];
        return ans;
    }
};