class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        
        int n = dungeon.length, m = dungeon[0].length; 
        
        int[][] dp = new int[n][m]; 
        
        
        for (int i = n - 1; i > -1; i--) {
            
            for (int j = m - 1; j > -1; j--) {
                
                dp[i][j] = Integer.MIN_VALUE; 
                
               if (i == n - 1 && j == m - 1) {
                   dp[i][j] = dungeon[i][j]; 
                   
               }
                
                else {
               if (i < n - 1) dp[i][j] = dungeon[i][j] + dp[i + 1][j]; 
               if (j < m - 1) dp[i][j] = Math.max(dp[i][j], dungeon[i][j] + dp[i][j + 1]); 
                }
                
                dp[i][j] = Math.min(dp[i][j], 0); 
                
            }
        }
        
        return Math.max(dp[0][0] * -1, 0) + 1; 
    }
}