class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        else if(N == 1)
            return 1;
        else if(N == 2)
            return 1;
        return fib(N - 1) + fib(N - 2);
    }
};
