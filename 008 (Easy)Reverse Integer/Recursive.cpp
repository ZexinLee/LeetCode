class Solution {
public:
    long long rst = 0;
    void raw_reverse(int x) {
        if(x==0)
            return;
        else
            rst *= 10;
        rst += x % 10;
        x /= 10;
        raw_reverse(x);
    }
    
    int reverse(int x) {
        raw_reverse(x);
        return (rst > INT_MAX || rst < INT_MIN) ? 0 : rst;
    }
};