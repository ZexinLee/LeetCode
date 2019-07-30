class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int ans[10] = {0};
        int record[4] = {-1};
        string sbcym = "";
        for(int i = 0; i < 4; i++)
            ans[A[i]]++;
        for(int i = 0; i < 24; i++)
            for(int j = 0; j < 60; j++)
            {
                int count[4] = {0};
                int countcount[10] = {0};
                count[0] = i / 10;
                count[1] = i % 10;
                count[2] = j / 10;
                count[3] = j % 10;
                bool tag = true;
                for(int k = 0; k < 4; k++)
                    countcount[count[k]]++;
                for(int k = 0; k < 10; k++)
                    if(ans[k] != countcount[k])
                        tag = false;
                if(tag)
                {
                    int pos = 0;
                    for(int k = 0; k < 4; k++)
                        record[pos++] = count[k];
                }
            }
        if(record[0] == -1)
            return sbcym;
        else
        {
            sbcym += (record[0] + '0');
            sbcym += (record[1] + '0');
            sbcym += ':';
            sbcym += (record[2] + '0');
            sbcym += (record[3] + '0');
        }
        return sbcym;
    }
};
