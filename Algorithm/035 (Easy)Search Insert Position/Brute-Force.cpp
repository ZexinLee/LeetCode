class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int low=-1, up=nums.size();
        while(up-low>1)
        {
            int mid = int( (low+up)/2 );
            if (nums[mid]>=target)
                up = mid;
            else
                low = mid;
        }
        return up;
    }
};