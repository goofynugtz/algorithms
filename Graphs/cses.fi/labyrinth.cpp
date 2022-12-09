// https://cses.fi/problemset/task/1193
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

void bfs(vector<vector<char>>& adjMat, int Ai, int Aj, int Bi, int Bj){
  int n = adjMat.size(), m = adjMat[0].size();
  queue<pair<int,pair<int,int>>> q;
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  dist[Ai][Aj] = 0;
  q.push({0, {Ai, Aj}});
  map<pair<int,int>, pair<int,int>> parent;

  while(!q.empty()){
    pair<int,int> node = q.front().second;
    int i = node.first; int j = node.second;
    q.pop();
    
    if (i-1 >= 0 && (adjMat[i-1][j] == '.' || adjMat[i-1][j] == 'B') && dist[i-1][j] > dist[i][j]+1){
      dist[i-1][j] = dist[i][j]+1;
      q.push({dist[i][j]+1, {i-1, j}});
      parent[{i-1,j}] = {i,j};
    }
    if (i+1 < n && (adjMat[i+1][j] == '.' || adjMat[i+1][j] == 'B') && dist[i+1][j] > dist[i][j]+1){
      dist[i+1][j] = dist[i][j]+1;
      q.push({dist[i][j]+1, {i+1, j}});
      parent[{i+1,j}] = {i,j};
    }
    if (j-1 >= 0 && (adjMat[i][j-1] == '.' || adjMat[i][j-1] == 'B') && dist[i][j-1] > dist[i][j]+1){
      dist[i][j-1] = dist[i][j]+1;
      q.push({dist[i][j]+1, {i, j-1}});
      parent[{i,j-1}] = {i,j};
    }
    if (j+1 < m && (adjMat[i][j+1] == '.' || adjMat[i][j+1] == 'B') && dist[i][j+1] > dist[i][j]+1){
      dist[i][j+1] = dist[i][j]+1;
      q.push({dist[i][j]+1, {i, j+1}});
      parent[{i,j+1}] = {i,j};
    }
  }
  vector<char> path;
  if (dist[Bi][Bj] != 1e9){
    cout << "YES\n" << dist[Bi][Bj] << "\n";
    while (Bi != Ai || Bj != Aj){
      if (parent[{Bi,Bj}].first == Bi-1 && parent[{Bi,Bj}].second == Bj){
        path.push_back('D');
        Bi--;
      }
      if (parent[{Bi,Bj}].first == Bi+1 && parent[{Bi,Bj}].second == Bj){
        path.push_back('U');
        Bi++;
      }
      if (parent[{Bi,Bj}].first == Bi && parent[{Bi,Bj}].second == Bj-1){
        path.push_back('R');
        Bj--;
      }
      if (parent[{Bi,Bj}].first == Bi && parent[{Bi,Bj}].second == Bj+1){
        path.push_back('L');
        Bj++;
      }
    }
    reverse(path.begin(), path.end());
    for (auto it: path) cout << it;
    cout << "\n";
  } else {
    cout << "NO\n"; return;
  }
}

int main(void){
  setIO();
  int n, m, Ai, Aj, Bi, Bj; cin >> n >> m;
  vector<vector<char>> adjMat(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      char c; cin >> c;
      adjMat[i][j] = c;
      if (c == 'A'){
        Ai = i; Aj = j;
      }
      if (c == 'B'){
        Bi = i; Bj = j;
      }
    }
  }

  bfs(adjMat, Ai, Aj, Bi, Bj);
  return 0;
}


/* 
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/