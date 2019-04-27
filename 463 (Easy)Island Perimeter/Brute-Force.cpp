class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) { 
                if (grid[i][j] == 0)    continue;
                int neighborsCount = 0;
                
                if (i-1>=0)     neighborsCount += grid[i-1][j];
                if (j-1>=0)     neighborsCount += grid[i][j-1];
                if (i+1<=rows-1)    neighborsCount += grid[i+1][j];
                if (j+1<=cols-1)    neighborsCount += grid[i][j+1];
                
                perimeter += (4-neighborsCount);
            }
        }
        
        return perimeter;
    }
};
