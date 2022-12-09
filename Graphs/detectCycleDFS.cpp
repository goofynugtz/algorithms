#pragma GCC optimize ("O2")
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
// WARN: incomplete
bool detectCycle(int i, int parent, vector<int> adj[], vector<bool>& visited){
  visited[i] = 1;
  for (auto it: adj[i]){
    if (it != parent){
      if (visited[it]) return true;
      else if (detectCycle(it, i, adj, visited)) return true;
    }
  }
  return false;
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<int> adj[n+1]; // 1 based indexing
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n, 0);
  cout << detectCycle(0, -1, adj, visited);

  return 0;
}