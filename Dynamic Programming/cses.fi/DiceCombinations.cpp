// https://cses.fi/problemset/task/1633
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

ll combinations(ll target, int face, vector<vector<ll>>& DP){
  if (target < 0) return 0;
  if (target == 0) return 1;
  if (DP[target][face] != 0) return DP[target][face];
  DP[target][face] = 0;
  for (int i = 1; i <= 6; i++)
    if (target-i >= 0)
      DP[target][face] += combinations(target-i, i, DP) % MOD;
  return DP[target][face] % MOD;
}

int main(void){
  setIO();
  ll n; cin >> n;
  vector<vector<ll>> DP(n+1, vector<ll>(7, 0));
  cout << combinations(n, 1, DP) << "\n";
  return 0;
}