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

// Prims Algorithm: Greedy
int spanningTree(int n, vector<pair<int,int>> adj[]){
  priority_queue<pair<int,int>,
  vector<pair<int,int>>, greater<pair<int,int>>> q;
  vector<bool> visited(n, 0);
  int sum = 0; 
  q.push({0, 0}); // {wt, node}
  while (!q.empty()){
    auto it = q.top();
    int node = it.second;
    int weight = it.first;
    q.pop();
    if (visited[node]) continue;
    visited[node] = 1;
    sum += weight;
    for (auto it: adj[node]){
      if (!visited[it.first]) {
        q.push({it.second, it.first});
      }
    }
  }
  return sum;
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

  return 0;
}