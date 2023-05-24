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

ll f(ll target, int face, vector<vector<ll>>& DP){
  if (target < 0) return 0;
  if (target == 0) return 1;
  if (DP[target][face] != -1) return DP[target][face];
  DP[target][face] = 0;
  for (int i = 1; i <= 6; i++)
    if (target >= i)
      DP[target][face] += f(target-i, i, DP) % MOD;
  return DP[target][face] % MOD;
}

ll combinations(ll n){
  vector<vector<ll>> DP(n+1, vector<ll>(7, -1));
  return DP[n][1] = f(n, 1, DP);
}

int main(){
  ll n; cin >> n;
  ll ways = combinations(n);
  cout << ways << "\n";
  return 0;
}
