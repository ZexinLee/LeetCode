class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0;
        for (int j = 0; j < n;) {
            if (j == n-1 || chars[j] != chars[j+1]) 
                chars[i++] = chars[j++];
            else {
                int k = j;
                while (j < n && chars[j] == chars[k])
                    j++;
                chars[i++] = chars[k];
                string s = to_string(j-k);
                for (char c:s) chars[i++] = c;
            }
        }
        return i;
    }
};
