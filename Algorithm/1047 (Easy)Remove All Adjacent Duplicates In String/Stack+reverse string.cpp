class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        string ans = "";
        for(char c : S) {
            if(s.empty()) {
                s.push(c);
            } else {
                if(s.top() == c) {
                    s.pop();
                } else {
                    s.push(c);
                }
            }
        }
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        char temp;
        for(int i = 0; i < ans.length()/2; i++) {
            temp = ans[i];
            ans[i] = ans[ans.length() - 1 - i];
            ans[ans.length() - 1 - i] = temp;
        }
        return ans;
    }
};