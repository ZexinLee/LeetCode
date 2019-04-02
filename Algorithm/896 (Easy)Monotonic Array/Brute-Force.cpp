class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int status = 0;
        int len = A.size();
        int temp = A[0];
        bool judge = true;
        for(int i = 0; i < len; i++)
        {
            if(A[i] == temp)
            {
                
            }
            else if(A[i] > temp)
            {
                temp = A[i];
                if(status == 0)
                    status = 1;
                else if(status != 1)
                {
                    judge = false;
                    break;
                }
            }
            else if(A[i] < temp)
            {
                temp = A[i];
                if(status == 0)
                    status = 2;
                else if(status != 2)
                {
                    judge = false;
                    break;
                }
            }
        }
        return judge;
    }
};