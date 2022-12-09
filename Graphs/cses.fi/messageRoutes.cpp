// https://cses.fi/problemset/task/1667
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

void bfs(int n, vector<int> adj[]){
  queue<pair<int,int>> q;
  vector<int> distance(n+1, 1e9);
  vector<int> parent(n+1);
  distance[1] = 0;
  q.push({0, 1});
  while (!q.empty()){
    int node = q.front().second;
    q.pop();
    for (auto it: adj[node]){
      if (distance[it] > distance[node] + 1){
        distance[it] = distance[node]+1;
        parent[it] = node;
        q.push({distance[node]+1, it});
      }
    }
  }
  vector<int> path;
  if (distance[n] != 1e9){
    cout << distance[n]+1 << "\n";
    int i = n;
    while (i != 1){
      path.push_back(i);
      i = parent[i];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (auto it: path) cout << it << " ";
    cout << "\n";

  } else {
    cout << "IMPOSSIBLE\n";
    return;
  }
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
  bfs(n, adj);
  return 0;
}

/* 
5 5
1 2
1 3
1 4
2 3
5 4
*/