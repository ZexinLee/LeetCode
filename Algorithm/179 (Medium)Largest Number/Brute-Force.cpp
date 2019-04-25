class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if(nums[0] == 0)
            return "0";
        string res = "";
        for(auto a : nums){
            res += to_string(a);
        }
        return res;
    }
    static bool compare(const int& num1, const int& num2) {  
        string str1 = to_string(num1) + to_string(num2);
        string str2 = to_string(num2) + to_string(num1);
        if(str1 <= str2)
            return false;
        else 
            return true;
    }    
};       
