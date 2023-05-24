#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD int(1e9+7)

typedef long long ll;
void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

ll f(vector<ll>& coins, ll target, vector<ll>& DP){
  if (target <= 0) return 0;
  if (DP[target] != -1) return DP[target];
  ll count = INT_MAX;
  for (auto it: coins){
    if (target - it >= 0){
      count = min(1+f(coins, target-it, DP), count);
    }
  }
  return DP[target] = count;
}

ll combinations(ll n, ll x, vector<ll>& coins){
  vector<ll> DP(x+1, -1);
  DP[x] = f(coins, x, DP);
  if (DP[x] == INT_MAX){
    return -1;
  } else return DP[x];
}

int main(){
  ll n, x; cin >> n >> x;
  vector<ll> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];
  
  ll ways = combinations(n, x, coins);
  cout << ways << "\n";
  return 0;
}
