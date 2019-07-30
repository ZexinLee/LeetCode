class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        typedef long long ll;
        vector<ll> sums;
        int count = 0;
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return (nums[0] == k) ? 1 : 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
                sums.push_back(nums[0]);
            else
                sums.push_back(nums[i] + sums[i - 1]);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                for(int j = i; j < nums.size(); j++)
                {
                    if(sums[j] == k)
                        count++;
                }
            }
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(sums[j] - sums[i] == k)
                {
                    count++;
                    cout << i << " " << j << " " << endl;
                }
            }
        }
        return count;
    }
};
