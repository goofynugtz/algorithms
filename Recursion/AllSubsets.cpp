#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

void printSubsets(vector<int>& v, int i, vector<int>& ans){
  if (i == v.size()){
    for (auto it: ans) cout << it << " ";
    cout << "\n";
    return;
  }
  ans.push_back(v[i]);
  printSubsets(v, i+1, ans);
  ans.pop_back();
  printSubsets(v, i+1, ans);
}

void printUniqueSubsets(vector<char>& v, int i, string& ans, map<string, bool>& m){
  if (i == v.size()){
    if (m[ans] == 0)
      cout << ans << "\n";
    m[ans] = true;
    return;
  }
  ans.push_back(v[i]);
  printUniqueSubsets(v, i+1, ans, m);
  ans.pop_back();
  printUniqueSubsets(v, i+1, ans, m);
}

int main(void){
  setIO();
  // vector<int> v = {2,5,6,7};
  vector<char> v = {'a','a','c'};
  // vector<int> ans;
  string ans;
  map<string, bool> m;
  // printSubsets(v, 0, ans);
  printUniqueSubsets(v, 0, ans, m);
  return 0;
}