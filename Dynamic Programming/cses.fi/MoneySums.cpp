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

int f(vector<int>& coins, int n, int sum, vector<vector<int>>& dp){
  if (sum == 0) return 1;
  if (n <= -1) return 0;
  if (sum < 0) return 0;
  if (dp[n][sum] != -1) return dp[n][sum];
  return dp[n][sum] = f(coins, n-1, sum - coins[n], dp) || f(coins, n-1, sum, dp);
}

set<int> createMoneySums(vector<int>& coins, int sum){
  set<int> ans;
  int n = coins.size();
  vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
  for (int i = 0; i <= sum; i++){
    f(coins, n-1, i, dp);
    if (dp[n-1][i] == 1) ans.insert(i);
  }
  return ans;
}

int main(void){
  setIO();
  int n; cin >> n;
  vector<int> coins(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
    sum += coins[i];
  }
  sort(coins.begin(), coins.end());
  set<int> st = createMoneySums(coins, sum);
  cout << st.size() << "\n";
  for (auto it: st) cout << it << " ";
  cout << "\n"; 
  return 0;
}
