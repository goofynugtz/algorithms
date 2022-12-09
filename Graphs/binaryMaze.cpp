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

int shortestPathInMaze(vector<vector<int>>& grid, pair<int,int>& source, pair<int,int>& destination){
  queue< pair< int, pair<int,int> > > q;
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> distance(n, vector<int>(m, 1e9));
  distance[source.first][source.second] = 0;
  q.push({0, {source.first, source.second}});
  
  while (!q.empty()){
    pair<int,int> node = q.front().second;
    int x = node.first, y = node.second;
    int d = q.front().first;
    q.pop();
    if (x-1 >= 0 && grid[x-1][y] == 1 && distance[x-1][y] > d+1){
      distance[x-1][y] = d+1;
      q.push({d+1, {x-1, y}});
    }
    if (x+1 < n && grid[x+1][y] == 1 && distance[x+1][y] > d+1){
      distance[x+1][y] = d+1;
      q.push({d+1, {x+1, y}});
    }
    if (y-1 >= 0 && grid[x][y-1] == 1 && distance[x][y-1] > d+1){
      distance[x][y-1] = d+1;
      q.push({d+1, {x, y-1}});
    }
    if (y+1 < m && grid[x][y+1] == 1 && distance[x][y+1] > d+1){
      distance[x][y+1] = d+1;
      q.push({d+1, {x, y+1}});
    }
  }
  return distance[destination.first][destination.second] == 1e9 ? -1: distance[destination.first][destination.second];
}

int main(void){
  setIO();
  vector<vector<int>> grid = {{1,1,1,1}, {1,1,0,1}, {1,1,1,1}, {1,1,0,0}, {1,0,0,1}};
  pair<int,int> source = {0,1};
  pair<int,int> destination = {2,2};

  cout << shortestPathInMaze(grid, source, destination) << "\n";
  return 0;
}