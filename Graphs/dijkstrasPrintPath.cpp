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

vector<int> dijkstrasGetPath(int n, vector<pair<int,int>> adj[], int source, int destination){
  priority_queue<pair<int,int>> q;
  vector<int> distance(n+1, 1e9);
  vector<int> parent(n+1);
  for (int i = 1; i <= n; i++) parent[i] = i;
  distance[source] = 0;
  q.push({0, source});
  while (!q.empty()){
    int node = q.top().second;
    int d = q.top().first;
    q.pop();
    for (auto it: adj[node]){
      if (distance[it.first] > d + it.second){
        distance[it.first] = d + it.second;
        q.push({d + it.second, it.first});
        parent[it.first] = node;
      }
    }
  }
  vector<int> path;
  int i = destination;

  if (distance[i] != 1e9){
    path.push_back(i);
    while(i >= source){
      path.push_back(parent[i]);
      i = parent[i];
      if (parent[i] == source)break;
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
  } else return {-1};
}

int main(void){ 
  setIO();
  int n, m;
  cin >> m >> n;
  vector<pair<int,int>> adj[n+1];
  for (int i = 0; i < m; i++){
    int u, v, wt; cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  vector<int> result = dijkstrasGetPath(n, adj, 1, 5);
  for (auto it: result) cout << it << " ";
  cout << "\n";
  return 0;
}