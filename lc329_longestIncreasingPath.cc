class Solution {
private:
  int m, n;
  vector<vector<int>> longest;
  vector<vector<int>>* mm;
  void goOnce(int len, int i, int j, vector<vector<bool>>& visited) {
    // cout<<(*mm)[i][j]<<endl;
    // cout << i << j << len + 1<<endl;
    if(len + 1 > longest[i][j]) {
      longest[i][j] = len + 1;
    }
    if(j < n - 1 && !visited[i][j+1] && (*mm)[i][j + 1] > (*mm)[i][j]) {
      visited[i][j+1] = true;
      goOnce(len + 1, i, j + 1, visited);
      visited[i][j+1] = false;
    }
    if(j > 0 && !visited[i][j-1] && (*mm)[i][j - 1] > (*mm)[i][j]) {
      visited[i][j - 1] = true;
      goOnce(len + 1, i, j - 1, visited);
      visited[i][j - 1] = false;
    }
    if(i < m - 1 && !visited[i + 1][j] && (*mm)[i + 1][j] > (*mm)[i][j]) {
      visited[i + 1][j] = true;
      goOnce(len + 1, i + 1, j, visited);
      visited[i+1][j] = false;
    }
    if(i > 0 && !visited[i - 1][j] && (*mm)[i - 1][j] > (*mm)[i][j]) {
      visited[i - 1][j] = true;
      goOnce(len + 1, i - 1, j, visited);
      visited[i - 1][j] = false;
    }
  }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      if(matrix.empty() || matrix[0].empty()) {
        return 0;
      }
      mm = &matrix;
      m = matrix.size();
      n = matrix[0].size();
      for(int i = 0; i < m; i++) {
        longest.push_back(vector<int>{0, n});
      }
      // cout<<longest.size()<<endl;
      vector<vector<bool>> visited(m, vector<bool>(n));
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          visited[i][j] = true;
          goOnce(0, i, j, visited);
          visited[i][j] = false;
        }
      }
      int res = 0;
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          if(res < longest[i][j]) {
            res = longest[i][j];
          }
        }
      }
      return res;
    }
};
