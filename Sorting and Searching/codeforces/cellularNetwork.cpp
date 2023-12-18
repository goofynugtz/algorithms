// https://codeforces.com/problemset/problem/702/C

#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
  #endif
}

// Predicate Function
bool checker(ll x, vector<ll>& a, vector<ll>& b){
  ll i = 0, j = 0;
  ll n = a.size(), m = b.size();
  while (i < n && j < m){
    if (abs(a[i] - b[j]) <= x) i++;
    else j++;
  }
  if (i >= n) return true;
  return false;
}

int main(void){
  setIO();
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);
  for (ll i = 0; i < n; i++) cin >> a[i];
  for (ll i = 0; i < m; i++) cin >> b[i];

  int radius = -1;
  ll l = 0, r = 2e9;
  
  while (l <= r){
    ll mid = l + r/2-l/2;
    if (checker(mid, a, b)){
      radius = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  cout << radius << "\n";
  
  return 0;
}