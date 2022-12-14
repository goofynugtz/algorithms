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

int timer = 1;

void dfs(int node, int parent, vector<int>& visited, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges){
  visited[node] = 1;
  tin[node] = low[node] = timer++;
  for (auto it: adj[node]){
    if (it == parent) continue;
    if (!visited[it]){
      dfs(it, node, visited, adj, tin, low, bridges);
      low[node] = min(low[node], low[it]);
      if (low[it] > tin[node]){
        bridges.push_back({it, node});
      }
    } else {
      low[node] = min(low[node], low[it]);
    }
  }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
  vector<int> adj[n];
  for (auto it: connections){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
  }
  vector<int> visited(n, 0);
  int tin[n];
  int low[n];
  vector<vector<int>> bridges;
  dfs(0, -1, visited, adj, tin, low, bridges);
  return bridges;
}

int main(void){
  setIO();
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return 0;
}