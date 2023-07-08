#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculatePower(const vector<int>& villagers, int start, int end) {
    int power = 0;
    for (int i = start + 1; i <= end; i++) {
        power += abs(villagers[i - 1] - villagers[i]);
    }
    return power;
}

int minimumGroupPower(const vector<int>& villagers, int k) {
    int n = villagers.size();
    vector<vector<int>> dp(k, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        dp[0][i] = calculatePower(villagers, 0, i);
    }

    for (int i = 1; i < k; i++) {
        for (int j = i; j < n; j++) {
            for (int x = i - 1; x < j; x++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][x] + calculatePower(villagers, x + 1, j));
            }
        }
    }

    return dp[k - 1][n - 1];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> villagers(n);
        for (int i = 0; i < n; i++) {
            cin >> villagers[i];
        }

        int result = minimumGroupPower(villagers, k);
        cout << result << endl;
    }

    return 0;
}
