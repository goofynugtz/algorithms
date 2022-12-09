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

int cheapestFlightKStops(int n, vector<pair<int,int>> adj[], int source, int destination, int k){
  queue<pair<int,pair<int,int>>> q;
  // {stops, {node, cost}};
  vector<int> cost(n, 1e9);
  cost[source] = 0;
  q.push({0, {source, 0}});
  while (!q.empty()){
    int stops = q.front().first;
    int node = q.front().second.first;
    int c = q.front().second.second;
    q.pop();
    if (stops > k) continue;
    for (auto it: adj[node]){
      if (c + it.second < cost[it.first] && stops <= k){
        cost[it.first] = c + it.second;
        q.push({stops+1,{it.first, c + it.second}});
      }
    }
  }
  for (auto it: cost) cout << it << " ";
  cout << "\n";
  return (cost[destination] == 1e9) ? -1 : cost[destination];
}

int main(void){
  setIO();
  int n, m;
  cin >> m >> n;
  vector<pair<int,int>> adj[n];
  for (int i = 0; i < m; i++){
    int u, v, wt; cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    // adj[v].push_back({u, wt});
  }
  int source, destination, k; cin >> source >> destination >> k;
  cout << cheapestFlightKStops(n, adj, source, destination, k) << "\n";
  return 0;  
}

/* 

5 4
0 1 100
1 2 200
2 0 100
1 3 600
2 3 200
0 3 1

*/