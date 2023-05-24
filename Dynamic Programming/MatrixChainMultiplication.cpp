#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define ll long long
#define MAX_N 100
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

class Solution{
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
public:
  int matrixMultiplication(int N, int arr[]){
    vector<vector<int>> DP(MAX_N, vector<int>(MAX_N, -1));
    return mcm(1,N-1,arr,DP);
  }
};


int main(void){
  setIO();
  int n; cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  Solution s;
  cout << s.matrixMultiplication(n, arr) << "\n";

  return 0;
}