class Solution {
public:
    vector<int> constructRectangle(int area) {
        double uplimit = sqrt(area);
        int first = 0, second = 0, now = 1;
        vector<int> ans;
        while(now <= uplimit)
        {
            if(area % now == 0)
            {
                first = area / now;
                second = now;
            }
            now++;
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};