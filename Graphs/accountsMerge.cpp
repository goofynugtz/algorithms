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

vector<vector<string>> mergeDetails(vector<vector<string>>& details){
  int n = details.size();
  DisjointSet ds(n);
  unordered_map<string, int> mailToNode;
  for (int i = 0; i < n; i++){
    for (int j = 1; j < details[i].size(); j++){
      string email = details[i][j];
      if (mailToNode.find(email) == mailToNode.end()){
        mailToNode[email] = i;
      } else {
        ds.add(i, mailToNode[email]);
      }
    }
  }
  vector<string> mails[n];
  for (auto it: mailToNode){
    string email = it.first;
    int node = ds.get(it.second);
    mails[node].push_back(email);
  }
  vector<vector<string>> ans(n);
  for (int i = 0; i < n; i++){
    if (mails[i].size() == 0) continue;
    sort(mails[i].begin(), mails[i].end());
    vector<string> temp;
    temp.push_back(details[i][0]);
    for (auto it: mails[i])
      temp.push_back(it);
    ans.push_back(temp);
  }
  return ans;
}