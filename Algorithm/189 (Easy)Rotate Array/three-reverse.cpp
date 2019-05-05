class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if(!nums.size() || !(k%nums.size())) return;
        
        k %= nums.size();
        
        // move swap the first nums.size()-k and the last k element
        // firstly, reverse the whole arry
        // then reverse the first k part
        // reverse the last nums.size()-k part
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }
};
