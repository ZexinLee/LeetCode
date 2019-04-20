class Solution {
public:
    void generate(vector<long long> &ans) {
        long long max = INT_MAX;
        long long minbound = *(ans.end() - 1);
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] * 2 < max && ans[i] * 2 > minbound)
                max = ans[i] * 2;
            if(ans[i] * 3 < max && ans[i] * 3 > minbound)
                max = ans[i] * 3;
            if(ans[i] * 5 < max && ans[i] * 5 > minbound)
                max = ans[i] * 5;
        }
        ans.push_back(max);
    }
    
    int nthUglyNumber(int n) {
        vector<long long> ans;
        ans.push_back(1);
        for(int i = 1; i < n; i++)
            generate(ans);
        return *(ans.end() - 1);
    }
};