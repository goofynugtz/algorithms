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

void dfs(int ro, int co, vector<vector<char>>& grid, vector<vector<bool>>& visited){
  visited[ro][co] = 1;
  if (ro-1 >= 0 && visited[ro-1][co] == 0 && grid[ro-1][co] == 'O')
    dfs(ro-1, co, grid, visited);

  if (ro+1 < grid.size() && visited[ro+1][co] == 0 && grid[ro+1][co] == 'O')
    dfs(ro+1, co, grid, visited);

  if (co-1 >= 0 && visited[ro][co-1] == 0 && grid[ro][co-1] == 'O')
    dfs(ro, co-1, grid, visited);

  if (co+1 < grid[0].size() && visited[ro][co+1] == 0 && grid[ro][co+1] == 'O')
    dfs(ro, co+1, grid, visited);
}

void boundariesHandler(vector<vector<char>>& grid, vector<vector<bool>>& visited){
  int n = grid.size();
  int m = grid[0].size();
  // left
  for (int i = 0; i < n; i++)
    if (visited[i][0] == 0 && grid[i][0] == 'O')
      dfs(i, 0, grid, visited);
  // bottom
  for (int j = 0; j < m; j++)
    if (visited[m-1][j] == 0 && grid[m-1][j] == 'O')
      dfs(m-1, j, grid, visited);
  // right
  for (int i = 0; i < n; i++)
    if (visited[i][n-1] == 0 && grid[i][n-1] == 'O')
      dfs(i, n-1, grid, visited);
  // top
  for (int j = 0; j < m; j++)
    if (visited[0][j] == 0 && grid[0][j] == 'O')
      dfs(0, j, grid, visited);
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  vector<vector<bool>> visited(n, vector<bool>(m, 0));
  boundariesHandler(grid, visited);

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (visited[i][j] == 1)
        cout << "O ";
      else 
        cout << "X ";
    }
    cout << "\n";
  }

  return 0;
}

/* 
5 5
X X X X X
X O O X O
X X O X O
X O X O X
O O X X X
*/