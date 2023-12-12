// https://cses.fi/problemset/task/1085

#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

// Predicate Function
bool checker(ll x, ll n, vector<ll>& v, ll k){
  ll sum = 0, count = 1;
  for (ll i = 0; i < n; i++){
    if (v[i] > x) return false;
    if (sum + v[i] <= x) sum += v[i];
    else {
      sum = v[i];
      count++;
    }
  }
  if (count > k) return false;
  else return true;
}

int main(void){
  setIO();
  ll k, n;
  cin >> n >> k;

  vector<ll> v(n);
  ll lo = INT_MIN, all = 0;
  for (ll i = 0; i < n; i++){
    cin >> v[i];
    lo = max(lo, v[i]);
    all += v[i];
  }

  // Search space is monotonic increasing. 
  // Searching for all possible values.
  ll l = lo, r = all, ans = 1e6;

  while (l <= r){
    ll mid = l + (r/2 - l/2);
    /* 
      If: predicate function returns true -> It's a possible solution, Look for further minima.
      Else returns false: Not a solution, discard that half and move forward.
     */
    if (checker(mid, n, v, k)){
      ans = mid;
      r = ans-1;
    } else l = mid+1;
  }
  cout << ans << "\n";
  return 0;
}



/* 
100 2
302 503 384 774 675 522 588 143 981 105 5 670 710 75 467 733 361 835 463 695 329 665 230 957 403 81 524 497 740 13 921 395 264 790 984 225 315 47 618 868 437 537 342 29 914 401 210 992 438 144 724 676 238 222 234 720 494 516 672 166 41 171 265 428 180 358 199 293 691 677 72 436 173 62 817 36 61 172 204 756 899 437 922 216 417 560 466 62 588 125 509 677 11 971 310 403 344 816 59 316
 */