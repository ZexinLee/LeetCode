class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapping1;
        map<char, char> mapping2;
        for(int i = 0; i < s.length(); i++)
        {
            if(mapping1.find(s[i]) == mapping1.end() && mapping2.find(t[i]) == mapping2.end())
            {
                mapping1[s[i]] = t[i];
                mapping2[t[i]] = s[i];
            }
            else if(mapping1.find(s[i]) == mapping1.end() || mapping2.find(t[i]) == mapping2.end())
            {
                return false;
            }
            else if(mapping1[s[i]] != t[i] || mapping2[t[i]] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
