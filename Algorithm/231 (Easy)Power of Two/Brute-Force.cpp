class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while(n > 1)
        {
            if(n / 2 * 2 == n)
                n /= 2;
            else
                return false;
        }
        return true;
    }
};