class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> m;
        m['Q'] = 0;
        m['q'] = 0;
        m['W'] = 0;
        m['w'] = 0;
        m['E'] = 0;
        m['e'] = 0;
        m['R'] = 0;
        m['r'] = 0;
        m['T'] = 0;
        m['t'] = 0;
        m['Y'] = 0;
        m['y'] = 0;
        m['U'] = 0;
        m['u'] = 0;
        m['I'] = 0;
        m['i'] = 0;
        m['O'] = 0;
        m['o'] = 0;
        m['P'] = 0;
        m['p'] = 0;
        m['A'] = 1;
        m['a'] = 1;
        m['S'] = 1;
        m['s'] = 1;
        m['D'] = 1;
        m['d'] = 1;
        m['F'] = 1;
        m['f'] = 1;
        m['G'] = 1;
        m['g'] = 1;
        m['H'] = 1;
        m['h'] = 1;
        m['J'] = 1;
        m['j'] = 1;
        m['K'] = 1;
        m['k'] = 1;
        m['L'] = 1;
        m['l'] = 1;
        m['Z'] = 2;
        m['z'] = 2;
        m['X'] = 2;
        m['x'] = 2;
        m['C'] = 2;
        m['c'] = 2;
        m['V'] = 2;
        m['v'] = 2;
        m['B'] = 2;
        m['b'] = 2;
        m['N'] = 2;
        m['n'] = 2;
        m['M'] = 2;
        m['m'] = 2;
        vector<string> ans;
        for(string s : words) {
            bool ifPush = true;
            int tempvalue;
            if(s.length() <= 1) {
                ans.push_back(s);
            } else {
                tempvalue = m[s[0]];
                for(char c : s) {
                    if(tempvalue != m[c]) {
                        ifPush = false;
                        break;
                    }
                }
                if(ifPush) {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};