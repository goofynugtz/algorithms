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

void bfs(int row, int col, vector<vector<int>>& adjMat, vector<vector<int>>& visited){
  if (visited[row][col]) return;
  visited[row][col] = 1;
  queue<pair<int,int>> q;
  q.push({row,col});
  int n = adjMat.size();
  int m = adjMat[0].size();

  while(!q.empty()){
    pair<int, int> node = q.front();
    q.pop();
    for (int i = -1; i <= 1; i++){
      for (int j = -1; j <= 1; j++){
        int ro = node.first + i;
        int co = node.second + j;
        if (ro >= 0 && ro < n && co >= 0 && co < m && adjMat[ro][co] == 1 && visited[ro][co] == 0){
          visited[ro][co] = 1;
          q.push({ro, co});
        }
      }
    }
  }
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      int x; cin >> x;
      v[i][j] = x;
    }
  }

  vector<vector<int>> visited(n, vector<int>(m, 0));
  int count = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (!visited[i][j] && v[i][j] == 1){
        bfs(i, j, v, visited);
        count++;
      }
    }
  }
  cout << count << "\n";

  return 0;
}


/* 
5 4
0 1 1 0
0 1 1 0
0 0 1 0
0 0 0 0
1 1 0 1
 */