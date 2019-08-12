# Algorithm

A simple building block question. 

answer = max(x-axis) + max(y-axis) + max(z-axis)

# Better Solution

```c++
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        
        int area =0;
        int n = grid.size(); 
        //XY
        area = n * n;
        
        //XZ
        int maxYZ ;
        for (int i=0; i<n; i++)
        {
            area += *max_element( grid[i].begin(),grid[i].end() );
            area -= count(grid[i].begin(),grid[i].end(),0);
             maxYZ = INT_MIN;
            for (int j=0;j<n; j++)
                maxYZ = max(maxYZ,grid[j][i]);
            area += maxYZ;
        }
        
        return area;
    }
};
```

(The best run time solution in the leetcode)

# Performance

Runtime: 12 ms, faster than 11.59% of C++ online submissions for Projection Area of 3D Shapes.

Memory Usage: 10.2 MB, less than 25.00% of C++ online submissions for Projection Area of 3D Shapes.

# Time Spent

19 min 44 seconds

# Times of Wrong Answer

0

# Solution

```c++
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int x = 0, y = 0, z = 0;
        
        vector<vector<int>> temp(grid[0].size(), vector<int>(grid.size(), 0));
        for(int i = 0; i < temp.size(); i++) {
            for(int j = 0; j < temp[0].size(); j++) {
                temp[i][j] = grid[j][i];
            }
        }
        
        for(auto v : temp) {
            x += *(max_element(v.begin(),v.end()));
        }
        
        for(auto v : grid) {
            y += *(max_element(v.begin(),v.end()));
        }
        
        for(auto v : grid) {
            for(int cell : v) {
                if(cell != 0) {
                    z++;
                }
            }
        }
        return x + y + z;
    }
};
```

The code of AC solution

# Time Complexity

O(n^2)

# Note & Tips

1. Don't apply a lot new dynamic memory if not necessary since it will cause bad performance.