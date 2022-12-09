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

int minimumEfforts(vector<vector<int>>& heights, pair<int,int> s, pair<int,int> d){
  priority_queue< pair< int, pair<int,int> >, 
  vector< pair<int, pair<int,int>>>, 
  greater< pair<int, pair<int,int>>>> q;
  
  int n = heights.size(), m = heights[0].size();
  vector<vector<int>> difference(n, vector<int>(m, 1e9));
  difference[s.first][s.second] = 0;
  q.push({0, {s.first, s.second}});
  while(!q.empty()){
    pair<int,int> node = q.top().second;
    int x = node.first, y = node.second;
    int diff = q.top().first;
    q.pop();
    if (x == n-1 && y == m-1) return diff;
    if (x-1 >= 0){
      int effort = max(diff,abs(heights[x][y]-heights[x-1][y]));
      if (effort < difference[x-1][y]){
        difference[x-1][y] = effort;
        q.push({effort, {x-1,y}});
      }
    }
    if (x+1 < n){
      int effort = max(diff,abs(heights[x][y]-heights[x+1][y]));
      if (effort < difference[x+1][y]){
        difference[x+1][y] = effort;
        q.push({effort, {x+1,y}});
      }
    }
    if (y-1 >= 0){
      int effort = max(diff,abs(heights[x][y]-heights[x][y-1]));
      if (effort < difference[x][y-1]){
        difference[x][y-1] = effort;
        q.push({effort, {x,y-1}});
      }
    }
    if (y+1 < m){
      int effort = max(diff,abs(heights[x][y]-heights[x][y+1]));
      if (effort < difference[x][y+1]){
        difference[x][y+1] = effort;
        q.push({effort, {x,y+1}});
      }
    }
  }
  return difference[d.first][d.second];
}

int main(void){
  setIO();
  vector<vector<int>> heights = {{8,2,2},{3,8,6},{5,3,5}};
  cout << minimumEfforts(heights, {0,0}, {2,2}) << "\n";
  return 0;
}