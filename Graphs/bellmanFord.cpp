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

vector<int> bellmanFord(int n, vector<vector<int>>& edges, int source){
  vector<int> distance(n, 1e8);
  distance[source] = 0;
  for (int i = 0; i < n-1; i++){
    for (auto it: edges){
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if (distance[u] != 1e8 && distance[u]+wt < distance[v]){
        distance[v] = distance[u]+wt;
      }
    }
  }
  for (auto it: edges){
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    if (distance[u] != 1e8 && distance[u]+wt < distance[v]){
      return {-1};
    }
  }
  return distance;
}

int main(void){
  setIO();
  int n,m; cin >> n >> m;
  /* vector<pair<int,int>> adj[n];
  for (int i = 0; i < m; i++){
    int u,v,wt; cin >> u >> v >> wt;
    adj[u].push_back({v,wt});
  } */
  vector<vector<int>> edges(n, vector<int>(3));
  for (int i = 0; i < m; i++){
    int u, v, wt; cin >> u >> v >> wt;
    edges[i][0] = u;
    edges[i][1] = v;
    edges[i][2] = wt;
  }
  vector<int> d = bellmanFord(n, edges, 0);
  for (auto it: d) cout << it << " "; cout << "\n";
  return 0;
}

/* 
2 1
0 1 9
0
*/