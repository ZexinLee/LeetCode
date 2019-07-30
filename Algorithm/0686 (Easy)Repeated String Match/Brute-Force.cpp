class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        const int n_A=A.size(),n_B=B.size();
        string a=A;
        int ans=1;
        while(a.size()<n_B) {a=a+A;ans++;}//step 1
        int stop=ans+2,f=0;
        while(ans<stop) //step 2
        {
            f=a.find(B);
            if(f>=0&&f<a.size())return ans;
            a=a+A;
            ans++;
        }
        return -1;
    }
};