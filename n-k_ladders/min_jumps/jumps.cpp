//
// Created by visit on 9/23/2023.
//

#include <vector>
#include <climits>

using namespace std;

int maxJumps(vector<int> arr, int n, vector<int> dp, int i = 0) {
    if(i == n-1) return 0;
    if(i >= n) return INT_MAX;

    if(dp[i] != 0) return i;

    int steps = INT_MAX;
    int max_jump = arr[i];

    for(int jump = 1; jump<=max_jump; jump++) {
        int next_cell = i + jump;
        int subProb = maxJumps(arr, n, dp, next_cell);
        if(subProb != INT_MAX){
            steps = min(steps, subProb+1);
        }
    }

    return dp[i] = steps;
}