class Solution {
public:
    static bool cmp(vector<int> x,vector<int> y)
    {
        return x[0]*x[0] + x[1]*x[1] < y[0]*y[0] + y[1]*y[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), cmp);
        
        vector<vector<int>> ans;
        for(int i = 0; i < K; i++)
                ans.push_back(points[i]);
        
        return ans;
    }
};