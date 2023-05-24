// https://codeforces.com/problemset/problem/1709/B

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

void computeDamages(int n, vector<int>& a, vector<vector<int>>& dp){
  dp[0][0] = 0;
  for (int i = 1; i < n; i++){
    if (a[i] > a[i-1]) dp[i][0] = dp[i-1][0] + (a[i] - a[i-1]);
    else dp[i][0] = dp[i-1][0];
    if (a[i] < a[i-1]) dp[0][i] = dp[0][i-1] + (a[i-1] - a[i]);
    else dp[0][i] = dp[0][i-1];
  }
  
  for (int i = 1; i < n; i++){
    for (int j = 1; j < i; j++){
      if (i == j) continue;
      if (a[i] > a[i-1]) dp[i][j] = dp[i-1][j] + (a[i] - a[i-1]);
      else dp[i][j] = dp[i-1][j];
    }
    for (int j = i; j < n; j++){
      if (i == j) continue;
      if (a[j] < a[j-1]) dp[i][j] = dp[i][j-1] + (a[j-1] - a[j]);
      else dp[i][j] = dp[i][j-1];
    }
  }
  for (int i = 1; i < n; i++){
  }
  // cout << "\n\n";
  // for (auto row: dp){
  //   for (auto i: row) cout << i << "  ";
  //   cout << "\n";
  // }
  return;
}

void solve(){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> s(m);
  vector<int> t(m);
  for (int i = 0; i < m; i++){
    cin >> s[i] >> t[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  computeDamages(n, a, dp);
  // for (auto row: dp){
  //   for (auto i: row) cout << i << " ";
  //   cout << "\n";
  // }
  
  for (int i = 0; i < m; i++){
    cout << dp[s[i]-1][t[i]-1] << "\n";
  }
}

signed main(){
  // setIO();
  // int t; cin >> t;
  // while (t--)
    solve();
  return 0;
}