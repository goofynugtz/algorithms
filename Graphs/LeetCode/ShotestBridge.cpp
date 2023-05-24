// https://leetcode.com/problems/shortest-bridge/
#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Solution {
  void dfs(int ro, int co, vector<vector<int>>& grid, vector<vector<int>>& visited, int distance, vector<int>& ds){
    cout << ro << " " << co << " " << grid[ro][co] << " " << distance << "\n";
    visited[ro][co] = 1;
    if (grid[ro][co] == 1){
      ds.push_back(distance-1);
      return;
    }
    if (ro-1 >= 0 && (grid[ro-1][co] == 0 || grid[ro-1][co] == 1) && visited[ro-1][co] != 1)
      cout << "Going to: " << ro-1 << " " << co << "\n";
      dfs(ro-1, co, grid, visited, distance+1, ds);
    
    if (ro+1 < grid.size() && (grid[ro+1][co] == 0 || grid[ro+1][co] == 1) && visited[ro+1][co] != 1)
      cout << "Going to: " << ro+1 << " " << co << "\n";
      dfs(ro+1, co, grid, visited, distance+1, ds);
    
    if (co-1 >= 0 && (grid[ro][co-1] == 0 || grid[ro][co-1] == 1) && visited[ro][co-1] != 1)
      cout << "Going to: " << ro << " " << co-1 << "\n";
      dfs(ro, co-1, grid, visited, distance+1, ds);
    
    if (co+1 < grid.size() && (grid[ro][co+1] == 0 || grid[ro][co+1] == 1) && visited[ro][co+1] != 1)
      cout << "Going to: " << ro << " " << co+1 << "\n";
      dfs(ro-1, co+1, grid, visited, distance+1, ds);
  }

  int computeMinimumDistanceUsingDfs(vector<vector<int>>& markedGrid){
    int n = markedGrid.size();

    vector<int> ds;
    int minDistance = INT_MAX;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (markedGrid[i][j] == 2){
          vector<vector<int>> visited(n, vector<int>(n, 0));
          // previewGrid(markedGrid);
          dfs(i, j, markedGrid, visited, 0, ds);
        }
      }
    }
    for (auto it: ds) cout << it << " ";
    cout << "\n";
    return *min_element(ds.begin(), ds.end());
  }


  void markInitialIslandUsingBfs(vector<vector<int>>& grid, int x1, int y1){
    int n = grid.size();
    // Turn the 1s to 2s in that island
    grid[x1][y1] = 2;
    queue<pair<int,int>> q;
    q.push({x1,y1});
    while (!q.empty()){
      pair<int, int> node = q.front();
      q.pop();
      int i = node.first, j = node.second;
      grid[i][j] = 2;
      if (i-1 >= 0 && grid[i-1][j] == 1)
        q.push({i-1, j});
      if (i+1 < n && grid[i+1][j] == 1)
        q.push({i+1, j});
      if (j-1 >= 0 && grid[i][j-1] == 1)
        q.push({i, j-1});
      if (j+1 < n && grid[i][j+1] == 1)
        q.push({i, j+1});
    }
  }

  pair<int,int> getInitialPosition(vector<vector<int>>& grid){
    int n = grid.size();
    int x1, y1;
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 1)
          x1 = i, y1 = j;
    return {x1,y1};
  }

  void previewGrid(vector<vector<int>>& grid){
    cout << "\n";
    for (auto row: grid){
      for (auto it: row) cout << it << " ";
      cout << "\n";
    }
    cout << "\n";
  }

public:
  int shortestBridge(vector<vector<int>>& grid) {
    
    pair<int,int> init = getInitialPosition(grid);
    int x1 = init.first, y1 = init.second;
    // find the start island 
    markInitialIslandUsingBfs(grid, x1, y1);
    previewGrid(grid);
    // Now a dfs to second island with monitoring distance
    int minDistance = computeMinimumDistanceUsingDfs(grid);
    return minDistance;
  }
};

int main(void){
  // vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
  // vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
  vector<vector<int>> grid = {{0,1},{1,0}};
  Solution s;
  cout << s.shortestBridge(grid);

  return 0;
}