// https://cses.fi/problemset/task/1634
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

ll calculateMinimumBottomUp(vector<ll>& coins, ll amount, vector<ll>& DP){
  if (amount == 0) return DP[amount] = 0;
  if (DP[amount] != INT_MAX) return DP[amount];
  for (int i = 0; i < (int)coins.size(); i++)
    if (amount - coins[i] >= 0)
      DP[amount] = min(DP[amount], 1+calculateMinimumBottomUp(coins, amount-coins[i], DP));
  return DP[amount];
}

ll calculateMinimumTopDown(vector<ll>& coins, ll amount){
  vector<ll> DP(amount+1, INT_MAX);
  DP[0] = 0;
  for (ll i = 1; i <= amount; i++)
    for (int j = 0; j < (int)coins.size(); j++)
      if (i - coins[j] >= 0)
        DP[i] = min(DP[i], 1 + DP[i-coins[j]]);
  return DP[amount];
}

ll minimizingCoins(vector<ll>& coins, int x){
  vector<ll> DP(x+1, INT_MAX);
  // int res = calculateMinimumBottomUp(coins, x, DP); // TLE due to overflow.
  ll res = calculateMinimumTopDown(coins, x);
  return res == INT_MAX ? -1 : res;
}

int main(void){
  setIO();
  int n; ll x; cin >> n >> x;
  vector<ll> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];
  cout << minimizingCoins(coins, x) << "\n";
  return 0;
}