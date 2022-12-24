// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
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

class Solution{
  int cut(vector<int>& price, int n, vector<int>& DP){
    if (n == 0) return DP[n] = 0;
    if (DP[n] != -1) return DP[n]; 
    int profit = INT_MIN;
    for (int i = 1; i <= n; i++)
      profit = max(price[i-1]+cut(price, n-i, DP), profit);
    return DP[n] = profit;
  }

  public:
  int cutRod(vector<int>& price){
    int n = price.size();
    if (n == 0) return 0;
    vector<int> DP(n+1, -1);
    int ans = cut(price, n, DP);
    return ans;
  }
};

int main(void){
  setIO();
  int n; cin >> n;
  vector<int> price(n, 0);
  for (int i = 0; i < n; i++)
    cin >> price[i];
  Solution s;
  cout << s.cutRod(price) << "\n";
  return 0;
}

/* 
8
1 5 8 9 10 17 17 20
*/