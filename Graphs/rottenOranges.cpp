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

void rottenOranges (vector<vector<int>>& grid, 
                    vector<vector<int>>& visited, int& time, 
                    queue<pair< pair<int,int> , int >>& q, 
                    int& freshCount){

  while(!q.empty()){
    int r = q.front().first.first;
    int c = q.front().first.second;
    int t = q.front().second;
    time = max(time, t);
    q.pop();

    if (r-1 >= 0 && visited[r-1][c] == 0 && grid[r-1][c] == 1){
      q.push({{r-1, c}, time+1});
      visited[r-1][c] = 1;
      --freshCount;
    }
    if (r+1 < grid.size() && visited[r+1][c] == 0 && grid[r+1][c] == 1){
      q.push({{r+1, c}, time+1});
      visited[r+1][c] = 1;
      --freshCount;
    }
    if (c-1 >= 0 && visited[r][c-1] == 0 && grid[r][c-1] == 1){
      q.push({{r, c-1}, time+1});
      visited[r][c-1] = 1;
      --freshCount;
    }
    if (c+1 < grid[0].size() && visited[r][c+1] == 0 && grid[r][c+1] == 1){
      q.push({{r, c+1}, time+1});
      visited[r][c+1] = 1;
      --freshCount;
    }
  }
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }

  // queue => { {row, column} , time};
  queue<pair< pair<int,int>, int>> q;
  vector<vector<int>> visited(n, vector<int>(m, 0));
  
  int freshCount = 0; 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (grid[i][j] == 2){
        q.push({{i, j}, 0});
        visited[i][j] = 2;
      } else {
        visited[i][j] = 0;
      }
      if (grid[i][j] == 1) freshCount++;
    }
  }

  int time = 0;
  rottenOranges(grid, visited, time, q, freshCount);
  if (freshCount != 0){
    cout << "-1\n" << freshCount;
  } else {
    cout << time << "\n";
  }

  return 0;
}

/* 
3 3
0 1 2
0 1 2
2 1 1
 */