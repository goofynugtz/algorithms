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

void dfs(int ro, int co, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& step){
  visited[ro][co] = 1;
  ++step;

  if (ro-1 >= 0 && visited[ro-1][co] == 0 && grid[ro-1][co] == 1){
    dfs(ro-1, co, grid, visited, step);
  }
  if (ro+1 < grid.size() && visited[ro+1][co] == 0 && grid[ro+1][co] == 1){
    dfs(ro+1, co, grid, visited, step);
  }
  if (co-1 >= 0 && visited[ro][co-1] == 0 && grid[ro][co-1] == 1){
    dfs(ro, co-1, grid, visited, step);
  }
  if (co+1 < grid[0].size() && visited[ro][co+1] == 0 && grid[ro][co+1] == 1){
    dfs(ro, co+1, grid, visited, step);
  }
}

void ignoreEdgeLands(vector<vector<int>>& grid, vector<vector<bool>>& visited){
  int n = grid.size();
  int m = grid[0].size();
  int ign = 0;
  for (int i = 0; i < n; i++)
    if (grid[i][0] == 1 && visited[i][0] == 0)
      dfs(i, 0, grid, visited, ign);
  for (int i = 0; i < m; i++)
    if (grid[n-1][i] == 1 && visited[n-1][i] == 0)
      dfs(n-1, i, grid, visited, ign);
  for (int i = 0; i < n; i++)
    if (grid[i][m-1] == 1 && visited[i][m-1] == 0)
      dfs(i, m-1, grid, visited, ign);
  for (int i = 0; i < m; i++)
    if (grid[0][i] == 1 && visited[0][i] == 0)
      dfs(0, i, grid, visited, ign);
}

int computeLands(vector<vector<int>>& grid, vector<vector<bool>>& visited){
  int lands = 0;
  for (int i = 0; i < grid.size(); i++){
    for (int j = 0; j < grid[0].size(); j++){
      if (visited[i][j] == 0 && grid[i][j] == 1){
        dfs(i, j, grid, visited, lands);
      }
    }
  }
  return lands;
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  vector<vector<bool>> visited(n, vector<bool>(m, 0));
  ignoreEdgeLands(grid, visited);

  cout << computeLands(grid, visited);

  return 0;
}

/* 
5 4
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
 */