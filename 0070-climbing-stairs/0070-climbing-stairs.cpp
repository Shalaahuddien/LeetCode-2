class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2;j++){
                if(j>i)
                    continue;
                else{
                    dp[i]=dp[i]+dp[i-j];
                }
            }
        }
        return dp[n];
    }
};