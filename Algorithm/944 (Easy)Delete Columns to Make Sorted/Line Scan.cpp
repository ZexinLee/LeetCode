class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 0 || A[0].length() == 0)
            return 0;
        int count = 0;
        for(int i = 0; i < A[0].length(); i++) {
            for(int j = 0; j < A.size() - 1; j++) {
                if(A[j + 1][i] >= A[j][i]) {
                    
                }
                else {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};