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
  bool visited[n] = {0};
  visited[0] = 1;
  queue<int> q;
  q.push(0);
  while (!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";
    for (auto it: adj[node]){
      if (!visited[it]){
        visited[it] = 1;
        q.push(it);
      }
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
  bfs(n, adj);

  return 0;
}