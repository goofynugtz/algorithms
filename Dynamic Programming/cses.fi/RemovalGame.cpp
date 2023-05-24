// https://cses.fi/problemset/task/1745
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

int sum(int l, int r, vector<int>& p){
  return p[r] - p[l-1];
}

int f(vector<int>& x, int l, int r, vector<int>& p){
  // cout << l << " " << r << "\n";
  if (l == r) return x[l];
  int score1 = x[l] + sum(l+1,r,p) - f(x, l+1, r, p);
  int score2 = x[r] + sum(l,r-1,p) - f(x, l, r-1, p);
  cout << score1 << " " << score2 << "\n";
  return max(score1, score2);
}

int RemovalGame(vector<int>& x, vector<int>& p){
  int n = x.size();
  int score = f(x, 1, n, p);
  return score;
}

int main(void){
  setIO();
  int n; cin >> n;
  vector<int> x(n+1);
  vector<int> p(n+1);
  p[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> x[i];
    p[i] = p[i-1] + x[i];
  }
  int ans = RemovalGame(x, p);
  cout << ans << "\n";

  return 0;
}
