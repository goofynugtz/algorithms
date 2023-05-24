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

// Cycle detection in undirected graph
bool dfs(int src, int parent, vector<int> adj[], vector<int>& visited){
  visited[src] = 1;
  for (auto it: adj[src]){
    if (!visited[it])
      if (dfs(it, src, adj, visited)) 
        return true;
    else
      if (it != parent) return true;
  }
  return false;
}

bool detectCycle(int n, vector<int> adj[]){
  vector<int> visited(n,0);
  visited[0] = 1;
  for (int i = 0; i < n; i++)
    if (!visited[i])
      if (dfs(i, -1, adj, visited)) 
        return true;
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

  cout << detectCycle(n, adj);

  return 0;
}