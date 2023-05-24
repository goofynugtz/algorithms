#include <bits/stdc++.h>
#define INF (int)1e15
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

class Solution {
public:
  int bfs(vector<int>& board, int n){
    // for (auto it: board) cout << it << " "; cout << "\n";
    vector<int> visited(n*n+1, 0);
    // for (auto it: visited) cout << it << " "; cout << "\n";
    queue<pair<int,int>> q;
    int ans = INT_MAX;
    q.push({1,0});
    visited[1] = 1;
    while (!q.empty()){
      int node = q.front().first;
      int distance = q.front().second;
      // cout << node << " " << distance << "\n";
      q.pop();
      if (node == (n*n)){
        ans = min(distance, ans);
        break;
      }
      for (int i = 1; i <= 6 && node+i <= (n*n); i++){
        // cout << "check curr @" << board[node+i] << "\n";
        if (board[node+i] != -1){
          if (!visited[board[node+i]]){
            visited[board[node+i]] = 1;
            q.push({board[node+i], distance+1});
          // cout << "Pushed " << board[node+i] << "\n";
          } else continue;
        } else {
          if (!visited[node+i]){
            visited[node+i] = 1;
            q.push({node+i, distance+1});
          // cout << "Pushed " << node+i << "\n";
          }
        }
        
      }
    }
    return ans;
  }
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> oneBoard((n*n)+1);
    int o = 1, x = 0;
    for (int i = n-1; i >= 0; i--){
      if (x % 2 == 0)
        for (int j = 0; j < n; j++) oneBoard[o++] = board[i][j];
      else 
        for (int j = n-1; j >= 0; j--) oneBoard[o++] = board[i][j];
      x++;
    }
    int minDistance = bfs(oneBoard, n);
    return minDistance == INT_MAX ? -1 : minDistance;
  }
};

int main(void){
  Solution s;
  vector<vector<int>> board = {{1,1,-1},{1,1,1},{-1,1,1}};
  cout << s.snakesAndLadders(board) << "\n";


  return 0;
}