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

// When you have edge weights, or see test case below
// WARN: Does not work when there's signle negative weight
// as it would jump back and forth to minimize the distance endlessly
// better implementation would be with set but no difference in time complexity

vector<int> dijkstras(int n, vector<pair<int,int>> adj[], int source){
  priority_queue<pair<int,int>> q;
  vector<int> distance(n, 1e9);
  distance[source] = 0;
  q.push({0, source});
  while (!q.empty()){
    int node = q.top().second;
    int d = q.top().first;
    q.pop();
    for (auto it: adj[node]){
      if (distance[it.first] > d + it.second){
        distance[it.first] = d + it.second;
        q.push({d+it.second, it.first});
      }
    }
  }
  return distance;
}

int main(void){
  setIO();
  int n, m;
  cin >> m >> n;
  vector<pair<int,int>> adj[n];
  for (int i = 0; i < m; i++){
    int u, v, wt; cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  vector<int> result = dijkstras(n, adj, 0);
  for (auto it: result) cout << it << " ";
  cout << "\n";
  return 0;
}

/* 

8 6
0 1 4
0 2 4
1 2 2
2 3 3
2 4 1
2 5 6
3 5 2
4 5 3

*/