// https://leetcode.com/problems/find-the-town-judge/

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> adj[n+1];
    for (int i = 0; i < trust.size(); i++){
      adj[trust[i][0]].push_back(trust[i][1]);
    }
    vector<int> indegree(n+1, 0);
    vector<int> outdegree(n+1, 0);
    for (int i = 1; i <= n; i++){
      outdegree[i] = adj[i].size();
      for (auto it: adj[i])
        indegree[it]++;
    }
    
    int judge = -1;
    for (int i = 1; i <= n; i++){
      if (indegree[i] == n-1 && outdegree[i] == 0) judge = i;
    }
    return judge;
  }
};

int main(void){

  // int n = 3;
  int n = 2;
  // vector<vector<int>> trust = {{1,3}, {2,3}};
  vector<vector<int>> trust = {{1,2}};
  // vector<vector<int>> trust = {{1,3}, {2,3}, {3,1}};
  Solution s;
  int ans = s.findJudge(n, trust);
  cout << ans << "\n";
  return 0;
}