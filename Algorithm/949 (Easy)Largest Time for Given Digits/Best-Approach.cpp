class Solution {
public:
    bool valid(int hour, int minute) {
        return (hour < 24 && hour >= 0 && minute < 60 && minute >= 0);
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        char ans[6] = "", buffer[6];
        sort(A.begin(), A.end());
        do {
            sprintf(buffer, "%d%d:%d%d", A[0], A[1], A[2], A[3]);
            if (valid(A[0]*10+A[1], A[2]*10+A[3]) && strcmp(ans, buffer) < 0)  // actually, it's needn't to compare ans with buffer
                strcpy(ans, buffer);
        } while (next_permutation(A.begin(), A.end()));
        return string(ans);
    }
};
