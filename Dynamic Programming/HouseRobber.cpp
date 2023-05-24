#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define INF (int)1e5
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ff first
#define ss second
#define ll long long
using namespace std;

void setIO(){
  fast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}

class Solution {
  int solve(vector<int>& nums, int n, vector<int>& DP){
    if (DP[n] != -1) return DP[n];
    if (n == 0) return DP[n] = nums[n];
    if (n == 1) return DP[n] = (nums[1] > nums[0]) ? nums[1] : nums[0];
    if (n == 2) return DP[n] = (nums[2]+nums[0] > nums[1]) ? nums[2]+nums[0] : nums[1];
    int moneyRobbed = 0;
    if (n > 2){
      moneyRobbed += nums[n];
      int _temp1 = 0, _temp2 = 0; 
      if (n-2 >= 0) _temp1 += solve(nums, n-2, DP);
      if (n-3 >= 0) _temp2 += solve(nums, n-3, DP);
      moneyRobbed += max(_temp1, _temp2);
    }
    return DP[n] = moneyRobbed;
  }

public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return nums[1] > nums[0] ? nums[1] : nums[0];
    if (nums.size() == 2) return (nums[2]+nums[0] > nums[1]) ? nums[2]+nums[0] : nums[1];
    vector<int> DP(nums.size()+1, -1);
    // cout << "Size: " << nums.size() << "\n";
    int _temp1 = solve(nums, nums.size()-1, DP);
    int _temp2 = solve(nums, nums.size()-2, DP);
    return max(_temp1, _temp2);
  }
};

int main(void){
  setIO();
  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution s;
    cout << s.rob(nums) << "\n";
  }
  return 0;
}