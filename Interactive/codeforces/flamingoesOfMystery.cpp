#include <iostream>
using namespace std;
 
const int MAXN = 1000;
int n, ans[MAXN+5];
 
int ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    int ret; cin >> ret;
    return ret;
}
 
void answer(){
    cout << "!";
    for(int i = 1;i <= n;i++) cout << " " << ans[i];
    cout << endl;
}
 
int main(){
    cin >> n;
    ans[n] = ask(1, n);
    ans[1] = ans[n]-ask(2, n);
    for(int i = 2;i <= n-1;i++) ans[i] = ask(i-1, i)-ans[i-1];
    for(int i = 1;i < n;i++) ans[n] -= ans[i];
    answer();
}