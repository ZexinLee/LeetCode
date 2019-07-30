class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int rot = searchrot(nums,0,nums.size());
        int res;
        res = binarysearch(nums,0,rot+1,target);
        if (res == -1) res = binarysearch(nums,rot+1,nums.size(),target);
        return res;
    }
    int searchrot(vector<int>& nums, int i, int j) {
        int mid;
        while (j-i > 1) {
            mid = (i+j) / 2;
            if (nums[mid] <= nums[i]) j = mid;
            else i = mid;
        }        
        return i;
    }
    int binarysearch(vector<int>& nums, int i, int j, int& target) {
        int mid;
        while (j > i) {
            mid = (i+j)/2;
            if (nums[mid] == target) return mid; 
            if (nums[mid] < target) i= mid+1;
            else j = mid,target;
        }
        return -1;
    }
};