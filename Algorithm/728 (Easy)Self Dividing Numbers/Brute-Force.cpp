class Solution {
public:
    bool isAns(int i) {
        int temp = i;
        while(i > 0) {
            if(i / 10 * 10 == i || temp % (i % 10) != 0) {
                return false;
            }
            else {
                i /= 10;
            }
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++) {
            if(isAns(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};