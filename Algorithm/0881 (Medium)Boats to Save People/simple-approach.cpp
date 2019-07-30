class Solution {
public:
    int numRescueBoats(vector<int>& ppl, int limit) {
          int boats = 0;
          sort(begin(ppl), end(ppl));
          for (int i = 0, j = ppl.size() - 1; i <= j; ++boats, --j) {
            if (ppl[i] + ppl[j] <= limit) ++i;
          }
          return boats;
    }
};
