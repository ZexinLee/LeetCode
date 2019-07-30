class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    {
        char buffer[20];
        vector<string> out;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (num == __builtin_popcount(h) + __builtin_popcount(m)) {
                    sprintf(buffer, "%d:%02d", h, m);
                    out.emplace_back(buffer);
                }
            }
        }
        return out;
    }
};