// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
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
  int lcsBottomUp(int x, int y, string s1, string s2, vector<vector<int>>& DP){
    if (DP[x][y] != -1) return DP[x][y];
    if (x == 0 || y == 0) return DP[x][y] = 0;
    if (s1[x-1] == s2[y-1]) return DP[x][y] = 1 + lcsBottomUp(x-1, y-1, s1, s2, DP);
    else return DP[x][y] = max(lcsBottomUp(x-1, y, s1, s2, DP), lcsBottomUp(x, y-1, s1, s2, DP));
  }

  int lcsTopDown(int x, int y, string s1, string s2, vector<vector<int>>& DP){
    for (int i = 0; i <= x; i++)
      for (int j = 0; j <= y; j++)
        if (i == 0 || j == 0) DP[i][j] = 0;
    
    for (int i = 1; i <= x; i++){
      for (int j = 1; j <= y; j++){
        if (s1[i-1] == s2[j-1]) DP[i][j] = 1 + DP[i-1][j-1];
        else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  return DP[x][y];
  }

  public:
  //Function to find the length of longest common subsequence (!substring) in two strings.
  int lcs(int x, int y, string s1, string s2){
    vector<vector<int>> DP(x+1, vector<int>(y+1, -1));
    return lcsTopDown(x,y,s1,s2,DP);
    // return lcsBottomUp(x,y,s1,s2,DP);
  }
};

int main(void){
  setIO();
  int a, b; cin >> a >> b;
  string str1, str2; cin >> str1 >> str2;
  Solution s;
  cout << s.lcs(a,b,str1,str2) << "\n";
  return 0;
}

/* 
6 7
ezupkr
ubmrapg
*/