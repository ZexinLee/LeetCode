class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<int> temp;
        
        for(int i = 0; i <= rowIndex; i++)
        {
            for(int j = 0; j < ans.size(); j++)
            {
                if(j == 0)
                    temp.push_back(1);
                else
                {
                    temp.push_back(ans[j] + ans[j - 1]);
                }
            }
            temp.push_back(1);
            ans.clear();
            ans.assign(temp.begin(), temp.end());
            temp.clear();
        }
        return ans;
    }
};