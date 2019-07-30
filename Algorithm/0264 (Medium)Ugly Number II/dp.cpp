class Solution {
public:
	int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1] = 1;
        int i = 1, j = 1, k = 1;    // i,j,k:index of 2,3,5
        
        int ct = 1;
        
        while(ct < n) {
            int n2 = dp[i]*2, n3 = dp[j] * 3, n5 = dp[k] * 5;
            dp[++ct] = min(min(n2, n3), n5);  // select minimum
            
            // index++
            if(dp[ct] == n2)
                i++;
            if(dp[ct] == n3)
                j++;
            if(dp[ct] == n5)
                k++;
        }
        
        
        return dp[n];
	}
};