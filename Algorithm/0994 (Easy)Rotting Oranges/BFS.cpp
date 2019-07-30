class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0, time = 0;
        queue<int> tx;
        queue<int> ty;
        queue<int> ttx;
        queue<int> tty;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    count++;
                if(grid[i][j] == 2)
                {
                    tx.push(i);
                    ty.push(j);
                }
            }
        }
        
        int x,y;
        if(count == 0)
            return 0;
        while(tx.size() != 0)
        {
            ttx = tx;
            tty = ty;
            tx = queue<int>();
            ty = queue<int>();
            while(ttx.size() != 0)
            {
                x = ttx.front();
                y = tty.front();
                ttx.pop();
                tty.pop();
                if(x > 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    tx.push(x - 1);
                    ty.push(y);
                    count--;
                }
                if(x < grid.size() - 1 && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    tx.push(x + 1);
                    ty.push(y);
                    count--;
                }
                if(y > 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    tx.push(x);
                    ty.push(y - 1);
                    count--;
                }
                if(y < grid[x].size() - 1 && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    tx.push(x);
                    ty.push(y + 1);
                    count--;
                }
            }
            time++;
            if(count == 0)
                break;
        }
        return (count == 0) ? time : -1;
    }
};
