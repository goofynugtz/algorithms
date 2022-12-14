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

vector<int> numberOfIslands(int n, int m, vector<pair<int,int>>& operators){
  DisjointSet ds(n*m);
  vector<vector<int>> visited(n, vector<int>(m, 0));
  int count = 0;
  vector<int> ans;
  for (auto it: operators){
    int row = it.first;
    int col = it.second;
    if (visited[row][col]){
      ans.push_back(count);
      continue;
    }
    visited[row][col] = 1;
    count++;
    if (row-1 >= 0 && visited[row-1][col]){
      int index = row*m + col;
      int adjIndex = (row-1)*m + col;
      if (ds.get(index) != ds.get(adjIndex)){
        count--;
        ds.add(index, adjIndex);
      }
    }
    if (row+1 < n && visited[row+1][col]){
      int index = row*m + col;
      int adjIndex = (row+1)*m + col;
      if (ds.get(index) != ds.get(adjIndex)){
        count--;
        ds.add(index, adjIndex);
      }
    }
    if (col-1 >= 0 && visited[row][col-1]){
      int index = row*m + col;
      int adjIndex = row*m + (col-1);
      if (ds.get(index) != ds.get(adjIndex)){
        count--;
        ds.add(index, adjIndex);
      }
    }
    if (col+1 < m && visited[row][col+1]){
      int index = row*m + col;
      int adjIndex = row*m + (col+1);
      if (ds.get(index) != ds.get(adjIndex)){
        count--;
        ds.add(index, adjIndex);
      }
    }
    ans.push_back(count);
  }
  return ans;
}

int main(void){
  return 0;
}