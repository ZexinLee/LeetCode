class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0,b = 0;
        for(int i = 0; i < nums.size(); i++){
            a = a ^ nums[i] & ~b;
            b = b ^ nums[i] & ~a;
        }
        return a|b;
    }
};