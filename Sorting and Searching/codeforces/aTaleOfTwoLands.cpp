// https://codeforces.com/problemset/problem/1166/C

#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

void setIO(){
  fast;
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout);
  // #endif
}

int main(void){
  setIO();

  ll n; cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++){
    ll x; cin >> x;
    a[i] = abs(x);
  }

  sort(a.begin(), a.end());
  ll count = 0;
  for (ll i = 0; i < n; i++){
    count += upper_bound(a.begin(), a.end(), 2*a[i]) - a.begin() - (i+1);
  }
  cout << count << "\n";

  return 0;
}
