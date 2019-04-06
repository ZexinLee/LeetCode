class Solution {
public:
 uint32_t reverseBits(uint32_t n) {
        uint32_t a = 0;
        int i = 0;
        while(n){
            a <<= 1;
            a |= (n & 0x1);
            ++i;
            n >>= 1;
        }
        return a == 0? 0: a<< (32-i);
    }
};