class Solution {
public:
    int lengthOfLastWord(string s) {
        int all = s.length();
        int count = 0;
        bool ifallspace = true;
        
        for(int i = all - 1; i >= 0; i--)
        {
            if(ifallspace && s[i] == ' ')
            {
            }
            else if(s[i] == ' ')
            {
                break;
            }
            else
            {
                ifallspace = false;
                count++;
            }
        }
        return count;
    }
};