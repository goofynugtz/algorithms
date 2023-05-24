#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define MAX_N (int)501
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define ll long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}


class Solution{
public:
  bool isPalindrome(string s, int i, int j){
    for (int x = i, y= j; x < y; x++, y--)
      if (s[x] != s[y]) 
        return false;
    return true;
  }

  int cut(string& s, int x, int y, vector<vector<int>>& DP){
    for (int i = 0; i <= s.length(); i++){
      for (int j = 0; j <= s.length(); j++){
        if (i >= j) DP[i][j] = 0;
        if (isPalindrome(s,i,j)) DP[i][j] = 0;
        for (int k = i; k < j; k++){
          DP[i][j] = min(1 + DP[i][k] + DP[k+1][j], DP[i][j]);
        }
      }
    }
    return DP[x][y];
  }

  int partition(string& s, int i, int j, vector<vector<int>>& DP){
    if (DP[i][j] != -1) return DP[i][j];
    if (i >= j) 
      return DP[i][j] = 0;
    if (isPalindrome(s, i, j)) 
      return DP[i][j] = 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++){
      int left, right;
      if (DP[i][k] != -1) left = DP[i][k];
      else left
       = partition(s, i, k, DP);
      if (DP[k+1][j] != -1) right = DP[k+1][j];
      else right = partition(s, k+1, j, DP);
      int _temp = 1+left+right;
      ans = min(_temp, ans);
    }
    return DP[i][j] = ans;
  }

  int palindromicPartition(string str){
    vector<vector<int>> DP(MAX_N, vector<int>(MAX_N, -1));
    return cut(str, 0, str.length()-1, DP);
  }
};

int main(void){
  setIO();
  string st; cin >> st;
  Solution s;
  cout << s.palindromicPartition(st) << "\n";
  return 0;
}