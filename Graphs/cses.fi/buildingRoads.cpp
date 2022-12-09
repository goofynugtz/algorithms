// https://cses.fi/problemset/task/1666
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

void dfs(vector<int> adj[], vector<bool>& visited, int source){
  visited[source] = 1;
  for (auto it: adj[source]){
    if (!visited[it])
      dfs(adj, visited, it);
  }
}

void disconnectedCities(int n, vector<int> adj[]){
  int count = 0;
  vector<bool> visited(n+1, 0);
  vector<pair<int,int>> toBeBuilt;
  for (int i = 1; i <= n; i++){
    if (!visited[i]){
      if (i > 1) toBeBuilt.push_back({i-1,i});
      dfs(adj, visited, i);
      count++;
    }
  }
  cout << count-1 << "\n";
  for (auto it: toBeBuilt) cout << it.first << " " << it.second << "\n";
}

int main(void){
  setIO();
  int n, m;
  cin >> n >> m;
  vector<int> adj[n+1];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  disconnectedCities(n, adj);
  return 0;
}

/* 
10 10
2 5
5 6
1 4
6 8
2 6
3 6
1 10
8 9
2 3
5 8
*/