// https://cses.fi/problemset/task/1746
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

int arrayDescription(int n, int m, vector<int> x, int zeroCount){
  if (zeroCount == 0) return 1;
  int ways = 0;
  for (int i = 0; i < n; i++){
    if (x[i] == 0){
      if (x[i+1] == 0){
        x[i] = x[i-1]+1;
        ways += arrayDescription(n, m, x, zeroCount-1);
        x[i] = x[i-1];
        ways += arrayDescription(n, m, x, zeroCount-1);
        x[i] = x[i-1]+1;
        ways += arrayDescription(n, m, x, zeroCount-1);
      } else {
        if (x[i-1] - x[i+1] == 2){
          x[i] = (x[i-1] + x[i+1])/2;
          ways += 1;
        } else if (x[i-1] - x[i+1] == 1){
          ways += 2;
        } else if (x[i-1] - x[i+1] == 0){
          ways += 3;
        }
      }
    }
  }
  return ways;
}

int main(void){
  setIO();
  int n, m; cin >> n >> m;
  vector<int> x(n);
  int zeroCount = 0;
  for (int i = 0; i < n; i++){
    cin >> x[i];
    if (x[i] == 0) zeroCount++;
  }
  cout << arrayDescription(n, m, x, zeroCount) << "\n";
  return 0;
}

/*
10 3
0 0 0 0 0 0 0 0 0 0

// 8119
*/