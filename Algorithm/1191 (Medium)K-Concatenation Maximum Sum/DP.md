# Algorithm

DP

# Better Solution

```c++
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k == 0 || arr.size() == 0)
            return 0;
        
        int mod = pow(10, 9) + 7;
		
        //Kadane's Algorithm to find min subarray and max subarray:
        int curr_max = INT_MIN, max_seen = INT_MIN;
        int curr_min = INT_MAX, min_seen = INT_MAX;
        for(auto x : arr)
        {
            curr_max = max(curr_max%mod + (x%mod), x);
            max_seen = max(max_seen, curr_max);
            curr_min = min(curr_min%mod + (x%mod), x);
            min_seen = min(curr_min, min_seen);
        }
		
		//Calculate case 3:
        int sumOfKVectors = 0;
        int total = accumulate(arr.begin(), arr.end(), 0);
		
		//Calculate the total sum of K input arrays
        for(int i = 0; i < k; i++)
            sumOfKVectors = (sumOfKVectors + (total % mod)) % mod;
        
		//see if removing elements from the head will result in an increased total:
        int totalMaxSeenKVectors = sumOfKVectors;
        for(int i = 0; i < arr.size(); i++)
        {
            totalMaxSeenKVectors = max(totalMaxSeenKVectors, sumOfKVectors - arr[i]);
            sumOfKVectors -= arr[i];
        }
		 
		//see if removing elements from the back will result in an increased total:
        int removeFromFront = totalMaxSeenKVectors;
        for(int i = arr.size()-1; i >= 0; i--)
        {
            totalMaxSeenKVectors = max(totalMaxSeenKVectors, removeFromFront - arr[i]);
            removeFromFront -= arr[i];
        }
        
		//return the max of case 1, case2, or case3
        return max(max_seen, max(totalMaxSeenKVectors, total-min_seen));
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 64 ms, faster than 50.00% of C++ online submissions for K-Concatenation Maximum Sum.

Memory Usage: 14.4 MB, less than 100.00% of C++ online submissions for K-Concatenation Maximum Sum.

# Time Spent

Not Done

# Times of Wrong Answer

2

# Solution

```c++

```

The code of AC solution

# Time Complexity

O(n), n is the length of single array.

# Note & Tips

1. It can use long long multiplication template.