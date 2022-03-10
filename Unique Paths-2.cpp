/*
  Unique path with obstacles
  
  1. Apply DP
  
*/
int uniquePathsWithObstacles(vector<vector<int>>&a) {
  int n = a.size();
  int m = a[0].size();

  if (a[0][0] == 1 or a[n - 1][m - 1] == 1)
    return 0;

  int dp[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    if (a[0][i] == 1) break;
    dp[0][i] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (a[i][0] == 1) break;
    dp[i][0] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] == 0) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  return dp[n - 1][m - 1];
}
