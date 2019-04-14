class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(haystack.length() < needle.length())
            return -1;
        int i = 0;
        bool isfound = false;
        for(; i < haystack.length() - needle.length() + 1; i++)
        {
            for(int j = 0; j < needle.length(); j++)
            {
                if(haystack[i + j] != needle[j])
                    break;
                if(j == needle.length() - 1)
                {
                    isfound = true;
                    goto flag;
                }
            }
        }
        
        flag:return (isfound) ? i : -1;
    }
};