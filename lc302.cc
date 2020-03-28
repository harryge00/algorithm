class Solution {
    int directions[4][2] = {
        {-1, 0},
        {0, 1},
        {0, -1},
        {0, 1}
    };
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        queue<pair<int,int>> q;
        q.push(pair<int,int>(x, y));
        int left = y, right = y;
        int up = x, down = x;
        while(!q.empty()) {
            pair<int,int> loc = q.front();
            q.pop();
            x = loc.first;
            y = loc.second;
            if(x < up) {
                up = x;
            } else if (x > down) {
                down = x;
            }
            if(y < left) {
                left = y;
            } else if ( y > right) {
                right = y;
            }
            image[x][y] = 2;
            for(int i = 0; i < 4; i++) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];
                if(newX < image.size() && newX >= 0 && newY >= 0 && 
                    newY < image[0].size() && image[newX][newY] == 1) {
                    q.push(pair<int, int>(loc.first + directions[i][0], loc.second + directions[i][1]));
                }
            }
            
        }
        return (right - left + 1) * (down - up + 1);
    }

};