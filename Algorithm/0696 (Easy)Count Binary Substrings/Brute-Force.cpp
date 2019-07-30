class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0,n = s.size(),i=0,pre=0;
        char temp = s[0];       
        while(i<n){
            int j = i;
            while(j<n&&s[j]==temp)   j++;
            if(j<n) temp = s[j];
            ans+=min(j-i,pre);
            pre = j-i;
            i = j;
        }
        return ans;
    }
};
