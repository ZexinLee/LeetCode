class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
		//vector<vector<int>> ret;
		int len = nums.size();
		if(len == 0) 
            return 0;
        else if(len == 1)
            return nums[0];
        else if(len == 2)
            return nums[1] + nums[0];

        int temp = 1000000, ans = 1000000;
        
		for (int i = 0; i < len - 2; ++i){
			if (i>0 && nums[i] ==nums[i-1]) continue;//to avoid duplicates through first value
			//if(nums[i]+nums[i+1]+nums[i+2]>0) break;//no solution
			//if(nums[i]+nums[len-2]+nums[len-1]<0) continue;//"i" is too small

			int j = i + 1, k = len - 1;
			while(j < k){
				int sum = nums[i] + nums[j] + nums[k];
                temp = (abs(temp - target) > abs(sum - target)) ? sum : temp;
				if (sum > target) --k;
				else if (sum < target) ++j;
				else 
				{
					return target;
				}
			}
            ans = (abs(ans - target) > abs(temp - target)) ? temp : ans;
		}
		return ans;
    }
};