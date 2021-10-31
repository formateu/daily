function countBits(n: number): number[] {    
    let dp: number[] = new Array(n+1).fill(0);
    dp[0] = 0;
    if (n === 0) {
        return dp;
    }
    
    dp[1] = 1;
    
    for (let i = 2; i < dp.length; ++i) {
        dp[i] = dp[Math.floor(i/2)];
        dp[i] = i % 2 === 0 ? dp[i] : dp[i] + 1;
    }
    
    return dp;
};