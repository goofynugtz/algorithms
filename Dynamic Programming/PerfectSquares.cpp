// https://leetcode.com/problems/perfect-squares/description/
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define int long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

class Solution {
public:
  int f(int n, vector<int>& DP){
    cout << n << "\n";
    if (n == 0) return DP[n] = 0;
    if (n == 1) return DP[n] = 1;
    if (DP[n] != 1e8) return DP[n];
    DP[n] = n;
    for (int i = 1; i <= n; i++){
      if (n-(i*i) >= 0) DP[n] = min(DP[n], 1+f(n-(i*i), DP));
    }
    return DP[n];
  }
  int numSquares(int n) {
    vector<int> DP(n+1, 1e8);
    int _sq = sqrt(n);
    if (_sq*_sq == n) return DP[n] = 1;
    int res = f(n, DP);
    return res == 1e8 ? -1 : res;
  }
};

signed main(void){
  setIO();
  int n = 12;
  Solution s;
  cout << s.numSquares(n);
  return 0;
}