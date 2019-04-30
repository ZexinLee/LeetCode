class Solution {
public:
    int count;
    Solution() {
        this->count = 0;
    }
    void calculate(int N, int pos, vector<bool> &visited) {
        if (pos > N)
            this->count++;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }
    int countArrangement(int N) {
        vector<bool> visited(N, false);
        calculate(N, 1, visited);
        return this->count;
    }
};
