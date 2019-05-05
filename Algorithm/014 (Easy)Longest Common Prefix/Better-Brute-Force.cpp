class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        if(N == 0)
            return "";
        if(N == 1)
            return strs[0];
        
        sort(strs.begin(), strs.end());
        int i = 0, j = 0;
        while(i < strs[0].length() && j < strs[N-1].length())
        {
            if(strs[0][i] != strs[N-1][j])
                break;
            i++, j++;
        }
        return strs[0].substr(0,i);
    }
};
