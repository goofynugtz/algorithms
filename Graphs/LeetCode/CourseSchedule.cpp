// https://leetcode.com/problems/course-schedule/
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define ll long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

class Solution {
  bool detectCycle(vector<int> adj[], int n){
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++){
      for (auto it: adj[i])
        indegree[it]++;
    }
    int x = 0;
    queue<int> q;
    for (int i = 0; i < n; i++){
      if(indegree[i] == 0)
        q.push(i);
    }
    while (!q.empty()){
      for (auto &it: adj[q.front()]){
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
      x++;
      q.pop();
    }
    return x == n;
  }
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> adj[numCourses];
    for (auto it: prerequisites)
      adj[it[1]].push_back(it[0]);
    
    if (detectCycle(adj, numCourses))
      return true;
    return false;
  }
};

int main(void){
  setIO();
  int n; cin >> n;
  return 0;
}