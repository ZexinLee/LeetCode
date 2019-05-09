class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<char> temp;
        bool isnew = false;
        int lcount = 0, rcount = 0;
        string ans = "";
        for(int i = 0; i < S.length(); i++)
        {
            temp.push_back(S[i]);
            if(S[i] == '(')
                lcount++;
            else
                rcount++;
            if(lcount == rcount)
                isnew = true;
            if(isnew)
            {
                for(int j = 1; j < temp.size() - 1; j++)
                    ans += temp[j];
                temp = vector<char>();
                isnew = false;
                lcount = 0;
                rcount = 0;
            }
        }
        return ans;
    }
};
