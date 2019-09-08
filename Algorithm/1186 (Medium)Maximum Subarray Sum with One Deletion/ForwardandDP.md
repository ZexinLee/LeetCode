# Algorithm

Forwarding, DP

## Hint

How to solve this problem if no deletions are allowed ?

Try deleting each element and find the maximum subarray sum to both sides of that element.

To do that efficiently, use the idea of [Kadane's algorithm](https://www.jianshu.com/p/89939a9dc3e1).

## Solution

- This problem is kind a modifiled version from Kenede's algorithm. see [here](https://en.wikipedia.org/wiki/Maximum_subarray_problem)

- We calculate the maximum subarray sum foward and backward

- Picture below shows how it goes

- The picture of explanation is shown as below:

  

# Better Solution

```c++
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> fw(n,0);
        vector<int> bw(n,0);
        int cur_max=arr[0],max_so_far=arr[0];
        fw[0]=arr[0];
        for(int i=1;i<n;i++){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            fw[i]=cur_max;
        }
        cur_max=max_so_far=bw[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            bw[i]=cur_max;
        }
        int res=max_so_far;
        for(int i=1;i<n-1;i++)
            res=max(res,fw[i-1]+bw[i+1]);
        return res;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 40 ms, faster than 100.00% of C++ online submissions for Maximum Subarray Sum with One Deletion.

Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for Maximum Subarray Sum with One Deletion.

# Time Spent

Not Done

# Times of Wrong Answer

7

# Solution

```c++
~
```

The code of AC solution

# Time Complexity

Brute Force: O(n^2)

Forwarding&DP: O(n)

# Note & Tips

1. some tips used in the solving of this question.