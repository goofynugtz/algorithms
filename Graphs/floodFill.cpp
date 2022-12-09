#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

void dfs(int n, int m, vector<vector<int>>& mat, int rows, int columns, vector<vector<bool>> visited, int initColor, int newColor){
  visited[n][m] = 1;
  if (mat[n][m] == initColor) 
    mat[n][m] = newColor;
  if (n-1 >= 0 && visited[n-1][m] == 0 && mat[n-1][m] == initColor && mat[n-1][m] != newColor)
    dfs(n-1, m, mat, rows, columns, visited, initColor, newColor);
  if (n+1 < rows && visited[n+1][m] == 0 && mat[n+1][m] == initColor && mat[n+1][m] != newColor)
    dfs(n+1, m, mat, rows, columns, visited, initColor, newColor);
  if (m-1 >= 0 && visited[n][m-1] == 0 && mat[n][m-1] == initColor && mat[n][m-1] != newColor)
    dfs(n, m-1, mat, rows, columns, visited, initColor, newColor);
  if (m+1 < columns && visited[n][m+1] == 0 && mat[n][m+1] == initColor && mat[n][m+1] != newColor)
    dfs(n, m+1, mat, rows, columns, visited, initColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> image, int row, int column, int newColor){
  int initColor = image[row][column];
  vector<vector<int>> result = image;
  int n = image.size();
  int m = image[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m));
  dfs(row, column, result, n, m, visited, initColor, newColor);
  return result;
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> v[i][j];
    }
  }

  vector<vector<int>> ans = floodFill(v, 1, 1, 2);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}

/* 
3 3
1 1 1
1 1 0
1 0 1
 */