class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for(int i : A) {
            if(i % 2 == 0) {
                sum += i;
            }
        }
        for(vector<int> i : queries) {
            if(A[i[1]] % 2 == 0 && i[0] % 2 == 0) {
                sum += (i[0]);
            } else if(A[i[1]] % 2 == 0 && i[0] % 2 != 0) {
                sum += (-A[i[1]]);
            } else if(A[i[1]] % 2 != 0 && i[0] % 2 == 0) {
                sum += 0;
            } else if(A[i[1]] % 2 != 0 && i[0] % 2 != 0) {
                sum += (A[i[1]] + i[0]);
            }
            A[i[1]] += i[0];
            ans.push_back(sum);
        }
        return ans;
    }
};