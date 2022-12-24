#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define MAX_N (int)1e6+6
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

const int MOD = 1e9+7;

int main(void){
  setIO();
  vector<vector<ll>> DP(MAX_N+1, vector<ll>(2, 0));
  DP[1][0] = DP[1][1] = 1;
  for (int i = 2; i < MAX_N; i++){
    DP[i][0] = ((DP[i-1][0]*4)%MOD + DP[i-1][1])%MOD;
    DP[i][1] = (DP[i-1][0] + (DP[i-1][1]*2)%MOD)%MOD;
  }

  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    cout << (DP[n][0]+DP[n][1])%MOD << "\n";
  }
  return 0;
}

/* 
3
2
6
1337
 */