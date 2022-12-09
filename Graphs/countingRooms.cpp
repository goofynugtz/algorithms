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
 
void dfs(int n, int m, vector<vector<char>>& adjMat, vector<vector<bool>>& visited){
  if (visited[n][m]) return;
  visited[n][m] = 1;
  queue<pair<int,int>> q;
  q.push({n,m});
 
  int rows = adjMat.size();
  int columns = adjMat[0].size();
 
  while(!q.empty()){
    pair<int,int> node = q.front();
    q.pop();
    int i = node.first; int j = node.second;
    int top = i-1;
    if (top >= 0 && adjMat[top][j] == '.' && visited[top][j] == 0){
      q.push({top, j});
      visited[top][j] = 1;
    }
    int bottom = i+1;
    if (bottom < rows && adjMat[bottom][j] == '.' && visited[bottom][j] == 0){
      q.push({bottom, j});
      visited[bottom][j] = 1;
    }
    int left = j-1;
    if (left >= 0 && adjMat[i][left] == '.' && visited[i][left] == 0){
      q.push({i, left});
      visited[i][left] = 1;
    }
    int right = j+1;
    if (right < columns && adjMat[i][right] == '.' && visited[i][right] == 0){
      q.push({i, right});
      visited[i][right] = 1;
    }
  }
}
 
int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<vector<char>> adjMat(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      char c; cin >> c;
      adjMat[i][j] = c;
    }
  }
 
  int result = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (!visited[i][j] && adjMat[i][j] == '.'){
        result++;
        dfs(i, j, adjMat, visited);
      }
    }
  }
  cout << result << "\n";  
  return 0;
}

/* 
5 8
########
#..#...#
####.#.#
#..#...#
########
*/