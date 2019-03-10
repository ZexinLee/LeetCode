class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int tmp;
        for(int i = n; i > 0; i--) {
            tmp = i;
            while(tmp / 5 * 5 == tmp) {
                tmp /= 5;
                sum++;
            }
        }
        return sum;
    }
};