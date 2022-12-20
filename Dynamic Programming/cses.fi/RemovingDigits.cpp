// https://cses.fi/problemset/task/1637
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

int remove(int n, vector<int>& DP){
  if (n == 0) return DP[n] = 0;
  if (DP[n] != INT_MAX) return DP[n];
  string s = to_string(n);
  for (auto it: s){
    if (n-int(it-'0') != n && n-int(it-'0') >= 0)
      DP[n] = min(1+remove(n-int(it-'0'), DP), DP[n]);
  }
  return DP[n];
}

int removeDigits(int n){
  vector<int> DP(n+1, INT_MAX);
  return remove(n, DP);
}

int main(void){
  setIO();
  int n; cin >> n;
  cout << removeDigits(n);
  return 0;
}