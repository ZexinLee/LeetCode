class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N,0);
        
        int t = 0;
        for (int x: A)
            if (x % 2 == 0) {
                ans[t] = x;
                t += 2;
            }

        t = 1;
        for (int x: A) 
            if (x % 2 == 1) {
                ans[t] = x;
                t += 2;
            }

        return ans;
    }
};
