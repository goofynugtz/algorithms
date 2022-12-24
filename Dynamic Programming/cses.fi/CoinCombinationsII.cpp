// https://cses.fi/problemset/task/1636
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

ll combinationsBottomUp(vector<ll>& coins, ll amount, vector<ll>& DP, set<ll>& s, map<set<ll>, int>& m){
  if (amount == 0){
    m[s]++;
    return DP[amount] = 1;
  }
  if (DP[amount] != 0) return DP[amount];
  for (int i = 0; i < (int)coins.size(); i++)
    if (amount - coins[i] >= 0){
      s.insert(coins[i]);
      DP[amount] += combinationsBottomUp(coins, amount-coins[i], DP, s, m) % MOD;
      s.erase(coins[i]);
    }
  return m.size()%MOD;
}

ll minimizingCoins(vector<ll>& coins, int x){
  vector<ll> DP(x+1, 0);
  set<ll> s;
  map<set<ll>, int> m;
  ll res = combinationsBottomUp(coins, x, DP, s, m) % MOD; // TLE due to overflow.
  // ll res = combinationsTopDown(coins, x, DP) % MOD;
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