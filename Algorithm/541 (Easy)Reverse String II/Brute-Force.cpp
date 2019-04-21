class Solution {
public:
    void reverse(string &s, int pos, int len) {
        int begin = pos, end = pos + len - 1;
        cout << begin << end << " ";
        char a;
        if(end > s.length() - 1)
            end = s.length() - 1;
        while(end > begin)
        {
            a = s[end];
            s[end--] = s[begin];
            s[begin++] = a;
        }
    }
    
    string reverseStr(string s, int k) {
        for(int i = 0; i <= s.length() / (k * 2); i++)
            reverse(s, i*k*2, k);
        return s;
    }
};