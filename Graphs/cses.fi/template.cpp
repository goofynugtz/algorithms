// https://cses.fi/problemset/task/1194
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v){
  for (auto it:v) out << it << " "; return out;
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& v){
  for (auto it:v) out << it << " "; return out;
}
template <typename T, typename S>
ostream& operator<<(ostream& out, const map<T, S>& v){
  for (auto it:v) out << it.ff << ": " << it.ss << "\n"; return out;
}
void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
  #endif
}

int main(void){

  vector<int> v = {5,6,45,456456,1,2,3,7,89};
  vector<vector<int>> v2 = {{12,45,56,785}, {1,44454,5,75}, {1,5,5,5}};
  cout << v <<"\n";
  cout << v2;
  return 0;
}