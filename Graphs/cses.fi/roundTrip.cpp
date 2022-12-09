// https://cses.fi/problemset/task/1669
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

void detectCycle(int n, vector<int> adj[], int src, vector<bool>& visited){
  visited[src] = 1;
  // WARN: Incomplete. Start again.
}

vector<int> roundTrip(int n, vector<int> adj[]){

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
  vector<int> path = roundTrip(n, adj);
  if (path[0] != -1){
    for (int i = 1; i <= n; i++) cout << path[i] << " ";
    cout << "\n";
  } else cout << "IMPOSSIBLE\n";
  
  return 0;
}