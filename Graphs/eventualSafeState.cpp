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

void dfs(int curr, vector<int> adj[], vector<bool>& visited){
  if (visited[curr]) return;
  visited[curr] = 1;
  for (auto it: adj[curr]){
    if (!visited[it]){
      dfs(it, adj, visited);
    }
  }
}

bool isThisNodeSafe(int node, vector<int> adj[], vector<bool>& visited, vector<int>& pathVisited, vector<int>& check){
  visited[node] = 1;
  pathVisited[node] = 1;
  check[node] = 0;
  for (auto it: adj[node]){
    if (!visited[node])
      if (isThisNodeSafe(it, adj, visited, pathVisited, check)) return true;
    else if (pathVisited[node] == 1) return true;
  }
  check[node] = 1;
  pathVisited[node] = 0;
  return false;
}

vector<int> eventualSafeNodes(int n, vector<int> adj[]){
  vector<int> safeNode(n, 1);

  for (int i = 0; i < n; i++){

  }
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }


  return 0;
}