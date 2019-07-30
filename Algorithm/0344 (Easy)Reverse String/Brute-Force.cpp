class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin = 0, end = s.size() - 1;
        char a;
        while(end > begin)
        {
            a = s[begin];
            s[begin++] = s[end];
            s[end--] = a;
        }
    }
};