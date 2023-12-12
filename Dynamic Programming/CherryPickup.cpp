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

int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid){
  if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
  if (i == r-1){
    if (j1 == j2) return grid[i][j1];
    else return grid[i][j1] + grid[i][j2];
  }
  int maxVal = -1e8;
  for (int d1 = -1; d1 <= 1; d1++){
    for (int d2 = -1; d2 <= 1; d2++){
      int value = 0;
      if (j1 == j2) value = grid[i][j1];
      else value = grid[i][j1] + grid[i][j2];
      value += f(i+1, j1+d1, j2+d2, r, c, grid);
      maxVal = max(maxVal, value);
    }
  }
  return maxVal;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  vector<vector<int>> DP(r+1, vector<int>(c+1, -1));
  return f(0, 0, c-1, r, c, grid);
}

void solve(){
  int r, c; cin >> r >> c;
  vector<vector<int>> grid(r, vector<int>(c));
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
    }
  }
  maximumChocolates(r, c, grid);
}

signed main(){
  setIO();
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}