class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int>hashmap;
        if (nums1.size() < nums2.size()) swap(nums1, nums2);
        
        for (int i=0; i<nums1.size(); i++) {
            if (hashmap.count(nums1[i]) <= 0)
                hashmap.insert(make_pair(nums1[i], 1));
            else 
                hashmap[nums1[i]] ++;
        }
        
        for (int i=0; i<nums2.size(); i++) {
            if (hashmap.count(nums2[i]) > 0 && hashmap[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                hashmap[nums2[i]] --;
            }
        }
     
        
        return ans;
    }
};
