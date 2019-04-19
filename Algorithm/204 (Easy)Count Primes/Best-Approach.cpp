class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        bool res[n]; //array is faster than vector
        memset(res, true, sizeof(res)); 
        int counts = 2;
        for(int i = 2; i * i < n; i++){
            if(res[i]){
                int step = (i > 2) ? 2 * i : 2;  //trick:prime is odd,except 2.
                for(int j=i*i;j<n;j += step){ //odd+even=odd
                    if(res[j]){
                        res[j]=false;
                        counts++;
                    }
                }
            }
        }
        return n-counts;
    }
};