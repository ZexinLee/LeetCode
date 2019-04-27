class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<int> qx;
        queue<int> qy;
        int count = 0;
        int tempcount = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    tempcount = 0;
                    qx = queue<int>();
                    qy = queue<int>();
                    qx.push(i);
                    qy.push(j);
                    grid[i][j] = 0;
                    int tx,ty;
                    while(qx.size() != 0)
                    {
                        tx = qx.front();
                        ty = qy.front();
                        qx.pop();
                        qy.pop();
                        tempcount++;
                        // if(tx > 0 && !isvisited[tx - 1][ty])
                        if(tx > 0 && grid[tx - 1][ty] == 1)
                        {
                            // isvisited[tx - 1][y] = true;
                            qx.push(tx - 1);
                            qy.push(ty);
                            grid[tx - 1][ty] = 0;
                        }
                        if(ty > 0 && grid[tx][ty - 1] == 1)
                        {
                            qx.push(tx);
                            qy.push(ty - 1);
                            grid[tx][ty - 1] = 0;
                        }
                        if(tx < grid.size() - 1 && grid[tx + 1][ty] == 1)
                        {
                            qx.push(tx + 1);
                            qy.push(ty);
                            grid[tx + 1][ty] = 0;
                        }
                        if(ty < grid[0].size() - 1 && grid[tx][ty + 1] == 1)
                        {
                            qx.push(tx);
                            qy.push(ty + 1);
                            grid[tx][ty + 1] = 0;
                        }
                    }
                    //cout << tempcount << ' ';
                    count = max(count, tempcount);
                }
            }
        }
        return count;
    }
};
