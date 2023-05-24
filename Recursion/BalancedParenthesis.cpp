#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

void balancedParenthesis(string s, int open, int close){
  if (open == 0 && close == 0){
    cout << s << "\n";
    return;
  }
  if (open == close){
    s.push_back('(');
    balancedParenthesis(s, open-1, close);
  }
  if (open != 0 && close > open){
    s.push_back('(');
    balancedParenthesis(s, open-1, close);
    s.pop_back();
    s.push_back(')');
    balancedParenthesis(s, open, close-1);
  }
  if (open == 0 && close != 0){
    s.push_back(')');
    balancedParenthesis(s, open, close-1);
  }
}

int main(void){
  setIO();
  int n = 3;
  string s = "";
  balancedParenthesis(s, n, n);
  return 0;
}