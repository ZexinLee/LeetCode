class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        bool isAna = true;
        
        for(int i = 0; i < s.length(); i++)
            m[s[i]]++;
        for(int i = 0; i < t.length(); i++)
            if(m.find(t[i]) != m.end())
                m[t[i]]--;
            else
                isAna = false;
        for(auto &v : m)
            if(v.second != 0)
                isAna = false;
        return isAna;
    }
};
