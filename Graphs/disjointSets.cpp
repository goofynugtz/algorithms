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

// TC: O(4alpha) ~ O(1)
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

/* class DisjointSet {
  private:
  vector<int> rank, parent;
  public:
    DisjointSet(int n){
      rank.resize(n+1,0);
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
      if (rank[a] == rank[b]) rank[a]++;
      if (rank[a] > rank[b]) parent[b] = a;
      else parent[a] = b;
    }
}; */