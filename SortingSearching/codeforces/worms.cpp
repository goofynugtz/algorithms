// https://codeforces.com/contest/474/problem/B

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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i<n; i++) cin >> a[i];

  vector<ll> cummulative(n, 0);
  cummulative[0] = a[0];
  for (int i = 1; i<n; i++){
    cummulative[i] = a[i] + cummulative[i-1];
  }

  ll m; cin >> m;
  vector<ll> q(m);
  for (ll i = 0; i<m; i++){
    int key; cin >> key;
    int index = lower_bound(cummulative.begin(), cummulative.end(), key) - cummulative.begin();
    cout << index+1 << "\n";
  }

  return 0;
}