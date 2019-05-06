class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        if(num < 10)
            return num;
        else
            while(num > 0)
            {
                ans += (num % 10);
                num /= 10;
            }
        
        if(ans >= 10)
            return addDigits(ans);
        return ans;
    }
};
