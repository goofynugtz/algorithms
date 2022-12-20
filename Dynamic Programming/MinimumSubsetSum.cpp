// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
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

int subsetSum(int i, int sum, vector<int>& subset, vector<vector<int>>& DP){
  if (sum > 0 && i == 0) return DP[i][sum] = 0;
  if (sum == 0) return DP[i][sum] = 1;
  if (DP[i][sum] != -1) return DP[i][sum];
  if (sum - subset[i-1] >= 0){
    return DP[i][sum] = subsetSum(i-1, sum-subset[i-1], subset, DP) || subsetSum(i-1, sum, subset, DP);
  } else return DP[i][sum] = subsetSum(i-1, sum, subset, DP);
}

int minDifference(vector<int>& arr){
  int range = 0;
  for (auto &it: arr) range += it;
  cout << range << "\n";
  int n = arr.size();
  vector<vector<int>> DP(n+1, vector<int>(range+1, -1));
  int s1 = 0;
  for (int i = 0; i <= range/2; i++){
    if (subsetSum(n, i, arr, DP)){
      s1 = max(i, s1);
    }
  }
  return range-(2*s1);
}

signed main(void){
  setIO();
  vector<int> arr = {1, 6, 5, 11};
  cout << minDifference(arr) << "\n";
  return 0;
}