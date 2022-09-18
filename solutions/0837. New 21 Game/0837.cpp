class Solution {
 public:
  double new21Game(int n, int k, int maxPts) {
    // when the game ends, the point is in [k..k - 1 + maxPts]
    //   P = 1, if n >= k - 1 + maxPts
    //   P = 0, if n < k (note the constraints already have k <= n)
    if (k == 0 || n >= k - 1 + maxPts)
      return 1.0;

    double ans = 0.0;
    vector<double> dp(n + 1);  // dp[i] := prob to have i points
    dp[0] = 1.0;
    double windowSum = dp[0];  // P(i - 1) + P(i - 2) + ... + P(i - maxPts)

    for (int i = 1; i <= n; ++i) {
      // the prob to get point i is
      // P(i) = [P(i - 1) + P(i - 2) + ... + P(i - maxPts)] / maxPts
      dp[i] = windowSum / maxPts;
      if (i < k)
        windowSum += dp[i];
      else  // the game ends
        ans += dp[i];
      if (i - maxPts >= 0)
        windowSum -= dp[i - maxPts];
    }

    return ans;
  }
};
