// https://cses.fi/problemset/task/1635
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

ll combinationsBottomUp(vector<ll>& coins, ll amount, vector<ll>& DP){
  if (amount == 0) return DP[amount] = 1;
  if (DP[amount] != 0) return DP[amount];
  for (int i = 0; i < (int)coins.size(); i++)
    if (amount - coins[i] >= 0)
      DP[amount] += combinationsBottomUp(coins, amount-coins[i], DP) % MOD;
  return DP[amount] % MOD;
}

ll combinationsTopDown(vector<ll>& coins, ll amount, vector<ll>& DP){
  DP[0] = 1; // DP[amount]
  for (ll i = 1; i <= amount; i++)
    for (int j = 0; j < (int)coins.size(); j++)
      if (i - coins[j] >= 0)
        DP[i] += DP[i-coins[j]] % MOD;
  return DP[amount];
}

ll minimizingCoins(vector<ll>& coins, int x){
  vector<ll> DP(x+1, 0);
  // ll res = combinations(coins, x, DP) % MOD; // TLE due to overflow.
  ll res = combinationsTopDown(coins, x, DP) % MOD;
  return res;
}

int main(void){
  setIO();
  int n; ll x; cin >> n >> x;
  vector<ll> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];
  cout << minimizingCoins(coins, x) << "\n";
  return 0;
}