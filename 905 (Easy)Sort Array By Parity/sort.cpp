class Solution {
private:
    static bool cmp(int a,int b)
    {
        return (a % 2) < (b % 2);
    }
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), cmp);
        return A; 
    }
};
