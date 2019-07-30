class Solution {
public:
    int climb_Stairs(int i, int n) {
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
    
    int climbStairs(int n) {
        return climb_Stairs(0,n);
    }
};