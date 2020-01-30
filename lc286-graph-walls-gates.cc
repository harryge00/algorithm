#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

void wallsAndGates(vector<vector<int>>& rooms) {
    queue<pair<int,int>> q;
    for(int i = 0; i < rooms.size(); i++) {
        for(int j = 0; j < rooms.size(); j++) {
            if(rooms[i][j] == 0) {
                q.push(pair<int,int>(i, j));
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if(x - 1 >= 0 && rooms[x - 1][y] > rooms[x][y] + 1) {
            // Found a closer path
            rooms[x - 1][y] = rooms[x][y] + 1;
            q.push(pair<int,int>(x - 1, y));
        }
        if(x + 1 >= 0 && rooms[x + 1][y] > rooms[x][y] + 1) {
            // Found a closer path
            rooms[x + 1][y] = rooms[x][y] + 1;
            q.push(pair<int,int>(x + 1, y));
        }
        if(y - 1 >= 0 && rooms[x][y - 1] > rooms[x][y] + 1) {
            // Found a closer path
            rooms[x][y - 1] = rooms[x][y] + 1;
            q.push(pair<int,int>(x, y - 1));
        }
        if(y + 1 >= 0 && rooms[x][y + 1] > rooms[x][y] + 1) {
            // Found a closer path
            rooms[x][y + 1] = rooms[x][y] + 1;
            q.push(pair<int,int>(x, y + 1));
        }
        q.pop();
    }
}

int main() {
    vector<vector<int> > rooms;
    wallsAndGates(rooms);
}