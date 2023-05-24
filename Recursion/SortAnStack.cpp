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

void insert(stack<int>& s, int e){
  if (s.empty() || s.top() < e){
    s.push(e);
    return;
  }
  int top = s.top();
  s.pop();
  insert(s, e);
  s.push(top);
}

void sort(stack<int>& s){
  if (s.empty()) return;
  int top = s.top();
  s.pop();
  sort(s);
  insert(s, top);
}

int main(void){
  setIO();
  stack<int> s;
  s.push(5);
  s.push(1);
  s.push(0);
  s.push(6);
  s.push(2);

  sort(s);

  for (int i = 0; i < 5; i++){
    cout << s.top() << " ";
    s.pop();
  }
  cout << "\n";

  return 0;
}