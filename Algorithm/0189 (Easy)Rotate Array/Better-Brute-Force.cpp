class Solution {
    int gbd(int a,int b){
        if(a<b) swap(a,b);
        if(!b) return a;
        return gcd(b,a%b);
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), m = gcd(n,k);
        for(int i=0;i<m;i++){
            int x = nums[i],index=(i+k)%n;
            for(int j=0;j<n/m;j++){
                int tmp = nums[index];
                nums[index] = x;
                x = tmp;
                index = (index+k)%n;
            }
        }
        return;
    }
};
