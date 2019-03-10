class Solution {
public:
    int trailingZeroes(int n) {
        if(n<=0)
            return 0;
        int count = 0;
        int f = n/5;
       while (f>0)
       {
           count += f;
           f /= 5;
       }
        return count;
    }
};