class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int key = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[i].size() / 2; j++)
            {
                key = A[i][j];
                A[i][j] = A[i][A[i].size() - 1 - j];
                A[i][A[i].size() - 1 - j] = key;
            }
        }
        for(auto &v : A)
            for(auto &q : v)
                q = (!q);
        return A;
    }
};
