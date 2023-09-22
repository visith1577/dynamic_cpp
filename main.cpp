#include <iostream>
#include <thread>
#include <vector>

#include "headers/threads.h"
#include "headers/ladder.h"
#include "headers/jumps.h"

using namespace std;

int main() {
    int n = 10;
    int k = 3;
    int dp[1000] = {0};
    int td = countWaysTopDown(n, k, dp);
    cout<<"countWaysTopDown : "<<td<<"\n";

    int bu = countWaysBottomUp(n, k);
    cout<<"countWaysBottomUp "<<bu<<"\n";

    int ocw = optimizedCountWays(n, k);
    cout<<"OptimizedCountWays"<<ocw<<"\n";

    thread subThread(&test, 100);

    subThread.join();

    cout << "hello from main thread" << endl;

    vector<int> arr = {3, 2, 5, 3, 6, 7, 2, 9, 7, 2, 3, 4, 1, 7};
    int size = (int)arr.size();
    vector<int> ndp(size, 0);

    int jmp = maxJumps(arr, size, ndp, 0);
    cout << "max jumps: "<< jmp << endl;
    return 0;
}
