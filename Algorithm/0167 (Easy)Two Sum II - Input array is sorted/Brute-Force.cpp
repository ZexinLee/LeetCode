class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = 0;
        int maxsize = numbers.size();
        vector<int> ans;
        
        for(i = 0; i < maxsize; i++)
            for(j = i + 1; j < maxsize; j++)
                if(numbers[i] + numbers[j] == target)
                    goto flag;
        flag:ans.push_back(i+1);
        ans.push_back(j+1);
        
        return ans;
    }
};