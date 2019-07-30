class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> head;
        vector<int> tail;
        int found = -1;
        for(int i = 0; i < trust.size(); i++)
        {
            head.push_back(trust[i][0]);
            tail.push_back(trust[i][1]);
        }
        for(int i = 1; i <= N; i++)
        {
            if(count(tail.begin(), tail.end(), i) == N - 1)
            {
                if(count(head.begin(), head.end(), i) == 0)
                {
                    found = i;
                    break;
                }
                else
                    break;
            }
        }
        return found;
    }
};
