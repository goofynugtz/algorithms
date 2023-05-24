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

void f(int index, vector<int>& arr, vector<int>& ds, int s, int sum){
  if (index == arr.size()){
    if (s == sum){
      for (auto it: ds) cout << it << " ";
      cout << "\n";
    }
    return;
  }
  ds.push_back(arr[index]);
  s += arr[index];
  f(index+1, arr, ds, s, sum);
  s -= arr[index];
  ds.pop_back();
  f(index+1, arr, ds, s, sum);
}

int main(){
  setIO();
  vector<int> arr = {2,3,5,7};
  vector<int> ds;
  int s = 0;
  int sum = 5;
  f(0, arr, ds, s, sum);
  return 0;
}