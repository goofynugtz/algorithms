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

void insert(vector<int>& v, int e){
  if (v.size() == 0 || v[v.size()-1] < e){
    v.push_back(e);
    return;
  }
  int temp = v[v.size()-1];
  v.pop_back();
  insert(v, e);
  v.push_back(temp);
}

void sort(vector<int>& v){
  if (v.size() == 1) return;
  int temp = v[v.size()-1];
  v.pop_back();
  sort(v);
  insert(v, temp);
}

int main(void){
  setIO();
  vector<int> v = {1, 0, 2, 5};
  sort(v);
  for (auto it: v) cout << it << " ";
  return 0;
}