#include <bits/stdc++.h>
using namespace std;

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

// Kruskals:
// 1. Sort all edges respect to weights.
// 2. Pick nodes not having same parent
int spanningTree(int n, vector<pair<int,int>> adj[]){
  vector<pair<int,pair<int,int>>> edges;
  for (int i = 0; i < n; i++){
    for (auto it: adj[i]){
      int adjNode = it.first;
      int weight = it.second;
      int node = i;
      edges.push_back({weight, {node, adjNode}});
    }
  }
  DisjointSet ds(n);
  sort(edges.begin(), edges.end());
  int minimumSpanningWeight = 0;
  for (auto it: edges){
    int weight = it.first;
    int u = it.second.first;
    int v = it.second.second;
    if (ds.get(u) != ds.get(v)){
      minimumSpanningWeight += weight;
      ds.add(u,v);
    }
  }
  return minimumSpanningWeight;
}