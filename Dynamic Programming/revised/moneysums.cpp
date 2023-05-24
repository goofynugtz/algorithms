#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD int(1e9+7)
typedef long long ll;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

int f(vector<int>& x, int i, int amount, vector<int>& dp){
  if (amount == 0) return 1;
  if (amount < 0) return 0;
  if (dp[amount] != -1) return dp[amount];
  int flag = 0;
  // if (amount >= x[i])
    flag = f(x, i-1, amount-x[i], dp) || f(x, i-1, amount, dp);
  return dp[amount] = flag;
}

set<int> combinations(int n, vector<int>& x){
  int sum = 0;
  for (auto it: x) sum += it;
  vector<int> dp(sum+1, -1);
  // for (auto it: dp) cout << it << " ";
  // cout << "\n";
  set<int> ans;
  for (int i = 0; i <= sum; i++){
    int fl = f(x, n, i, dp);
    if (dp[i] == 1) ans.insert(i);
  }
  return ans;
}

int main(){
  int n; cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  set<int> ways = combinations(n, x);
  cout << ways.size() << "\n";
  for (auto it: ways) cout << it << " ";
  cout << "\n";
  return 0;
}
