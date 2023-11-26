
    public int minCostII(int[][] costs) {
        if (costs == null || costs.length == 0) {
            return 0;
        }
         
        int n = costs.length;
        int k = costs[0].length;
         
        // dp[i][j] means the min cost painting for house i, with color j
        int[][] dp = new int[n][k];
         
        // Initialization
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
        }
         
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int m = 0; m < k; m++) {
                    if (m != j) {
                        dp[i][j] = Math.min(dp[i - 1][m] + costs[i][j], dp[i][j]);
                    }
                }
            }
        }
         
        // Final state
        int minCost = Integer.MAX_VALUE;
        for (int i = 0; i < k; i++) {
            minCost = Math.min(minCost, dp[n - 1][i]);
        }
         
        return minCost;
    }

