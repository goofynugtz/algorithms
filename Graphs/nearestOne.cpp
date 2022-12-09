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

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }

  queue<pair< pair<int,int>, int >> q; // { {i,j} , steps }
  vector<vector<bool>> visited(n, vector<bool>(m, 0));
  vector<vector<int>> steps(n, vector<int>(m));

  for (int i = 0; i < n ; i++){
    for (int j = 0; j < m; j++){
      if (grid[i][j] == 1 && visited[i][j] == 0){
        q.push({{i,j}, 0});
        visited[i][j] = 1;
        steps[i][j] = 0;
      }
    }
  }

  while (!q.empty()){
    int i = q.front().first.first;
    int j = q.front().first.second;
    int step = q.front().second;
    steps[i][j] = step;
    q.pop();

    if (i-1 >= 0 && visited[i-1][j] == 0){
      q.push({{i-1, j}, step+1});
      visited[i-1][j] = 1;
    }
    if (i+1 < n && visited[i+1][j] == 0){
      q.push({{i+1, j}, step+1});
      visited[i+1][j] = 1;
    }
    if (j-1 >= 0 && visited[i][j-1] == 0){
      q.push({{i, j-1}, step+1});
      visited[i][j-1] = 1;
    }
    if (j+1 < m && visited[i][j+1] == 0){
      q.push({{i, j+1}, step+1});
      visited[i][j+1] = 1;
    }
  }

  for (auto rows: steps){
    for (auto it: rows){
      cout << it << " ";
    }
    cout << "\n";
  }

  return 0;
}

/* 
3 3
0 0 0
0 1 0
1 0 1
 */