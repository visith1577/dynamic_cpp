#include <iostream>
#include "headers/ladder.h"

using namespace std;

int main() {
    int n = 10;
    int k = 3;
    int dp[1000] = {0};
    int td = countWaysTopDown(n, k, dp);
    cout<<"countWaysTopDown : "<<td<<"\n";

    int bu = countWaysBottomUp(n, k);
    cout<<"countWaysTopDown : "<<bu<<"\n";

    int ocw = optimizedCountWays(n, k);
    cout<<"countWaysTopDown : "<<ocw<<"\n";
    return 0;
}
