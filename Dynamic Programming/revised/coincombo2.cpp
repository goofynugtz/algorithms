#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define MOD int(1e9+7)

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}
// dp[x][y]=Is it possible to make y using first x elements
int fun(vector<int> &v,int n,int sum,vector<vector<int>> &dp)
{
  // cerr<<n<<" "<<sum<<endl;
  if(sum==0)return 1;
  if(sum<0)return 0;
  if(n<0) return 0;
  if(dp[n][sum]!=-1)return dp[n][sum];
  if(v[n]<=sum)
  return dp[n][sum]=fun(v,n,sum-v[n],dp) + fun(v,n-1,sum,dp);
  return dp[n][sum]=fun(v,n-1,sum,dp);
}
int tab(vector<int> &v,int n,int sum,vector<vector<int>> &dp)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=sum;j++)
    {
      if(j==0)dp[i][j]=1;
      else
      {
        if(v[i-1]<=j)
        dp[i][j]=(dp[i][j-v[i-1]]%MOD+dp[i-1][j]%MOD)%MOD;
        else
        dp[i][j]=dp[i-1][j]%MOD;
      }
    }
  }
  return dp[n][sum];
}
// int combinations(int n, int x, vector<int>& coins){
//   vector<int> dp(x+1, 0);
//   dp[0] = 1;
//   for(auto & i:coins)
//   {
//     cout<<i<<" ";
//   }
//   cout<<endl;
//   sort(coins.begin(), coins.end());
//   for (int i = 1; i <= x; i++){
//     // vector<int> v;
//     for (int j = 0; j < coins.size(); j++){
//       if (i >= coins[j]){
//         // v.push_back(coins[j]);
//         dp[i] += dp[i-coins[j]] % MOD;        
//       }
      
//     }
//   for(auto & i:dp)
//   {
//     cout<<i<<" ";
//   }
//   cout<<endl;
//   }
//   return dp[x] % MOD;
// }

signed main(){
  int n, x; cin >> n >> x;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];
  sort(coins.begin(),coins.end());
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  int ways = tab(coins,n, x, dp);
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<=x;j++)
  //   {
  //     cerr<<dp[i][j]<<" ";
  //   }
  //   cerr<<endl;
  // }
  cout << ways << "\n";
  return 0;
}
