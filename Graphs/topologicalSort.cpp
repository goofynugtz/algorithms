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

void dfs(int currNode, vector<int> adj[], vector<bool>& visited, stack<int>& s){
  if (visited[currNode]) return;
  visited[currNode] = 1;
  for (auto node: adj[currNode]){
    if (!visited[node])
      dfs(node, adj, visited, s);
  }
  s.push(currNode);
}

// DFS: Stack
void topologicalSort(int n, vector<int> adj[]){
  vector<bool> visited(n, 0);
  stack<int> s;
  for (int i = 0; i < n; i++){
    if (!visited[i]){
      dfs(i, adj, visited, s);
    }
  }
  while (!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
}

// BFS: Queue
void topologicalSortKahns(int n, vector<int> adj[]){
  vector<int> indegree(n);
  for (int i = 0; i < n; i++)
    for (auto it: adj[i])
      indegree[it]++;

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (indegree[i] == 0) q.push(i);
  
  vector<int> topo;
  while (!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for (auto it: adj[node]){
      indegree[it]--;
      if (indegree[it] == 0) q.push(it);
    }
  }
  cout << "\n";
  for (auto it: topo) cout << it << " ";
  cout << "\n";
}

int main(void){
  setIO();
  int n, m;
  cin >> m >> n;
  vector<int> adj[n];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
  topologicalSort(n, adj);
  topologicalSortKahns(n, adj);
  return 0;
}