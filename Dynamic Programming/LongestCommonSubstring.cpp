// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
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

class Solution {
  int longestCommonSubstringTD(string s1, string s2, int n, int m, vector<vector<int>>& DP){
    int length = 0;
    for (int i = 0; i <= n; i++){
      for (int j = 0; j <= m; j++){
        if (i == 0 || j == 0) DP[i][j] = 0;
        else if (s1[i-1] == s2[j-1]){
          DP[i][j] = 1+DP[i-1][j-1];
          length = max(length, DP[i][j]);
        } else DP[i][j] = 0;
      }
    }
    return length;
  }
  public:
  int longestCommonSubstr(string s1, string s2, int n, int m){
    vector<vector<int>> DP(n+1, vector<int>(m+1, -1));
    int ans = longestCommonSubstringTD(s1,s2,n,m,DP);
    /* for (auto row: DP){
      for (auto it: row) cout << it << " ";
      cout << "\n";
    } */
    return ans;
  }
};

int main(void){
  setIO();
  int a, b; cin >> a >> b;
  string str1, str2; cin >> str1 >> str2;
  Solution s;
  cout << s.longestCommonSubstr(str1, str2, a, b) << "\n";
  return 0;
}

/* 
6 6
ABCDGH
ACDGHR
*/