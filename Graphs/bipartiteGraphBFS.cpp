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

  bool detectOddLengthCycle(int n, vector<int> adj[], vector<int>& visited, vector<int>& colors){
    visited[n] = 1;
    queue<pair<int, int>> q;
    q.push({n,1});
    colors[n] = 1;

    while (!q.empty()){
      int node = q.front().first;
      int color = q.front().second;
      q.pop();

      for (auto it: adj[node]){
        int c = (color == 1) ? 2 : 1;
        if (!visited[it]){
          q.push({it, c});
          visited[it] = 1;
          colors[it] = c;
        } else if (c != colors[it]) return true;
      }
    }
    return false;
  }

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> visited(n, 0);
  vector<int> colors(n, -1);
  cout << detectOddLengthCycle(0, adj, visited, colors);

  return 0;
}

/* CASE 1
6 6
0 4
1 4
2 4
5 4
2 3
0 5
 */

/* CASE 2 
6 6
4 0
4 1
4 2
4 5
2 3
3 5
 */