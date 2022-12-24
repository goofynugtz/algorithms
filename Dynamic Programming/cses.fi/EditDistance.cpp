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

int getLargestSequence(string s1, int x, string s2, int y, vector<vector<int>>& DP){
  if (DP[x][y] != -1) return DP[x][y];
  if (x == 0) return y;
  if (y == 0) return x;
  if (s1[x-1] == s2[y-1])
    return DP[x][y] = getLargestSequence(s1, x-1, s2, y-1, DP);
  else return DP[x][y] = 1+min({getLargestSequence(s1, x-1, s2, y, DP), getLargestSequence(s1, x, s2, y-1, DP), getLargestSequence(s1, x-1, s2, y-1, DP)});
}

int getLargestSequenceTD(string s1, int x, string s2, int y, vector<vector<int>>& DP){
  for (int i = 0; i <= x; i++){
    for (int j = 0; j <= y; j++){
      if (i == 0 || j == 0){
        if (i == 0) DP[i][j] = j;
        if (j == 0) DP[i][j] = i;
      } else {
        if (s1[i-1] == s2[j-1]) DP[i][j] = DP[i-1][j-1];
        else DP[i][j] = 1+min({DP[i-1][j], DP[i][j-1], DP[i-1][j-1]});
      }
    }
  }
  return DP[x][y];
}

int main(void){
  setIO();
  string s1, s2; cin >> s1 >> s2;
  int x = s1.length();
  int y = s2.length();
  vector<vector<int>> DP(x+1, vector<int>(y+1, -1));
  cout << getLargestSequenceTD(s1, x, s2, y, DP);
  return 0;
}

/* 
HSMOWJXKGRWSMD
JMRTLLNPXKKXZC
*/