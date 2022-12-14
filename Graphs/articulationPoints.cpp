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

int timer = 0;

void dfs(int node, int parent, vector<int>& visited, int tin[], int low[], vector<int>& mark, vector<int> adj[]){
  visited[node] = 1;
  tin[node] = low[node] = timer++;
  int child = 0;
  for (auto it: adj[node]){
    if (it == parent) continue;
    if (!visited[it]){
      dfs(it, node, visited, tin, low, mark, adj);
      low[node] = min(low[node], low[it]);
      if (low[it] >= tin[node] && parent != -1){
        mark[node]++;
      }
      child++;
    } else {
      low[node] = min(low[node], tin[it]);
    }
  }
  if (child > 1 && parent == -1){
    mark[node]++;
  }
}

vector<int> articulationPoints(int n, vector<int> adj[]){
  vector<int> visited(n, 0);
  int tin[n];
  int low[n];
  vector<int> mark(n, 0);
  for (int i = 0; i < n; i++){
    if (!visited[i]){
      dfs(i, -1, visited, tin, low, mark, adj);
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++)
    if (mark[i] != 0) 
      ans.push_back(i);
  
  if (ans.size() == 0) return {-1};
  return ans;
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

  return 0;
}