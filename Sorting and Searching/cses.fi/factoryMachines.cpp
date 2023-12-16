// https://cses.fi/problemset/task/1620

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
bool checker(ll secs, vector<ll>& v, ll products){
  ll n = v.size();
  ll count = 0;
  // Increases the number of products contributed in secs by n product lines.
  for (ll i = 0; i < n; i++) count += secs/v[i];
  if (count >= products) return true;
  else return false;
}

int main(void){
  setIO();
  ll n, t;
  cin >> n >> t;

  vector<ll> v(n);
  ll lo = INT_MAX, hi = INT_MIN;
  for (ll i = 0; i < n; i++){
    cin >> v[i];
    lo = min(lo, v[i]);
    hi = max(hi, v[i]);
  }

  // Search space is monotonic increasing. 
  // Searching for all possible values.
  ll l = lo, r = t*lo, ans = 1e6;

  while (l <= r){
    ll mid = l + (r/2 - l/2);
    /* 
      If: predicate function returns true -> It's a possible solution, Look for further minima.
      Else returns false: Not a solution, discard that half and move forward.
     */
    if (checker(mid, v, t)){
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