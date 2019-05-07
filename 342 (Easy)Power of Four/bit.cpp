class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        if(num==1) return true;
        int k = (int)sqrt((long long)num+1);
        if(k*k!=num) return false;
        return !(k&(k-1));
    }
};
