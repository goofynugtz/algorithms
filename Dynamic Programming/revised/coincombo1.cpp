#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define MOD signed(1e9+7)

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

int combinations(int n, int x, vector<int>& coins){
  vector<int> dp(x+1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; i++){
    for (int j = 0; j < coins.size(); j++)
      if (i >= coins[j])
        dp[i] += dp[i-coins[j]] % MOD;
  }
  return dp[x] % MOD;
}


signed main(){
  int n, x; cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];
  
  int ways = combinations(n, x, coins);
  cout << ways << "\n";
  return 0;
}
