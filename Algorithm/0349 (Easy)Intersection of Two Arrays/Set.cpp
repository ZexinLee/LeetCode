class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> anslist;
        set<int> test;
        set<int> ans;
        for(auto &v : nums1)
            test.insert(v);
        for(auto &v : nums2)
            if(test.count(v))
                ans.insert(v);
        for(auto &v : ans)
            anslist.push_back(v);
        return anslist;
    }
};
