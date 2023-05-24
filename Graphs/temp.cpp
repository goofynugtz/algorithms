#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define MAX_N 500
int solve(pair<int,int> arr[], int low, int high, vector<vector<int>>& dp){  
  if (dp[low][high]!=-1)return dp[low][high];
  if (low==high)return dp[low][high]=0;
  if (high==low+1)return dp[low][high]=(arr[low].first * arr[low].second * arr[high].second);
  int val=INT_MAX;
  for (int i=low;i<high;i++){
    val = min(val,((arr[low].first*arr[i].second*arr[high].second)+solve(arr,low,i,dp)+solve(arr,i+1,high,dp)));
  }
  return dp[low][high]=val;      
}

int mcm(int i, int j, int arr[], vector<vector<int>>& DP){
  if (DP[i][j] != -1) return DP[i][j];
  if (i >= j) return DP[i][j] = 0;
  int cost = INT_MAX;
  for (int k = i; k < j; k++){
    int _temp = (mcm(i, k, arr, DP) + mcm(k+1, j, arr, DP)) + (arr[i-1]*arr[k]*arr[j]);
    cost = min(_temp, cost);
  }
  return DP[i][j] = cost;
}

int solveBottomUp(int i, int j, int arr[], vector<vector<int>>& dp){
  for (int i = 0; i < dp.size(); i++){
    for (int j = 0; j < dp.size(); j++){
      if (i >= j) dp[i][j] = 0;
      if (j == i+1) dp[i][j] = 0;
      int val = INT_MAX;
      for (int k = i; k < j; k++){
        int _temp = (dp[i][k] + dp[k+1][j]) + (arr[i-1]*arr[k]*arr[j]);
        val = min(_temp, val);
      }
    }
  }
  return dp[i][j];
}

int matrixMultiplication(int N, int arr[]){
  vector<vector<int>> DP(MAX_N, vector<int>(MAX_N, -1));
  return mcm(1,N-1,arr,DP);
}