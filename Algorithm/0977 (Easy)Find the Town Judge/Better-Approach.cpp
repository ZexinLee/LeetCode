class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int head[N + 1] = {0};
        int tail[N + 1] = {0};
        int found = -1;
        for(int i = 0; i < trust.size(); i++)
        {
            head[trust[i][0]]++;
            tail[trust[i][1]]++;
        }
        for(int i = 1; i <= N; i++)
        {
            if(tail[i] == N - 1 && head[i] == 0)
                found = i;
        }
        return found;
    }
};
