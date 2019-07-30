class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int ans = 0;
        cout << z;
        while(z > 0) {
            ans += (z % 2);
            z /= 2;
        }
        return ans;
    }
};