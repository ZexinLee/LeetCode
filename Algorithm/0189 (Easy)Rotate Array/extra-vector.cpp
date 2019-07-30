 class Solution {
    public:
    
        void rotate(vector<int>& nums, int k) 
        {
            if( !nums.size() || !( k%nums.size() ) ) return;
            
            k %= nums.size();
            
            vector<int> memo(nums.begin(), nums.end()-k);
            nums = vector<int>(nums.end()-k, nums.end());
            for(int i=0; i<memo.size(); i++)
                nums.push_back(memo[i]);
        }
    };
