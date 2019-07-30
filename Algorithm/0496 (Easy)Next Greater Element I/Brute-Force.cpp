class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        bool isfound = false;
        bool bad = false;
        vector<int> res;
        for(auto x : nums1)
        {
            isfound = false;
            bad = false;
            for(auto y : nums2)
            {
                if(isfound && y > x)
                {
                    bad = true;
                    res.push_back(y);
                    break;
                }
                if(y == x)
                    isfound = true;
            }
            if(!bad)
                res.push_back(-1);
        }
        return res;
    }
};
