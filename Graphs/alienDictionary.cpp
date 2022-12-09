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

vector<int> topologicalSort(int n, vector<int> adj[]){
  vector<int> indegree(n);
  for (int i = 0; i < n; i++)
    for (auto it: adj[i]) indegree[it]++;
  
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
  return topo;
}

string findOrder(vector<string> dict, int n, int k){
  vector<int> adj[k];
  for (int i = 0; i < n-1; i++){
    string s1 = dict[i];
    string s2 = dict[i+1];
    int len = min(s1.length(), s2.length());
    for (int j = 0; j < len; j++){
      if (s1[j] != s2[j]){
        adj[int(s1[j] - 'a')].push_back(int(s2[j] - 'a'));
        break;
      }
    }
  }

  vector<int> topo = topologicalSort(k, adj);
  string ans = "";
  for (auto it: topo) ans += char(it+'a');
  return ans;
}

int main(void){

  int n, k; cin >> n >> k;
  vector<string> dict(n);
  for (int i = 0; i < n; i++) cin >> dict[i];
  cout << findOrder(dict, n, k);

  return 0;
}

/* 
5 4
baa
abcd
abca
cab
cad
*/