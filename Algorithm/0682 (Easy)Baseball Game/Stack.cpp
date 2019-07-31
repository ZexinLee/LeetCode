class Solution {
public:
    int calPoints(vector<string>& ops) {
        long long ans = 0;
        stack<long long> st;
        int temp1, temp2;
        for(string s : ops) {
            if(s == "C") {
                st.pop();
            } else if(s == "D") {
                st.push(st.top() * 2);
            } else if(s == "+") {
                temp1 = st.top();
                st.pop();
                temp2 = st.top();
                st.push(temp1);
                st.push(temp1 + temp2);
            } else {
                st.push(atoi(s.c_str()));
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};