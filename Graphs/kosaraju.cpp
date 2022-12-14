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

void dfs_stack(int node, vector<int>& visited, vector<int> adj[], stack<int>& st){
  visited[node] = 1;
  for (auto it: adj[node]){
    if (!visited[it]) 
      dfs_stack(it, visited, adj, st);
  }
  st.push(node);
}

void dfs(int node, vector<int>& visited, vector<int> adjT[]){
  visited[node] = 1;
  for (auto it: adjT[node]){
    if (!visited[it]) 
      dfs(it, visited, adjT);
  }
}

// aka Kosaraju's Algorithm
// Pair (u,v) nodes in a strongly connected component can go from u -> v awa v -> u.
int stronglyConnectedComponents(int n, vector<int> adj[]){
  vector<int> visited(n, 0);
  stack<int> st;
  // Step 1: Store (Sort) all nodes in order of finishing time.
  for (int i = 0; i < n; i++){
    if (!visited[i]) 
      dfs_stack(i, visited, adj, st);
  }
  // Step 2: Reverse all edges of graph.
  // The edges that are not inside a SCC become disconnecting points of SCC.
  vector<int> adjT[n];
  for (int i = 0; i < n; i++){
    visited[i] = 0;
    for (auto it: adj[i])
      adjT[it].push_back(i);
  }
  int scc = 0;
  while (!st.empty()){
    int node = st.top();
    st.pop();
    if (!visited[node]){
      scc++;
      dfs(node, visited, adjT);
    }
  }
  return scc;
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
