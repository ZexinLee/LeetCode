class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
    
        int no_of_rows = matrix.size();
        if(no_of_rows == 0)
            return result;
        
        int no_of_columns = matrix[0].size();
    
        if(no_of_columns == 0)
            return result;
    
        enum State {GOING_RIGHT, GOING_DOWN, GOING_LEFT, GOING_UP};
        State direction = GOING_RIGHT;
        if(no_of_columns == 1)
            direction = GOING_DOWN;
    
        int rows_low {0}, rows_high {no_of_rows};
        int columns_low {0}, columns_high {no_of_columns};
    
        int i{0}, j{0};
    
        while(rows_low < rows_high && columns_low < columns_high) {
            result.emplace_back(matrix[i][j]);
        
            switch(direction) {
                case GOING_RIGHT:
                {
                    if(j == columns_high - 1) {     // Have processed the last element in the row. Change direction
                        direction = GOING_DOWN;
                        ++i;
                        ++rows_low;                 // When we come up, don't reach this row since it is finished
                    }
                    else
                        ++j;                        // Keep going right
                    break;
                }
            
                case GOING_DOWN:
                {
                    if(i == rows_high - 1) {
                        direction = GOING_LEFT;
                        --j;
                        --columns_high;
                    } else
                        ++i;
                    break;
                }
            
                case GOING_LEFT:
                {
                    if(j == columns_low) {
                        direction = GOING_UP;
                        --i;
                        --rows_high;
                    } else
                        --j;
                    break;
                }
            
                case GOING_UP:
                {
                    if(i == rows_low) {
                        direction = GOING_RIGHT;
                        ++j;
                        ++columns_low;
                    } else
                        --i;
                    break;
                }
            }
        }
    
        return result;
    }
};