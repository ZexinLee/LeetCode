class Solution {
public:
 int removeDuplicates(vector<int>& nums) {
        if(empty(nums))
            return 0;
        int writeIndex = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[writeIndex-1]!=nums[i]){
                nums[writeIndex++] = nums[i];
            }
        }
        return writeIndex;
    }
};