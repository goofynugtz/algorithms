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

void insertBottomOfStack(stack<int>& s, int e){
  if (s.empty()){
    s.push(e);
    return;
  }
  int top = s.top();
  s.pop();
  insertBottomOfStack(s, e);
  s.push(top);
}

void reverseStack(stack<int>& s){
  if (s.size() == 1){
    return;
  }
  int top = s.top();
  s.pop();
  reverseStack(s);
  insertBottomOfStack(s, top);
}

int main(void){
  
  setIO();
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  reverseStack(s);

  for (int i = 0; i < 5; i++){
    cout << s.top() << " ";
    s.pop();
  }
  cout << "\n";
  
  return 0;
}