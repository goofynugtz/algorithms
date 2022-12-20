// https://cses.fi/problemset/task/1638
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define ll long long
#define MOD int(1e9+7)
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

int checkTraps(int i, int j, vector<vector<char>>& grid ,int n, vector<vector<int>>& DP){
  cout << i << " " << j << "\n";
  if (i == n-1 && j == n-1) return 1;
  // if (grid[i][j] == '*') return 0;
  int paths = 0;
  if (i+1 < n && grid[i+1][j] != '*'){
    
    paths += 1+checkTraps(i+1, j, grid, n, DP);
  }
  if (j+1 < n && grid[i][j+1] != '*'){
    paths += 1+checkTraps(i, j+1, grid, n, DP);
  }
  return paths;
}

int gridPaths(int n, vector<vector<char>>& grid){
  vector<vector<int>> DP(n+1, vector<int>(n+1));
  return checkTraps(0, 0, grid, n, DP);
}

int main(void){
  setIO();
  int n; cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
      cin >> grid[i][j];
  cout << gridPaths(n, grid) << "\n";

  return 0;
}