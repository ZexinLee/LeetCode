class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::vector<int> evenVec, oddVec;
        for (const auto& elem: A) {
            if (elem%2 == 0) evenVec.push_back(elem);
            else oddVec.push_back(elem);
        }

        evenVec.insert(evenVec.end(), oddVec.begin(), oddVec.end());
        return evenVec;
    }
};
