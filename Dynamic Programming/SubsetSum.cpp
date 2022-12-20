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

bool isSum(vector<int>& arr, int index, int sum, vector<vector<int>>& DP){
  if (sum > 0 && index == 0) return DP[index][sum] = 0;
  if (sum == 0) return DP[index][sum] = 1;
  if (DP[index][sum] != -1) return DP[index][sum];
  if (sum >= arr[index-1])
    return DP[index][sum] = isSum(arr, index-1, sum-arr[index-1], DP) || isSum(arr, index-1, sum, DP);
  return DP[index][sum] = isSum(arr, index-1, sum, DP);
}

bool isSubsetSum(vector<int>& arr, int sum){
  int n = arr.size();
  vector<vector<int>> DP(n+1, vector<int>(sum+1, -1));
  int x = isSum(arr, n, sum, DP);

  /* for (auto row: DP){
    for (auto it: row) cout << setw(3) << it << " ";
    cout << "\n";
  } */
  return x;
}

signed main(void){
  setIO();
  vector<int> arr = {3,34,4,12,5,2};
  cout << isSubsetSum(arr, 14) << "\n";
  return 0;
}