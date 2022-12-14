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

bool dfs(int i, int src, int parent, vector<int> adj[], vector<int>& visited, vector<int>& trip){
  visited[i] = 1;
  trip.push_back(i);
  for (auto &it: adj[i]){
    if (!visited[it]){
      if (dfs(it, src, i, adj, visited, trip)){
        return true;
      }
    } else if (it != parent){
      trip.push_back(it);
      return true;
    }
  }
  trip.pop_back();
  return false;
}

vector<int> roundTrip(int n, vector<int> adj[]){
  vector<int> visited(n+1, 0);
  vector<int> trip;
  for (int i = 1; i <= n; i++){
    if (!visited[i]){
      if (dfs(i, i, -1, adj, visited, trip)){
        vector<int> ans;
        for (int j = trip.size()-1; j >= 0; j--){
          ans.push_back(trip[j]);
          if (trip[j] == trip[trip.size()-1] && j+1 != trip.size()) break;
        }
        return ans;
      }
    }
  }
  return {-1};
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
    cout << path.size() << "\n";
    for (auto &it:path) cout << it << " ";
    cout << "\n";
  } else cout << "IMPOSSIBLE\n";
  return 0;
}

/* 
WARN: Working online but not offline
4 3
2 3
3 4
2 4
*/