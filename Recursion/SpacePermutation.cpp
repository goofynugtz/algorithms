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

void spacePermutation(vector<char>& s, int i, string& res){
  if (i == s.size()){
    cout << res << "\n";
    return;
  }
  string res_left = res+s[i];
  string res_right = res + " " + s[i];
  spacePermutation(s, i+1, res_left);
  spacePermutation(s, i+1, res_right);
}

int main(void){
  setIO();
  vector<char> v = {'a', 'b', 'c', 'd', 'e'};
  string s = "";
  s.push_back(v[0]);
  spacePermutation(v, 1, s);
  return 0;
}