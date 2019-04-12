class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        double current = x;
        string binary_pow = "";
        if(n > 0)
        {
            while(n != 0)
            {
                binary_pow += ('0' + n % 2);
                n /= 2;
            }
            for(int i = 0; i < binary_pow.length(); i++)
            {
                ans *= (binary_pow[i] - '0' == 0) ? 1 : current;
                current *= current;
            }
        }
        else
        {
            while(n != 0)
            {
                binary_pow += ('0' + n % 2);
                n /= 2;
            }
            for(int i = 0; i < binary_pow.length(); i++)
            {
                ans /= (binary_pow[i] - '0' == 0) ? 1 : current;
                current *= current;
            }
        }
        return ans;
    }
};