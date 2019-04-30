class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        vector<vector<bool>> visitedCells(matrix.size(), vector<bool>(matrix[0].size(), false));
        int H = matrix.size();
        int W = matrix[0].size();
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                int row = i, col = j;
                bool isFirstElemForComp = false;
                int firstElem = -1;
                while ((row<H) && (col<W)) {
                    if (visitedCells[row][col] == false) {
                        visitedCells[row][col] = true;
                        if (isFirstElemForComp == false) {
                            isFirstElemForComp = true;
                            firstElem = matrix[row][col];
                        } else {
                            if (matrix[row][col] != firstElem)  return false;
                        }
                        ++row;
                        ++col;
                    } else break;
                }
            }
        }

        return true;
    }
};
