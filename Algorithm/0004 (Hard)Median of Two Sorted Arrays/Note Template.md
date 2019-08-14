# Algorithm

Binary Search, divide and conquer

# Better Solution

```c++
/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (26.20%)
 * Total Accepted:    430.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Devide & Conquer, O((M+N)log(m+n))
        int m = nums1.size(), n = nums2.size();
        int k = m + n;
        if(k % 2)
            return helper(nums1, 0, m, nums2, 0, n, k / 2 + 1);
        else
            return (helper(nums1, 0, m, nums2, 0, n, k / 2) + helper(nums1, 0, m, nums2, 0, n, k / 2 + 1)) / 2.0;
    }

    double helper(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k)
    {
        int m = r1 - l1, n = r2 - l2;
        if(m > n)
            return helper(nums2, l2, r2, nums1, l1, r1, k);
        if(m == 0) return nums2[l2 + k - 1];
        if(k == 1) return min(nums1[l1], nums2[l2]);

        int p1 = min(k/2, m), p2 = k - p1;
        if(nums1[l1 + p1 - 1] < nums2[l2 + p2 - 1])
            return helper(nums1, l1 + p1, r1, nums2, l2, r2, k - p1);
        else if(nums1[l1 + p1 - 1] > nums2[l2 + p2 - 1])
            return helper(nums1, l1, r1, nums2, l2 + p2, r2, k - p2);
        return nums1[l1 + p1 - 1];
    }
};

```

(The best run time solution in the leetcode)

# Performance

The best approach performance

Runtime: 12 ms, faster than 98.37% of C++ online submissions for Median of Two Sorted Arrays.

Memory Usage: 9.8 MB, less than 61.86% of C++ online submissions for Median of Two Sorted Arrays.

# Time Spent

~

# Times of Wrong Answer

0

# Solution

```c++
// Round-robin

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double pos1,temp;
        int x = 0, y = 0;
        if(sum >> 1 << 1 == sum){
            for(int i = 0; i < sum / 2 + 1; i++){
                if(x < nums1.size() && y < nums2.size()){
                    if(nums1[x] < nums2[y])
                        temp = nums1[x++];
                    else
                        temp = nums2[y++];
                }
                else if(x < nums1.size())
                    temp = nums1[x++];
                else
                    temp = nums2[y++];
                if(i == sum / 2 - 1)
                    pos1 = temp;
                if(i == sum / 2)
                    return (pos1+temp)/2;
            }
        }
        else{
            for(int i = 0; i < sum / 2 + 1; i++){
                if(x < nums1.size() && y < nums2.size()){
                    if(nums1[x] < nums2[y])
                        temp = nums1[x++];
                    else
                        temp = nums2[y++];
                }
                else if(x < nums1.size())
                    temp = nums1[x++];
                else
                    temp = nums2[y++];
                if(i == sum / 2)
                    return temp;
            }
        }
        
    return 0;
    }
};
```

The code of AC solution

# Time Complexity

m, n represents the length of two input array.

If using brute-force, just very straight forward merge and quick sort. O((m+n)log(m+n))

If using round-robin, to simply traverse two input array, can reach an constant time complexity. O(m+n)

If using binary search, can reach a log time complexity. O(log(m+n))

# Note & Tips

1. This question requires combination of binary search and divide and conquer, which is hard to AC in a short time.