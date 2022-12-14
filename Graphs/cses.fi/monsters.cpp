// https://cses.fi/problemset/task/1194
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define int long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

bool findPathForA(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited, 
vector<char>& path, int time){
  visited[i][j] = time;
  int n = grid.size(), m = grid[0].size();
  if (i == n-1 || i == 0 || j == m-1 || j == 0) return true;
  
  if (i-1 >= 0 && grid[i-1][j] == '.' && visited[i-1][j] > time+1){
    path.push_back('U');
    if (findPathForA(i-1, j, grid, visited, path, time+1)) return true;
    path.pop_back();
  }
  if (i+1 < n && grid[i+1][j] == '.' && visited[i+1][j] > time+1){
    path.push_back('D');
    if (findPathForA(i+1, j, grid, visited, path, time+1)) return true;
    path.pop_back();
  }
  if (j-1 >= 0 && grid[i][j-1] == '.' && visited[i][j-1] > time+1){
    path.push_back('L');
    if (findPathForA(i, j-1, grid, visited, path, time+1)) return true;
    path.pop_back();
  }
  if (j+1 < m && grid[i][j+1] == '.' && visited[i][j+1] > time+1){
    path.push_back('R');
    if (findPathForA(i, j+1, grid, visited, path, time+1)) return true;
    path.pop_back();
  }
  return false;
}

void evalMonsters(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visited, int time){
  visited[i][j] = time;
  int n = grid.size(), m = grid[0].size();
  if (i-1 >= 0 && grid[i-1][j] == '.' && visited[i-1][j] > time+1)
    evalMonsters(grid, i-1, j, visited, time+1);
  if (i+1 < n && grid[i+1][j] == '.' && visited[i+1][j] > time+1)
    evalMonsters(grid, i+1, j, visited, time+1);
  if (j-1 >= 0 && grid[i][j-1] == '.' && visited[i][j-1] > time+1)
    evalMonsters(grid, i, j-1, visited, time+1);
  if (j+1 < m && grid[i][j+1] == '.' && visited[i][j+1] > time+1)
    evalMonsters(grid, i, j+1, visited, time+1);
}

vector<char> escapeMonsters(vector<vector<char>>& grid, pair<int,int> s, vector<pair<int,int>>& monsters){
  vector<char> path;
  vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), INF));
  for (int i = 0; i < (int)monsters.size(); i++){
    evalMonsters(grid, monsters[i].ff, monsters[i].ss, visited, 0);
  }
  if (findPathForA(s.ff, s.ss, grid, visited, path, 0)){
    return path;
  }
  return {'0'};
}

signed main(void){
  setIO();
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  vector<pair<int,int>> monsters;
  pair<int,int> source;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> grid[i][j];
      if (grid[i][j] == 'A'){
        source = {i,j};
      }
      if (grid[i][j] == 'M'){
        monsters.push_back({i,j});
      }
    }
  }
  if (source.ff == n-1 || source.ff == 0 || source.ss == m-1 || source.ss == 0){
    cout << "YES\n0\n";
    return 0;
  } else {
    vector<char> path = escapeMonsters(grid, source, monsters);
    if (path[0] != '0'){
      cout << "YES\n";
      
      cout << path.size() << "\n";
      for (auto it:path) cout << it;
      cout << "\n";
      
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}

/* 
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
 */