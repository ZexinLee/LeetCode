class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto &v : A)
            v *= v;
        sort(A.begin(), A.end());
        return A;
    }
};
