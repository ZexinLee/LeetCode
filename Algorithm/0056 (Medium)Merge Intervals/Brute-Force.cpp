class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return intervals;
        }
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[0];
        };
        set<vector<int>, decltype(cmp)> st(cmp);
        st.insert(intervals[0]);
        for (int i = 1; i < n; ++i) {
            vector<int> current = intervals[i];
            while (st.find(current) != st.end()) {
                auto it = st.find(current);
                current[0] = min((*it)[0], current[0]);
                current[1] = max((*it)[1], current[1]);
                st.erase(it);
            }
            st.insert(current);
        }
        vector<vector<int>> ans;
        for (auto item : st) {
            ans.push_back(item);
        }
        return ans;
    }
};
