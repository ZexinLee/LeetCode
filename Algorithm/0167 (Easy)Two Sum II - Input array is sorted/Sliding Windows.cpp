class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> res;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            } else if (numbers[i] + numbers[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};


