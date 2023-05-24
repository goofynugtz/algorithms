// https://cses.fi/problemset/task/1145
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD int(1e9+7)
typedef long long ll;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

int lengthOfLargestIncreasingSequence(int n, vector<int>& x){
  vector<int> dp;
  for (int i = 0; i < n; i++){
    auto it = lower_bound(dp.begin(), dp.end(), x[i]);
    if (it == dp.end()){
      dp.push_back(x[i]);
    } else {
      *it = x[i];
    }
  }
  // for (auto it: dp) cout << it << " ";
  // cout << "\n";
  return dp.size();
}

int main(){
  int n; cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  
  int l = lengthOfLargestIncreasingSequence(n, x);
  cout << l << "\n";
  // lengthOfLargestIncreasingSequence();
  return 0;
}
