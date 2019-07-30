class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char>mp;
        unordered_set<char>st;
        int i = 0;
        int j = 0;
        int k = 0;
        while (j < str.size() && i < pattern.size()) {
            string token;
            while (j < str.size() && str[j] != ' ') {
                j++;
            }
            token = str.substr(k, j - k);
            j++;
            k = j;
            if (mp.find(token) == mp.end()) {
                if (st.find(pattern[i]) == st.end()) {
                    mp[token] = pattern[i];
                    st.insert(pattern[i]);
                }
                else {
                    return false;
                }

            }
            else if (mp[token] != pattern[i]) {
                return false;
            }
            i++;

        }

        return i < pattern.size() || j < str.size() ? false : true;
        }
}; 