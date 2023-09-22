//
// Created by visit on 9/22/2023.
//
#include <vector>

using namespace std;

int countWaysTopDown(int n, int k, int *dp) {
    if (n == 0) {
        return 1;
    }

    if( n < 0 ) return 0;

    if (dp[n] != 0) return dp[n];

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += countWaysTopDown(n-i, k, dp);
    }
    return dp[n] = ans;
}

int countWaysBottomUp(int n, int k) {
    vector<int> dp(n+1, 0);

    dp[0] = 1;

    for(int i = 1; i<=n; i++){
        for(int skip=1; skip<=k; skip++){
            if(i-skip>=0){
                dp[i] += dp[i-skip];
            }
        }
    }

    return dp[n];
}

int optimizedCountWays(int n, int k){
    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= k; i++) {
        dp[i] = 2*dp[i-1];
    }

    for (int i = k+1; i<=n; i++) {
        dp[i] = 2*dp[i-1] - dp[i-1-k];
    }

    return dp[n];
}