# Algorithm

Sort + Brute-Force

# Better Solution

```c++
~
```

(The best run time solution in the leetcode)

# Performance

Runtime: 88 ms, faster than 98.08% of C++ online submissions for 3Sum.

Memory Usage: 14.5 MB, less than 100.00% of C++ online submissions for 3Sum.

# Time Spent

From the beginning of the question to the time of the first AC.

# Times of Wrong Answer

3

# Solution

```c++
class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums)	{
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		int len = nums.size();
		if(len<3) return ret;

		for (int i = 0; i < len - 2; ++i){
			if (i>0 && nums[i] ==nums[i-1]) continue;//to avoid duplicates through first value
			if(nums[i]+nums[i+1]+nums[i+2]>0) break;//no solution
			if(nums[i]+nums[len-2]+nums[len-1]<0) continue;//"i" is too small

			int j = i + 1, k = len - 1;
			while(j < k){
				int sum = nums[i] + nums[j] + nums[k];
				if (sum > 0) --k;
				else if (sum < 0) ++j;
				else 
				{
					ret.push_back({ nums[i], nums[j], nums[k] });
					do{ ++j; }while(nums[j] == nums[j-1] && j < k);
					do{ --k; }while(nums[k] == nums[k+1] && j < k);
				}
			}
		}
		return ret;
	}
};
```

The code of AC solution

# Time Complexity

Sort -> O(nlogn)

# Note & Tips

1. This can be simply solved by sort.