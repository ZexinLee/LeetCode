class Solution {
public:
    void reverse(string &s, int begin, int end) {
        char a;
        
        if(end > s.length() - 1)
            end = s.length() - 1;
        while(end > begin) {
            a = s[end];
            s[end--] = s[begin];
            s[begin++] = a;
        }
    }
    
    string reverseWords(string s) {
        int begin = 0, end = 0;
        bool isreverse = false;
        while(end < s.length()) {
            if(!isreverse) {
                if(s[end] == ' ')
                    begin = ++end;
                else {
                    isreverse = true;
                    ++end;
                }
            }
            else {
                if(s[end] == ' ') {
                    reverse(s, begin, end - 1);
                    begin = ++end;
                    isreverse = false;
                }
                else {
                    ++end;
                }
            }
        }
        if(isreverse)
            reverse(s, begin, end);
        return s;
    }
};