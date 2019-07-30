class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> record;
        vector<int> ans;
        for(int i : arr1) {
            if(record.find(i) != record.end()) {
                record[i]++;
            }
            else {
                record[i] = 1;
            }
        }
        for(int& i : arr2) {
            for(int j = 0; j < record[i]; j++) {
                ans.push_back(i);
            }
            record[i] = 0;
        }
        for(auto& i : record) {
            if(i.second == 0)
                continue;
            for(int j = 0; j < i.second; j++) {
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};