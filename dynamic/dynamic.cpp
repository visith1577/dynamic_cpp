//
// Created by visit on 9/24/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> arr) {
    int n = (int) arr.size();
    vector<int> dp(n, 1);

    int len = 1;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                len = max(dp[i], len);
            }
        }
    }

    return len;
}

bool canPlace(vector<int> b1, vector<int> b2) {
    if (b1[0] > b2[0] and b1[1] > b2[1] and b1[2] > b2[2]) {
        return true;
    }
    return false;
}

int bsa(vector<vector<int>> boxes) {
    sort(boxes.begin(), boxes.end(), [](vector<int> b1, vector<int> b2) -> bool {
        return b1[2] < b2[2];
    });

    int n = boxes.size();

    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        dp[i] = boxes[i][2];
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (canPlace(boxes[j], boxes[i])) {
                int current_height = boxes[j][2];

                if (dp[j] + current_height > dp[i]) {
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }

    int max_height = 0;
    for (int val: dp) {
        max_height = max(max_height, val);
    }

    return max_height;
}