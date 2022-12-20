// https://leetcode.com/problems/target-sum/
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
  int subsetSum(vector<int>& subset, int i, int sum, vector<vector<int>>& DP){
    if (i == 0 && sum > 0) return DP[i][sum] = 0;
    if (i == 0 && sum == 0) return DP[i][sum] = 1;
    if (DP[i][sum] != -1) return DP[i][sum];
    int count = 0;
    if (sum - subset[i-1] >= 0){
      count = subsetSum(subset, i-1, sum-subset[i-1], DP)+subsetSum(subset, i-1, sum, DP);
    } else count = subsetSum(subset, i-1, sum, DP);
    return DP[i][sum] = count;
  }

  int subsetSumTopDown(vector<int>& subset, int index, int sum, vector<vector<int>>& DP){
    int n = subset.size();
    for (int j = 1; j <= n; j++)
      DP[j][0] = 0;
    for (int j = 1; j <= sum; j++)
      DP[0][j] = 0;
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++){
      for (int j = 0; j <= sum; j++){
        if (j - subset[i-1] >= 0)
          DP[i][j] = DP[i-1][j-subset[i-1]] + DP[i-1][j];
        else DP[i][j] = DP[i-1][j];
      }
    }
    return DP[index][sum];
  }
  
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int range = 0;
    for (auto it: nums) range += it;
    if (range < abs(target)) return 0;
    int n = nums.size();
    vector<vector<int>> DP(n+1, vector<int>(2*range+1, -1));
    int s1 = (range+target)/2;
    if ((range+target) % 2 == 1) return 0;
    int topdown = subsetSumTopDown(nums, n, s1, DP); 
    return DP[n][s1];
    // int recursive = subsetSum(nums, n, s1, DP);
    // return recursive;
  }
};

signed main(void){
  setIO();
  vector<int> arr = {100};
  Solution s;
  cout << s.findTargetSumWays(arr, -200);
  return 0;
}