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

// Cycle detection in undirected graph
// bfs
bool detectCycle(vector<int> adj[], vector<bool>& visited){
  // { node, parent }
  queue<pair<int, int>> q;
  q.push({1, -1});
  visited[1] = 1;

  while (!q.empty()){
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (auto it: adj[node]){
      if (it != parent){
        if (visited[it]) return true;
        else {
          q.push({it, node});
          visited[it] = 1;
        }
      }
    }
  }
  return false;
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<int> adj[n]; // 0 based indexing
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n, 0);
  cout << detectCycle(adj, visited);

  return 0;
}

/* 
7 7
1 2
2 5
5 7
7 6
6 3
4 3
3 1
*/