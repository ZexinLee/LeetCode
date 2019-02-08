/*
	copy from https://leetcode.com/problems/reverse-pairs/solution/
	by bwv988
*/

public:
    int reversePairs(vector<int>& nums){
        if(nums.size() < 2) return 0;
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end(), greater<int>());
        vector<int> tree(nums.size() + 1, 0); // Stores how many items so far are >= the item in according index in sorted array.
        int cnt = 0;
        for(auto i : nums){
            // When search, we accumulate item count of all numbers > 2 * current number.
            auto it = upper_bound(nums2.rbegin(), nums2.rend(), i * 2LL); 
            if(it != nums2.rend()){
                int idx = nums2.rend() - it;
                cnt += sum(tree, itIdx);
            }
            // When update, we increase the item count of all numbers <= current number.
            int idx = nums2.rend() - lower_bound(nums2.rbegin(), nums2.rend(), i);
            update(tree, idx, 1);
        }
        return cnt;
    }

private:
    int sum(vector<int> &tree, int idx){
        int cnt = 0;
        while(idx){
            cnt += tree[idx];
            idx -= idx & (-idx);            
        }
        return cnt;
    }
    
    void update(vector<int> &tree, int idx, int d){
        while(idx < tree.size()){
            tree[idx] += d;
            idx += idx & (-idx);
        }
    }