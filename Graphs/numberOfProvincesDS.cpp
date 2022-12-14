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

class DisjointSet {
  private:
  vector<int> size, parent;
  public:
  DisjointSet(int n){
    size.resize(n+1,1);
    parent.resize(n+1);
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int get(int node){
    return parent[node] = (parent[node] == node ? node : get(parent[node]));
  }

  void add(int u, int v){
    int a = get(u);
    int b = get(v);
    if (a == b) return;
    if (size[a] < size[b]){
      parent[a] = b;
      size[a] += size[b];
    } else {
      parent[b] = a;
      size[b] += size[a];
    }
  }
};

int numberOfProvinces(int n, vector<vector<int>>& adjMat){
  DisjointSet ds(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (adjMat[i][j] == 1)
        ds.add(i,j);  
  int count = 0;
  for (int i = 0; i < n; i++)
    if (ds.get(i) == i) count++;
  return count;
}

int main(void){
  setIO();
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j]; 
  cout << numberOfProvinces(n, adj) << "\n";
  return 0;
}