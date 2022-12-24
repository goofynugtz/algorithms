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

ll cut(ll a, ll b, vector<vector<ll>>& DP){
  cout << a << " " << b << "\n";
  if (a > b) swap(a,b);
  if (DP[a][b] != INF) return DP[a][b];
  if (a == b) return DP[a][b] = 0;
  if (a == 1 || b == 1)
    return a == 1 ? b-1 : a-1;
  for (int i = 1; i < a; i++)
    DP[a][b] = min(DP[a][b], cut(i,b,DP)+cut(a-i,b,DP)+1);
  for (int i = 1; i < b; i++)
    DP[a][b] = min(DP[a][b], cut(a,i,DP)+cut(a,b-i,DP)+1);
  return DP[a][b];
}

ll rectangleCutting(ll a, ll b){
  cout << a << " " << b <<"\n";
  if (a == 0 || b == 0) return 0;
  vector<vector<ll>> DP(501, vector<ll>(501, INF));
  return cut(a, b, DP);
}

int main(void){
  setIO();
  ll a,b; cin >> a >> b;
  cout << rectangleCutting(a,b) << "\n";
  return 0;
}

