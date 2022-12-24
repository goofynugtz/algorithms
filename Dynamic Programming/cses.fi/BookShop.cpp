// https://cses.fi/problemset/task/1158
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

int compute(int i, int j, vector<int>& price, vector<int>& pages, vector<vector<int>>& DP){
  // cout << j << " " << i << " " << totalPages << "\n";
  if (i == 0 || j == 0) return DP[i][j] = 0;
  if (j - price[i-1] >= 0){
    return DP[i][j] = max(pages[i-1] + compute(i-1, j - price[i-1], price, pages, DP), compute(i-1, j, price, pages, DP));
  } else return DP[i][j] = compute(i-1, j, price, pages, DP);
}

int computeTopDown(int totalCost, vector<int>& prices, vector<int>& pages, vector<vector<int>>& DP){
  int n = prices.size();
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= totalCost; j++){
      if (i == 0 || j == 0) DP[i][j] = 0;
      else {
        if (j - prices[i-1] >= 0)
          DP[i][j] = max(pages[i-1] + DP[i-1][j-prices[i-1]], DP[i-1][j]);
        else 
          DP[i][j] = DP[i-1][j];
      }
    } 
  }
  return DP[n][totalCost];
}

int bookShop(int totalCost, vector<int>& price, vector<int>& pages){
  int n = price.size();
  vector<vector<int>> DP(n+1, vector<int>(totalCost+1, -1));
  // int ans = compute(n, totalCost, price, pages, DP);
  int ans = computeTopDown(totalCost, price, pages, DP);
  return ans;
}

int main(void){
  setIO();
  int n, x; cin >> n >> x;
  vector<int> h(n), s(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) cin >> s[i];

  cout << bookShop(x, h, s) << "\n";
  return 0;
}