class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int pos = 0, temp;
        
        if(asteroids.size() == 0)
            return asteroids;
        
        for(int i = 0; i < asteroids.size(); i++)
        {
            ans.push_back(asteroids[i]);
            while(ans.size() > 1 && *(ans.end()-1) < 0 && *(ans.end()-2) > 0)
                {
                    if(abs(*(ans.end() - 1)) > abs(*(ans.end() - 2)))
                    {
                        temp = *(ans.end() - 1);
                        ans.pop_back();
                        ans.pop_back();
                        ans.push_back(temp);
                    }
                    else if(abs(*(ans.end() - 1)) < abs(*(ans.end() - 2)))
                    {
                        temp = *(ans.end() - 2);
                        ans.pop_back();
                        ans.pop_back();
                        ans.push_back(temp);
                    }
                    else
                    {
                        ans.pop_back();
                        ans.pop_back();
                    }
                }
        }
        
        
        
        return ans;
    }
};