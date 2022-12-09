// https://cses.fi/problemset/task/1668
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

bool dfs(int n, vector<int> adj[], vector<int>& colors, vector<bool>& visited, int src, int color){
  if (colors[src] != 0)
    if (colors[src] != color)
      return false;
  if (visited[src]) return true;
  visited[src] = 1;
  colors[src] = color;
  for (auto it: adj[src])
    if (!dfs(n, adj, colors, visited, it, color == 1? 2:1)) return false;
  return true;
}

vector<int> checkBipartite(int n, vector<int> adj[]){
  vector<int> colors(n+1, 0);
  vector<bool> visited(n+1, 0);
  for (int i = 1; i <= n; i++)
    if (colors[i] == 0)
      if(!dfs(n, adj, colors, visited, i, 1)) return {-1};
  return colors;
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
  vector<int> team = checkBipartite(n, adj);
  if (team[0] != -1){
    for (int i = 1; i <= n; i++) cout << team[i] << " ";
    cout << "\n";
  } else cout << "IMPOSSIBLE\n";
  
  return 0;
}

/* 
5 3
1 2
1 3
4 5
*/

/* 
10 20
7 10
3 10
9 10
2 10
1 7
4 7
2 8
4 9
5 9
1 9
7 8
2 6
8 9
5 7
3 4
2 5
6 9
3 5
3 6
6 7
*/