class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char, int> m;
        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            m['a'+i] = INT_MAX;
        }
        for(string s : A) {
            map<char, int> temp;
            for(char c : s) {
                if(temp.find(c) != temp.end()) {
                    temp[c]++;
                } else {
                    temp[c] = 1;
                }
            }
            for(auto& p : m) {
                if(temp.find(p.first) == temp.end()) {
                    p.second = 0;
                }
                else {
                    p.second = min(p.second, temp[p.first]);
                }
            }
        }
        for(auto p : m) {
            if(p.second != INT_MAX) {
                for(int i = 0; i < p.second; i++) {
                    ans.push_back(string(1,p.first));
                }
            }
        }
        return ans;
    }
};