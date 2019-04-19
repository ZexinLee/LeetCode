class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        bool isprime[n + 1];
        memset(isprime, true, sizeof(isprime)); 
        if(n < 2)
            return false;
        
        isprime[0] = isprime[1] = false;
        
        int temp = 0;
        for(int i = 2; i <= n; i++)
        {
            if(isprime[i])
            {
                temp = 2*i;
                while(temp <= n)
                {
                    isprime[temp] = false;
                    temp += i;
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(isprime[i])
            {
                count++;
                //cout << i;
            }
        return count;
    }
};