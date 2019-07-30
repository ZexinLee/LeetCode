class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        while(true)
        {
            if(n == 1)
                return true;
            if(n / 3 * 3 == n)
                n /= 3;
            else
                break;
        }
        return false;
    }
};
