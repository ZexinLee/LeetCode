class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> temp;
        int ans;
        for(int i : A) {
            if(temp.find(i) == temp.end()) {
                temp[i] = 1;
            }
            else {
                temp[i]++;
            }
        }
        for(auto i : temp)
            if(i.second == A.size() / 2)
                ans = i.first;
        return ans;
    }
};
