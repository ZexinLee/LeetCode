class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i : nums) {
            if(s.find(i) == s.end())
                s.insert(i);
            else
                return i;
        }
        return 0;
    }
};
