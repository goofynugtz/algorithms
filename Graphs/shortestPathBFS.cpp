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

// For graph having unit edge weights, or see test case below
vector<int> shortestPath(int n, vector<int> adj[]){
  vector<int> distance(n, 1e9);
  queue<pair<int,int>> q;
  distance[0] = 0;
  q.push({0,0});
  while (!q.empty()){
    int node = q.front().first;
    int d = q.front().second;
    q.pop();
    for (auto it: adj[node]){
      if (distance[it] > distance[node]+1){
        distance[it] = distance[node]+1;
        q.push({it, distance[node]+1});
      }
    }
  }
  return distance;
}

int main(void){
  setIO();
  int n, m;
  cin >> m >> n;
  vector<int> adj[n];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> distance = shortestPath(n, adj);
  for (auto it: distance) cout << it << " ";
  cout << "\n";
  return 0;
}

/* 
11 9
0 1
0 3
1 2
1 3
3 4
4 5
5 6
2 6
6 7
6 8
7 8
*/