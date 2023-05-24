// https://cses.fi/problemset/result/5808338/
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

// ll f(vector<ll> x, ll i, ll target, vector<vector<ll>>& dp){
//   if (target == 0) return 1;
//   if (target < 0) return 0;
//   if (i < 0) return 0;
//   if (dp[i][target] != -1) return dp[i][target];
//   ll ways = 0;
//   if (target >= x[i]){
//     ways = ((f(x, i-1, target-x[i], dp)%MOD) + (f(x, i-1, target, dp)%MOD))%MOD;
//   } else ways = f(x, i-1, target, dp)%MOD;
//   return dp[i][target] = ways%MOD;
// }

ll g(vector<ll>& x, ll n, ll target, vector<vector<ll>>& dp){
  dp[0][0] = 1;
  for (ll i = 1; i <= n; i++){
    for (ll j = 0; j <= target; j++){
      dp[i][j] = dp[i-1][j];
      if (j >= i)
        (dp[i][j] += dp[i-1][j-x[i]]) %= MOD;
    }
  }
  return dp[n][target];
}

ll ways(ll n){
  vector<ll> a(n+1);
  a[0] = 0;
  for (ll i = 1; i <= n; i++) a[i] = i;
  ll sum = n*(n+1)/2;
  if (sum % 2 != 0) return 0;
  sum /= 2;
  vector<vector<ll>> dp(n+1, vector<ll>(sum+1, 0));
  ll b = g(a, n-1, sum, dp);
  return b;
}

int main(){
  int n; cin >> n;
  int w = ways(n);
  cout << w << "\n";
  return 0;
}
