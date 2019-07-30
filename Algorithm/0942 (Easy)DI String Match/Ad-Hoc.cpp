class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int lo = 0, hi = N;
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'I')
                ans.push_back(lo++);
            else
                ans.push_back(hi--);
        }
        ans.push_back(lo);
        return ans;
    }
};