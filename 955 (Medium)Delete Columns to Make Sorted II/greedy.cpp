class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        int row = A.size();
        if(row == 0) return res;
        int col = A[0].size();
        vector<string> str(row, ""); // store intermediate results
        for(int j = 0; j < col; j++) {
            bool flag = true;
            for(int i = 0; i < row; i ++) // step 1: add cur char
                str[i] += A[i][j];
            for(int i = 1; i < row; i ++) // step 2: judge on str
               if(str[i] < str[i-1]) {
                   flag = false;
                   break;
                }
            if(!flag)
                for(int i = 0; i < row; i ++) //step 3:remove the char if false
                    str[i].pop_back();
        }
        res = col - str[0].size();
        return res;
    }
};
