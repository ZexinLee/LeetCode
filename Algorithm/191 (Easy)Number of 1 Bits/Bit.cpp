class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 32;
        int count = 0;
        while(bit)
        {
            if(n % 2 == 1)
                count++;
            n /= 2;
            bit--;
        }
        return count;
    }
};