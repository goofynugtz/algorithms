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

void dfs(int n, vector<int> adj[], int currNode, vector<bool>& visited){
  if (visited[currNode]){
    return;
  }
  visited[currNode] = 1;
  cout << currNode << " ";
  for (auto it: adj[currNode]){
    if (!visited[it]){
      dfs(n, adj, it, visited);
    }
  }
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
  vector<bool> visited(n, 0);
  dfs(n, adj, 0, visited);

  return 0;
}