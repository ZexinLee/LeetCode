class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //int midx = image.size()/2;
        //int midy = (image[image.size()/2]).size()/2;
        int midcolor = image[sr][sc];
        int tempx, tempy;
        
        bool isvisited[image.size()][image[0].size()];
        queue<int> currentx;
        queue<int> currenty;
        currentx.push(sr);
        currenty.push(sc);
        
        for(int i = 0; i < image.size(); i++)
            for(int j = 0; j < image[0].size(); j++)
                isvisited[i][j] = false;
        
        //cout << image.size() << " " << image[0].size() << endl;
        
        while(!currentx.empty())
        {
            tempx = currentx.front();
            tempy = currenty.front();
            currentx.pop();
            currenty.pop();
            image[tempx][tempy] = newColor;
            //cout << tempx << " " << tempy << endl;
            if(tempx - 1 >= 0 && !isvisited[tempx - 1][tempy] && image[tempx - 1][tempy] == midcolor)
            {
                currentx.push(tempx - 1);
                currenty.push(tempy);
                isvisited[tempx - 1][tempy] = true;
            }
            if(tempy - 1 >= 0 && !isvisited[tempx][tempy - 1] && image[tempx][tempy - 1] == midcolor)
            {
                currentx.push(tempx);
                currenty.push(tempy - 1);
                isvisited[tempx][tempy - 1] = true;
            }
            if(tempx + 1 < image.size() && !isvisited[tempx + 1][tempy] && image[tempx + 1][tempy] == midcolor)
            {
                currentx.push(tempx + 1);
                currenty.push(tempy);
                isvisited[tempx + 1][tempy] = true;
            }
            if(tempy + 1 < image[tempx].size() && !isvisited[tempx][tempy + 1] && image[tempx][tempy + 1] == midcolor )
            {
                currentx.push(tempx);
                currenty.push(tempy + 1);
                isvisited[tempx][tempy + 1] = true;
            }
        }
        
        return image;
    }
};