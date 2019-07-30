# Brute-Force

Very straightforward sort and find the single one.

Time Complexity: O(nlogn)

# Think Further

Use hashset

# Best Approach of C++

TODO

elegant but hard to understand

int a = 0,b = 0;
        for(int i = 0; i < nums.size(); i++){
            a = a ^ nums[i] & ~b;
            b = b ^ nums[i] & ~a;
        }
        return a|b;