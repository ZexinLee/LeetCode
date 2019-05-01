# Cummulative Sum
Cache
Runtime: 1008 ms, faster than 5.02% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 11.5 MB, less than 77.15% of C++ online submissions for Subarray Sum Equals K.

# Hashmap
Algorithm
The idea behind this approach is as follows: If the cumulative sum(repreesnted by sum[i]sum[i] for sum upto i^{th}ith index) upto two indices is the same, the sum of the elements lying in between those indices is zero. Extending the same thought further, if the cumulative sum upto two indices, say ii and jj is at a difference of kk i.e. if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices ii and jj is kk.
Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative sum upto all the indices possible along with the number of times the same sum occurs. We store the data in the form: (sum_i, no. of occurences of sum_i)(sumi,no.ofoccurencesofsumi). We traverse over the array numsnums and keep on finding the cumulative sum. Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. Further, for every sum encountered, we also determine the number of times the sum sum-ksum−k has occured already, since it will determine the number of times a subarray with sum kk has occured upto the current index. We increment the countcount by the same amount.
After the complete array has been traversed, the countcount gives the required result.
The animation below depicts the process.


Time complexity : O(n). The entire numsnums array is traversed only once.
Space complexity : O(n). Hashmap mapmap can contain upto nn distinct entries in the worst case.
