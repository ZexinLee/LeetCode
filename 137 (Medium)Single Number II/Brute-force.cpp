class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int temp = nums[0], count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(count==2){
                count = 0;
                temp = nums[i];
                continue;
            }
            if(nums[i]==temp)
                count++;
            else
                break;
        }
        return temp;
    }
};